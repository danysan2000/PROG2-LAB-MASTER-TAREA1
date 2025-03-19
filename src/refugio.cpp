#include "../include/refugio.h"


static int buscarPosicion(TPerro  vp[], int tope_aux, TPerro p);
static void insertarOrdenado(TPerro vp[], int *tope, TPerro p );

struct rep_refugio {
    /************ Parte 5.1 ************/
    TPerro perro[MAX_PERROS];
    int tope;
};

TRefugio crearTRefugio()
{
    TRefugio  refugio = new rep_refugio;
    refugio->tope = 0; // incializo a cero el tope del array Perros.
    return refugio;
}

void liberarTRefugio(TRefugio& refugio)
{
    // para liberar refugio hay que dar de baja cada perro
    int ix;
    for(ix=0; ix < refugio->tope ; ix++)
        liberarTPerro ( refugio->perro[ix] );                  
    delete refugio;
}

void agregarEnTRefugio(TRefugio& refugio, TPerro perro)
{
    // primero chequeo que no exista el id para ingresar.
    if( estaEnTRefugio( refugio, idTPerro( perro)  ) )
        return;
    // agrego porque no existe
    insertarOrdenado( refugio->perro, &refugio->tope , perro );
}

void imprimirTRefugio(TRefugio refugio)
{
    int ix;
    int tope = refugio->tope;
    for(ix=0; ix < tope ; ix++)
       imprimirTPerro( refugio->perro[ix]); 
}

static int indice_perro = 0;

bool estaEnTRefugio(TRefugio refugio, int id)
{
    // busqueda sequencial porque el vector perros esta ordenado por fecha.
    int ix; // variable auxiliar para loops.
    int tope = refugio->tope;
    
    ix=0;
    while( ix < tope &&  idTPerro( refugio->perro[ix]) != id ) ix++;
    if( ix < tope )
    {
        indice_perro = ix; // indice me sirve para saber cual es el indice en el vector
        return true;
    }
    else
        return false;
}

TPerro obtenerDeTRefugio(TRefugio refugio, int id)
{
    TPerro perro_aux = NULL;
    
    if( estaEnTRefugio(refugio, id) )
        perro_aux = refugio->perro[indice_perro];
    return perro_aux;
}

bool ingresaronPerrosFechaTRefugio(TRefugio refugio, TFecha fecha) 
{
    // tengo que hacer la busqueda por fecha y ir al primer indice 
    //
    
    int inicio = 0;
    int fin = refugio->tope - 1;
    int comp_aux;
    int medio;

    while (inicio <= fin)
    {
        medio = inicio + (fin - inicio) / 2;
        comp_aux = compararTFechas( fechaIngresoTPerro( refugio->perro[medio] )  , fecha );
        if ( comp_aux == 0 )
        {
         // TENGO QUE PONERLO A LO ULTIMO DE LOS REPETIDOS
            // voy por el primero en la lista de repetidos.
            while( medio > -1 && compararTFechas(fechaIngresoTPerro(refugio->perro[medio]) , fecha ) == 0) medio-- ;
            indice_perro = ++medio;
            return true;  // El valor ya existe, lo inserto al final de los repetidos.
        }
        else if ( comp_aux == -1 ) 
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return false;
}


void imprimirPerrosFechaTRefugio(TRefugio refugio, TFecha fecha) 
{
       
    if ( ! ingresaronPerrosFechaTRefugio( refugio, fecha) )
        return;
    while( (indice_perro < refugio->tope) && compararTFechas(fechaIngresoTPerro(refugio->perro[indice_perro] ) , fecha ) == 0 )
        imprimirTPerro( refugio->perro[indice_perro++] );
}

void removerDeTRefugio(TRefugio& refugio, int id) 
{
    int ix;
    int tope = refugio->tope - 1;

    if( refugio->tope  && !estaEnTRefugio(refugio, id) )
       return;
    liberarTPerro( refugio->perro[indice_perro] );                  
    for (ix = indice_perro; ix < tope ; ix++)
        refugio->perro[ix] = refugio->perro[ix+1]; 
    refugio->tope--;
}

//----------------------------------------------------------
// Funciones auxiliares privadas dentro del Modulo Refugio
//

// #define MAX_SIZE 100  // Tamaño máximo del vector

static int buscarPosicion(TPerro  vec_perro[], int tope_aux, TPerro perro  )
{
    // el orden es por fecha de ingreso.
    int inicio = 0;
    int fin = tope_aux - 1;
    int comp_aux=0;
    int medio;

    while (inicio <= fin)
    {
        medio = inicio + (fin - inicio) / 2;
        comp_aux = compararTFechas( fechaIngresoTPerro(vec_perro[medio]) , fechaIngresoTPerro(perro) );
        if ( comp_aux == 0 )
        {
           // TENGO QUE PONERLO A LO ULTIMO DE LOS REPETIDOS
            while( medio < tope_aux &&  compararTFechas(fechaIngresoTPerro(vec_perro[medio]) , fechaIngresoTPerro(perro) ) == 0) medio++ ;  // voy por el ultimo lugar de los repetidos.
            return medio;  // El valor ya existe, lo inserto al final de los repetidos.
        }
        else if ( comp_aux == -1 ) 
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return inicio;  // Posición donde se debe insertar el nuevo valor
}

static void insertarOrdenado(TPerro vec_perro[], int *tope, TPerro perro )
{
    if (*tope >= MAX_PERROS)
    {
        printf("El vector está lleno, no se puede insertar más elementos.\n");
        return;
    }
    // Encontrar la posición donde insertar el valor
    int pos = buscarPosicion(vec_perro, *tope,  perro );

    // Desplazar los elementos a la derecha para hacer espacio
    for (int i = *tope; i > pos; i--)
        vec_perro[i] = vec_perro[i - 1];

    // Insertar el valor en la posición correcta
    vec_perro[pos] = perro ;
    (*tope)++;
}

