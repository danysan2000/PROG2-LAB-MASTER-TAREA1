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
    printf("%d/%d/%d\n",fecha->dia,fecha->mes,fecha->anio);   

}

TFecha copiarTFecha(TFecha fecha) 
{
    TFecha fecha_new = new rep_fecha;
    *fecha_new = *fecha;
    return fecha_new ;
}

/************ Parte 3.9 ************/

/*Recuerde que las funciones auxiliares deben declararse antes de ser utilizadas*/

// Función para obtener la cantidad de días de un mes en un año dado
static nat diasMes(nat mes, nat anio)
{
            //   enero,febrero,marzo,abril,mayo,junio,julio,agosto,septiembre,octubre,noviembre,diciembre 
            //   31,      28,    31,   30,   31,  30,  31,    31,     30,      31,      30,       31
/*  Enero: 31 días
    Febrero: 28 días (29 en años bisiestos)
    Marzo: 31 días
    Abril: 30 días
    Mayo: 31 días
    Junio: 30 días
    Julio: 31 días
    Agosto: 31 días
    Septiembre: 30 días
    Octubre: 31 días
    Noviembre: 30 días
    Diciembre: 31 días
*/
    nat diames[12] = {31,0,31,30,31,30,31,31,30,31,30,31 };
    diames[1] = ( (anio % 4 == 0) && ((anio % 100 != 0) || (anio % 400 == 0)) ) ? 29 : 28 ;
    return diames[mes - 1];
}

void aumentarTFecha(TFecha &fecha, nat dias) 
{
    fecha->dia += dias;
    while (  fecha->dia > diasMes(fecha->mes,fecha->anio)  )
    {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }
    }

}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) 
{
    int res = 0;
    int fecha_aux1, fecha_aux2;

    fecha_aux1 =   fecha1->anio * 10000 + fecha1->mes * 100 + fecha1->dia;
    fecha_aux2 =   fecha2->anio * 10000 + fecha2->mes * 100 + fecha2->dia;
    
    res = ( fecha_aux1 == fecha_aux2) ? 0 : ( fecha_aux1 > fecha_aux2 ) ? 1 : -1 ;
    return res;
}
