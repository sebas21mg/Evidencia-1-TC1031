#include <stdio.h> // Librería de entrada y salida de datos
#include <stdlib.h> // Librería para el manejo de memoria
#include <time.h> // Librería para tener números random

// Estructura básica del programa ------------------------------------------------------------------

// Definición de la estructura de un nodo en la lista
struct nodo
{
    int valor;
    struct nodo* siguiente;
    struct nodo* anterior;
};

// Elemento que apunta a la parte inicial de la lista
struct nodo* inicio = NULL;
// Elemento que apunta a la parte final de la lista
struct nodo* fin = NULL;

// Funciones que pide la tarea ---------------------------------------------------------------------

// Verifica si la lista está vacía
int listaVacia(void)
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}

// Devuelve la longitud de la lista
int cantidadNodos(void)
{
    if (listaVacia() == 1)
        return 0;

    struct nodo* temporal;
    int longitud = 0;
    temporal = inicio;
    while (temporal != inicio || longitud == 0)
    {
        longitud++;
        temporal = temporal->siguiente;
    }
    return longitud;
}

// Inserta un elemento al final de la lista
void insertarFinal(int numero)
{
    printf("Nuevo elemento en el final de la lista: %d\n", numero);
    struct nodo* elemento = malloc(sizeof(struct nodo));
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
        elemento->valor = numero;
        elemento->anterior = fin;
        elemento->siguiente = inicio;
        fin->siguiente = elemento;
        inicio->anterior = elemento;
        fin = elemento;
    }
}

// Inserta varios nodos consecutivos (los valores se los pide al usuario)
void insertarNodosConsecutivosFinal(int cantidad_nodos)
{
    int i;
    for (i = 0; i < cantidad_nodos; i++)
    {
        printf("Ingresa un número: ");
        int numero;
        scanf("%d", &numero);
        insertarFinal(numero);
    }
}

// Eliminar un elemento de la lista
void eliminarNodo(int numero)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo* indice = inicio;
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

// Eliminar múltiples elemento de la lista (todos los números que sean igual al
// que se le da a la función)
void eliminarMultiplesNodos(int numero)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo* indice = inicio;
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

                struct nodo* temporal = indice;
                indice = indice->siguiente;
                free(temporal);
            }
        }
        else
            indice = indice->siguiente;
    } while (indice != inicio);
}

// Elimina todos los elementos de la lista
void eliminarLista(void)
{
    struct nodo* indice = inicio;
    struct nodo* temporal = inicio;
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
void imprimirElementosListaInicio()
{
    if (listaVacia() == 1)
    {
        printf("\nNo existen elementos a mostrar\n");
        return;
    }
    int i = 0, longitud = 0;
    longitud = cantidadNodos();
    struct nodo* temporal;
    temporal = inicio;
    printf("\nElementos en la lista:\n");
    for (i = 0; i < longitud; i++)
    {
        printf("Elemento[%d] = %d\n", i, temporal->valor);
        temporal = temporal->siguiente;
    }
    printf("\n");
}

// Buscar un nodo en la lista
void buscarNodo(int numero)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo* indice = inicio;
    int i = 0;
    do
    {
        if (indice->valor == numero)
        {
            printf("El elemento %d se encuentra en el nodo [%d] de la lista\n", numero, i);
            return;
        }
        indice = indice->siguiente;
        i++;
    } while (indice != inicio);
    printf("El elemento %d no se puede encontrar\n", numero);
}

// Funciones extras --------------------------------------------------------------------------------

// Imprime la longitud de la lista
void imprimirLongitudLista(void)
{
    int longitud = cantidadNodos();
    if (longitud == 0)
    {
        printf("No existen nodos en la lista\n");
        return;
    }
    printf("Existen %d nodos en la lista circular\n", cantidadNodos());
}

// Inserta varios nodos de forma consecutiva en la lista, la diferencia con la 
// primera función es que no se le piden los valores al usuario sino que se le pasa
// un número a la función y ese va a ser el valor de todos los nodos
void insertarNodosConsecutivosIgualesFinal(int numero, int cantidad_nodos)
{
    int i;
    for (i = 0; i < cantidad_nodos; i++)
    {
        insertarFinal(numero);
    }
}

    // Funciones 'insertar' pero que ahora insertan los elementos al inicio de la lista ------------

void insertarInicio(int numero)
{
    printf("Nuevo elemento en el inicio de la lista: %d\n", numero);
    struct nodo* elemento = malloc(sizeof(struct nodo));
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
        elemento->valor = numero;
        elemento->anterior = fin;
        elemento->siguiente = inicio;
        fin->siguiente = elemento;
        inicio->anterior = elemento;
        inicio = elemento;
    }
}

void insertarNodosConsecutivosInicio(int cantidad_nodos)
{
    int i;
    for (i = 0; i < cantidad_nodos; i++)
    {
        printf("Ingresa un número: ");
        int numero;
        scanf("%d", &numero);
        insertarInicio(numero);
    }
}

void insertarNodosConsecutivosIgualesInicio(int numero, int cantidad_nodos)
{
    int i;
    for (i = 0; i < cantidad_nodos; i++)
    {
        insertarInicio(numero);
    }
}

    // ---------------------------------------------------------------------------------------------

int numeroRandom(int inicio, int fin)
{
    return rand () % (fin - inicio + 1) + inicio;   // Este está entre incio y fin
}

void pedirNumeroBuscar(void)
{
    printf("Introduce el elemento que quieres buscar: ");
    int numero;
    scanf("%d", &numero);
    buscarNodo(numero);
}

// Imprime todos los elementos de una lista desde el final
void imprimirElementosListaFinal()
{
    if (listaVacia() == 1)
    {
        printf("\nNo existen elementos a mostrar\n");
        return;
    }
    int i;
    struct nodo* temporal;
    temporal = fin;
    printf("\nElementos en la lista:\n");
    for (i = cantidadNodos(); i > 0; i--)
    {
        printf("Elemento[%d] = %d\n", i - 1, temporal->valor);
        temporal = temporal->anterior;
    }
    printf("\n");
}

// Main --------------------------------------------------------------------------------------------
void main(void)
{
    srand(time(NULL));
    printf("\n- Operaciones para insertar valores\n\n");

    insertarFinal(numeroRandom(1,100));
    insertarInicio(numeroRandom(1,100));
    imprimirElementosListaInicio();

    int rand = numeroRandom(1,100);
    insertarNodosConsecutivosIgualesFinal(rand, numeroRandom(3,5));
    insertarNodosConsecutivosIgualesInicio(numeroRandom(1,100), numeroRandom(1,5));
    imprimirElementosListaInicio();

    printf("Nuevos elementos al final:\n");
    insertarNodosConsecutivosFinal(numeroRandom(1,3));
    printf("\nNuevos elementos al inicio:\n");
    insertarNodosConsecutivosInicio(numeroRandom(1,3));
    imprimirElementosListaInicio();

    printf("\n- Cantidad de nodos\n\n");
    imprimirLongitudLista();

    printf("\n- Buscar nodos\n\n");
    pedirNumeroBuscar();

    printf("\n- Operaciones de eliminar\n\n");
    printf("Intento de eliminar un número aleatorio:\n");
    eliminarNodo(numeroRandom(1,100));
    printf("\nEliminar sólo un nodo:\n");
    eliminarNodo(rand);
    imprimirElementosListaFinal();
    printf("Eliminar todos los nodos:\n");
    eliminarMultiplesNodos(rand);
    imprimirElementosListaFinal();
    printf("Eliminar toda la lista:\n");
    eliminarLista();
    imprimirElementosListaFinal();
}