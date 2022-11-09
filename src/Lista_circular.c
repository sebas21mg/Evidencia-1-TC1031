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
        struct nodo *indice = fin;
        elemento->valor = numero;
        elemento->siguiente = inicio;
        indice->siguiente = elemento;
        elemento->anterior = indice;
        fin = elemento;
    }
}

void insertarNodosConsecutivos(int cantidad_nodos)
{
    int i;
    for (i = 0; i < cantidad_nodos; i++)
    {
        printf("Ingresa un número: ");
        int numero;
        scanf("%d", &numero);
        insertaFinalLista(numero);
    }
}

void insertarNodosConsecutivosIguales(int numero, int cantidad_nodos)
{
    int i;
    for (i = 0; i < cantidad_nodos; i++)
    {
        insertaFinalLista(numero);
    }
}

// Eliminar un elemento de la lista
void eliminaElemento(int numero)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo *indice = inicio;
    do
    {
        if (indice->valor == numero)
        {
            // El elemento a eliminar es el único en la lista
            if (inicio == fin)
            {
                printf("Eliminando: %d\n", indice->valor);
                inicio = NULL;
                fin = NULL;
                free(indice);
                return;
            }
            // Hay más de un elemento en la lista
            else
            {
                printf("Eliminando: %d\n", indice->valor);
                indice->anterior->siguiente = indice->siguiente;
                indice->siguiente->anterior = indice->anterior;

                if (indice == inicio)
                    inicio = indice->siguiente;
                if (indice == fin)
                    fin = indice->anterior;

                free(indice);
                return;
            }
        }
        indice = indice->siguiente;
    } while (indice != inicio);
    printf("Elemento %d no se puede eliminar\n", numero);
}

// Eliminar múltiples elemento de la lista (todos los números que sean igual al que se ingresa)
void eliminaMultiplesElementos(int numero)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo *indice = inicio;
    do
    {
        if (indice->valor == numero)
        {
            // El elemento a eliminar es el único en la lista
            if (inicio == fin)
            {
                printf("Eliminando: %d\n", indice->valor);
                inicio = NULL;
                fin = NULL;
                free(indice);
                return;
            }
            // Hay más de un elemento en la lista
            else
            {
                printf("Eliminando: %d\n", indice->valor);
                indice->anterior->siguiente = indice->siguiente;
                indice->siguiente->anterior = indice->anterior;

                if (indice == inicio)
                    inicio = indice->siguiente;
                if (indice == fin)
                    fin = indice->anterior;

                struct nodo *temporal = indice;
                indice = indice->siguiente;
                free(temporal);
            }
        }
        else
            indice = indice->siguiente;
    } while (indice != inicio);
}

// Elimina todos los elementos de la lista
void eliminaLista(void)
{
    struct nodo *indice = inicio;
    struct nodo *temporal = inicio;
    while (listaVacia() != 1)
    {
        // El elemento a eliminar es el único en la lista
        if (inicio == fin)
        {
            printf("Eliminando: %d\n", indice->valor);
            inicio = NULL;
            fin = NULL;
            free(indice);
            return;
        }
        // Hay más de un elemento en la lista
        else
        {
            printf("Eliminando: %d\n", indice->valor);
            indice->anterior->siguiente = indice->siguiente;
            indice->siguiente->anterior = indice->anterior;
            inicio = indice->siguiente;
            temporal = indice;
            indice = indice->siguiente;
            free(temporal);
        }
    }
    return;
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

// Imprime la longitud de la lista
void printLongitudLista()
{
    int longitud = longitudLista();
    if (longitud == 0)
    {
        printf("No existen nodos en la lista\n");
        return;
    }
    printf("Existen %d nodos en la lista circular\n", longitudLista());
}

// Main
void main()
{
    printLongitudLista();
    eliminaElemento(1);
    insertaFinalLista(7);
    eliminaElemento(7);
    mostrarElementosListaInicio();
    printLongitudLista();
    insertaFinalLista(2);
    printLongitudLista();
    insertaFinalLista(6);
    insertaFinalLista(9);
    printLongitudLista();
    mostrarElementosListaInicio();
    eliminaElemento(1);
    eliminaElemento(9);
    eliminaElemento(2);
    mostrarElementosListaInicio();
    insertaFinalLista(8);
    mostrarElementosListaInicio();
    printf("\n\n\nInsertar varios elementos\n");
    insertarNodosConsecutivosIguales(5, 3);
    mostrarElementosListaInicio();
    printf("\n\n\nEliminar varios elementos\n");
    eliminaMultiplesElementos(5);
    mostrarElementosListaInicio();
    printf("\n\n\nEliminar la lista\n");
    eliminaLista();
    mostrarElementosListaInicio();
}