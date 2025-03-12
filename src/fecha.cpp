#include "../include/fecha.h"

struct rep_fecha 
{
    nat     anio, mes, dia;
};

TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    // TFecha nuevaFecha = NULL;
    TFecha nuevaFecha = new rep_fecha;

    // formato fecha Japonesa.
    *nuevaFecha = { anio, mes , dia } ;  // probar 

    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) 
{
    delete fecha;
    fecha = NULL;
}

void imprimirTFecha(TFecha fecha) 
{
    

}

TFecha copiarTFecha(TFecha fecha) 
{
    return NULL;
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/


void aumentarTFecha(TFecha &fecha, nat dias) 
{

}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) 
{
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */


    /****** Fin de parte Parte 3.10 *****/
    return res;
}
