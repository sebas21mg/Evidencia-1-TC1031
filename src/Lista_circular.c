// Librería de entrada y salida de datos
#include <stdio.h>
// Librería para el manejo de memoria
#include <stdlib.h>

// Definición de la estructura de un nodo en la lista
struct nodo
{
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
};

// Elemento que apunta a la parte inicial de la lista
struct nodo *inicio = NULL;
// Elemento que apunta a la parte final de la lista
struct nodo *fin = NULL;

// Verifica si la lista está vacía
int listaVacia()
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}

// Devuelve la longitud de una lista
int longitudLista()
{
    if (listaVacia() == 1)
        return 0;

    struct nodo *temporal;
    int longitud = 0;
    temporal = inicio;
    while (temporal != inicio || longitud == 0)
    {
        longitud++;
        temporal = temporal->siguiente;
    }
    return longitud;
}

// Inserta un elemento al final de una lista
void insertaFinalLista(int numero)
{
    printf("Nuevo elemento en el final de la lista: %d\n", numero);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if (elemento == NULL)
    {
        printf("No se puede crear un elemento en la lista");
        return;
    }
    if (listaVacia() == 1)
    {
        elemento->valor = numero;
        elemento->anterior = elemento;
        elemento->siguiente = elemento;
        inicio = elemento;
        fin = elemento;
    }
    else
    {
        struct nodo *indiceAnterior = NULL;
        struct nodo *indiceActual = inicio;
        while (indiceAnterior != fin)
        {
            indiceAnterior = indiceActual;
            indiceActual = indiceActual->siguiente;
        }
        elemento->valor = numero;
        elemento->siguiente = inicio;
        indiceAnterior->siguiente = elemento;
        elemento->anterior = indiceAnterior;
        fin = elemento;
    }
}

// // Inserta un elemento al inicio de una lista
// void insertaInicioLista(int numero)
// {
//     printf("Nuevo elemento en el inicio de la lista: %d\n", numero);
//     struct nodo *elemento = malloc(sizeof(struct nodo));
//     if (elemento == NULL)
//     {
//         printf("No se puede crear un elemento en la lista");
//         return;
//     }
//     if (listaVacia() == 1)
//     {
//         elemento->valor = numero;
//         elemento->anterior = NULL;
//         elemento->siguiente = NULL;
//         inicio = elemento;
//         fin = elemento;
//     }
//     else
//     {
//         inicio->anterior = elemento;
//         elemento->valor = numero;
//         elemento->siguiente = inicio;
//         elemento->anterior = NULL;
//         inicio = elemento;
//     }
// }

// Eliminar un elemento de la lista
void eliminaElemento(int numero)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo *indiceAnterior = NULL;
    struct nodo *indiceActual = inicio;
    while (indiceAnterior != fin)
    {
        if (indiceActual->valor == numero)
        {
            // El elemento a eliminar es el único en la lista
            if (inicio == fin)
            {
                printf("Eliminando: %d\n", indiceActual->valor);
                inicio = NULL;
                fin = NULL;
                free(indiceActual);
                return;
            }
            // Hay más de un elemento en la lista
            else
            {
                printf("Eliminando: %d\n", indiceActual->valor);
                indiceActual->anterior->siguiente = indiceActual->siguiente;
                indiceActual->siguiente->anterior = indiceActual->anterior;

                if (indiceActual == inicio)
                    inicio = indiceActual->siguiente;
                if (indiceActual == fin)
                    fin = indiceActual->anterior;

                free(indiceActual);
                return;
            }
        }
        indiceAnterior = indiceActual;
        indiceActual = indiceActual->siguiente;
    }
    printf("Elemento %d no se puede eliminar\n", numero);
}

// Imprime todos los elementos de una lista desde el inicio
void mostrarElementosListaInicio()
{
    if (listaVacia() == 1)
    {
        printf("No existen elementos a mostrar\n");
        return;
    }
    int i = 0, longitud = 0;
    longitud = longitudLista();
    struct nodo *temporal;
    temporal = inicio;
    printf("Elementos en la lista:\n");
    for (i = 0; i < longitud; i++)
    {
        printf("Elemento[%d] = %d\n", i, temporal->valor);
        temporal = temporal->siguiente;
    }
}

// // Imprime todos los elementos de una lista desde el fin
// void mostrarElementosListaFin()
// {
//     int i = longitudLista();
//     struct nodo *temporal;
//     temporal = fin;
//     printf("Elementos en la lista:\n");
//     while (temporal != NULL)
//     {
//         printf("Elemento[%d] = %d\n", i - 1, temporal->valor);
//         temporal = temporal->anterior;
//         i--;
//     }
// }

// Main
void main()
{
    printf("%d\n", longitudLista());
    eliminaElemento(1);
    insertaFinalLista(7);
    eliminaElemento(7);
    mostrarElementosListaInicio();
    printf("%d\n", longitudLista());
    insertaFinalLista(2);
    printf("%d\n", longitudLista());
    insertaFinalLista(6);
    insertaFinalLista(9);
    printf("%d\n", longitudLista());
    mostrarElementosListaInicio();
    eliminaElemento(1);
    eliminaElemento(9);
    eliminaElemento(2);
    mostrarElementosListaInicio();
    insertaFinalLista(8);
    mostrarElementosListaInicio();
    printf("Prueba de github");
}