#include <stdio.h>

#define MAX_SIZE 100  // Tamaño máximo del vector

static int buscarPosicion(int vector[][2], int n, int valor)
{
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        if (vector[medio][0] == valor)
        {
            while( vector[++medio][0] == valor );
            return medio;  // El valor ya existe, lo insertamos aquí
        }
        else if (vector[medio][0] < valor)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }
    return inicio;  // Posición donde se debe insertar el nuevo valor
}

static void insertarOrdenado(int vector[][2], int *n, int valor1, int valor2)
{
    // se ordena por valor1
    printf("n=%d valor1=%d  valor2=%d\n",*n, valor1,valor2);
    if (*n >= MAX_SIZE)
    {
        printf("El vector está lleno, no se puede insertar más elementos.\n");
        return;
    }
    // Encontrar la posición donde insertar el valor
    int pos = buscarPosicion(vector, *n, valor1);

    // Desplazar los elementos a la derecha para hacer espacio
    for (int i = *n; i > pos; i--)
    {
        vector[i][0] = vector[i - 1][0];
        vector[i][1] = vector[i - 1][1];
    }

    // Insertar el valor en la posición correcta
    vector[pos][0] = valor1;
    vector[pos][1] = valor2;
    (*n)++;
}


int main()
{
    int vector[MAX_SIZE][2];
    int n = 0;  // Número actual de elementos en el vector

    printf("Vector 5,3,8,1\n");
    // Insertar valores en el vector
    insertarOrdenado(vector, &n, 5,5 );
    insertarOrdenado(vector, &n, 3,2);
    insertarOrdenado(vector, &n, 8, 3);
    insertarOrdenado(vector, &n, 1, 4);
    insertarOrdenado(vector, &n, 5, 1 );

    // Imprimir el vector ordenado
    printf("\nVector ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("i=%d valor1=%d  valor2=%d\n",i, vector[i][0],vector[i][1]);
    }
//    printf("\n");
    return 0;
}


