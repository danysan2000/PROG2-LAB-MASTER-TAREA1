#include "../include/perro.h"

/*
Esta estructura debe contener un identificador
de tipo entero,
 un nombre de tipo texto,
 una edad de tipo natural (nat),
 un indicador de vitalidad de tipo natural,
 una descripción de tipo texto
 una fecha de ingreso de tipo TFecha.
 Para el nombre utilizaremos un arreglo de caracteres (char) de tamaño MAX_NOMBRE y
 para la descripción utilizaremos un arreglo de caracteres (char) de tamaño MAX_DESCRIPCION.

*/



struct rep_perro {
    /************ Parte 4.1 ************/
    int     id;
    char    nombre[MAX_NOMBRE];
    nat     id_vital;
    char    descr[MAX_DESCRIPCION];
    TFecha  fecha_ing;

};

TPerro crearTPerro(int id, const char nombre[MAX_NOMBRE], nat edad, nat vitalidad, const char descripcion[MAX_DESCRIPCION], TFecha fechaIngreso) {
    return NULL; 
}

void liberarTPerro(TPerro &perro) {

}

int idTPerro(TPerro perro) {
    return 0; 
}

char* nombreTPerro(TPerro perro) {
    return NULL; 
}

nat edadTPerro(TPerro perro) {
    return 0;
}

nat vitalidadTPerro(TPerro perro) {
    return 0; 
}

char* descripcionTPerro(TPerro perro) {
    return NULL; 
}

TFecha fechaIngresoTPerro(TPerro perro) {
    return NULL; 
}

void imprimirTPerro(TPerro perro) {

}

TPerro copiarTPerro(TPerro perro) {
    return NULL;
}

void actualizarEdadTPerro(TPerro &perro, nat nuevaEdad) {

}

void actualizarVitalidadTPerro(TPerro &perro, nat nuevaVitalidad) {

}
