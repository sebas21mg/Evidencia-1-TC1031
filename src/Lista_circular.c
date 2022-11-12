#include <stdio.h>  // Librería de entrada y salida de datos
#include <stdlib.h> // Librería para el manejo de memoria
#include <time.h>   // Librería para tener números random

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

// Lee un número y valida que esté en un rango (de inicio a fin)
void leerNumero (int *eleccion, int inicio, int fin)
{
    scanf("%d", eleccion);
    while (*eleccion < inicio || *eleccion > fin)
    {
        printf("Elección inválida. Vuelve a intentar: ");
        scanf("%d", eleccion);
    }
}

// Obtiene un número random que esté entre los números inicio y fin
int numeroRandom(int inicio, int fin)
{
    return rand() % (fin - inicio + 1) + inicio;
}

// Verifica si la lista está vacía
int listaVacia(void)
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}

// Imprime si la lista está vacía o no
void imprimirListaVacia(void)
{
    int lista_vacia = listaVacia();
    if (lista_vacia == 1)
        printf("La lista está vacía\n");
    else 
        printf("La lista no está vacía\n");
}

// Devuelve la longitud de la lista (cantidad de nodos)
int cantidadNodos(void)
{
    if (listaVacia() == 1)
        return 0;

    struct nodo *temporal;
    int longitud = 0;
    temporal = inicio;
    do
    {
        longitud++;
        temporal = temporal->siguiente;
    } while (temporal != inicio);
    return longitud;
}

// Imprime la cantidad de nodos que tiene la lista
void imprimirCantidadNodos (void)
{
    int longitud = cantidadNodos();
    if (longitud == 0)
        printf("No existen nodos en la lista\n");
    else
        printf("Existen %d nodos en la lista circular\n", cantidadNodos());
}

// Inserta un elemento en la lista. Dependiendo de la variable 'cantidad_insertar' 
// se va a insertar un nodo ('1') o varios (otro número) y dependiendo de 'lugar' 
// lo hace al final ('1') o al principio de la lista (otro número)
void insertarNodos(int numero, int cantidad_insertar, int lugar)
{
    int i;
    for (i = 0; i < cantidad_insertar; i++)
    {
        if (lugar == 1)
            printf("Nuevo elemento en el final de la lista: %d\n", numero);
        else
            printf("Nuevo elemento en el inicio de la lista: %d\n", numero);
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
            elemento->valor = numero;
            elemento->anterior = fin;
            elemento->siguiente = inicio;
            fin->siguiente = elemento;
            inicio->anterior = elemento;

            if (lugar == 1)
                fin = elemento;
            else
                inicio = elemento;
        }
    }
}

// Inserta uno o varios nodos en la lista, todo se lo pide al usuario
void insertarNodosUsuario(void)
{
    int i, cantidad_insertar;
    printf("Cantidad de elementos a insertar: ");
    scanf("%d", &cantidad_insertar);

    for (i = 0; i < cantidad_insertar; i++)
    {
        int lugar, numero;
        printf("\nInsertar al\n[1] Final\n[2] Inicio\nElegir: ");
        leerNumero (&lugar, 1, 2);
        printf("Ingresa el número: ");
        scanf("%d", &numero);
        insertarNodos(numero, 1, lugar);
    }
    printf("\n");
}

// Elimina elementos iguales al parámetro 'numero' de la lista. Dependiendo de eliminar_uno
// elimina un elemento ('1') o elimina todos (otro númeo)
void eliminarNodos(int numero, int eliminar_uno)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo *indice = inicio;
    int repetir = 1;
    while (indice != inicio || repetir == 1)
    {
        repetir = 0;
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
                {
                    inicio = indice->siguiente;
                    repetir = 1;
                }
                if (indice == fin)
                    fin = indice->anterior;

                struct nodo *temporal = indice;
                indice = indice->siguiente;
                free(temporal);
                if (eliminar_uno == 1)
                    return;
            }
        }
        else
            indice = indice->siguiente;
    }
    if (eliminar_uno == 1)
        printf("Elemento %d no se puede eliminar\n", numero);
}

// Elimina uno o varios nodos en la lista, todo se lo pide al usuario
void eliminarNodosUsuario(void)
{
    int eliminar_uno, numero;
    printf("Ingresa el número: ");
    scanf("%d", &numero);
    printf("\nEliminar el número\n[1] Una vez\n[2] Todas las veces que aparece\nElegir: ");
    leerNumero (&eliminar_uno, 1, 2);
    eliminarNodos(numero, eliminar_uno);
}

// Elimina todos los elementos de la lista
void eliminarLista(void)
{
    struct nodo *indice = inicio;
    struct nodo *temporal;
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

// Imprime todos los elementos de una lista. Dependiendo del parámetro 'lugar' 
// se hace de inicio a fin ('1') o viceversa (otro número)
void imprimirLista(int lugar)
{
    if (listaVacia() == 1)
    {
        printf("\nNo existen elementos a mostrar\n");
        return;
    }
    int i;
    struct nodo *temporal;
    printf("\nElementos en la lista:\n");

    if (lugar == 1)
    {
        temporal = inicio;
        int longitud = cantidadNodos();
        for (i = 0; i < longitud; i++)
        {
            printf("Elemento [%d] = %d\n", i, temporal->valor);
            temporal = temporal->siguiente;
        }
    }
    else
    {
        temporal = fin;
        for (i = cantidadNodos(); i > 0; i--)
        {
            printf("Elemento [%d] = %d\n", i - 1, temporal->valor);
            temporal = temporal->anterior;
        }
    }

    printf("\n");
}

// Imprime la lista. El orden se le pide al usuario
void imprimirListaUsuario (void)
{
    int lugar;
    printf("\n[1] De inicio a fin\n[2] De fin a inicio\nElegir: ");
    leerNumero (&lugar, 1, 2);
    imprimirLista(lugar);
}

// Busca la posición de un número en la lista
void buscarNodo(int numero)
{
    if (listaVacia() == 1)
    {
        printf("La lista está vacía\n");
        return;
    }
    struct nodo *indice = inicio;
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

// Pide el número del nodo a buscar
void pedirBuscarNodo(void)
{
    printf("Introduce el elemento que quieres buscar: ");
    int numero;
    scanf("%d", &numero);
    buscarNodo(numero);
}

// Ejecuta un programa de prueba ya predeterminado (el usuario no introduce nada)
void ejecucionPredeterminada(void)
{
    printf("\n- Operaciones para insertar valores\n\n");

    insertarNodos(numeroRandom(1, 100), 1, 1);
    insertarNodos(numeroRandom(1, 100), 1, 0);
    imprimirLista(1);

    int rand = numeroRandom(1, 100);

    insertarNodos(numeroRandom(1, 100), numeroRandom(3, 5), 1);
    insertarNodos(rand, numeroRandom(3, 5), 2);
    imprimirLista(1);

    printf("\n- Cantidad de nodos\n\n");
    imprimirCantidadNodos ();

    printf("\n- Buscar nodos\n\n");
    buscarNodo(rand);

    printf("\n- Operaciones de eliminar\n\n");
    printf("Intentar eliminar un número aleatorio (ver cuando no está el número a eliminar):\n");
    eliminarNodos(numeroRandom(1, 100), 1);
    printf("\nEliminar sólo un elemento %d:\n", rand);
    eliminarNodos(rand, 1);
    imprimirLista(0);
    printf("Eliminar todos los elementos %d:\n", rand);
    eliminarNodos(rand, 0);
    imprimirLista(0);
    printf("Eliminar toda la lista:\n");
    eliminarLista();
    imprimirLista(0);
}

// Ejecuta un programa en el que el usuario toma todas las decisiones
void ejecucionUsuario(void)
{
    system("cls");

    int eleccion = 0;
    do
    {
        printf("\n----------------------------\n");
        printf("MENÚ DEL PROGRAMA DE USUARIO\n\n");
        printf("[1] Añadir uno o varios elementos\n");
        printf("[2] Eliminar uno o varios elementos\n");
        printf("[3] Eliminar la lista\n");
        printf("[4] Buscar un nodo\n");
        printf("[5] Saber si la lista está vacía\n");
        printf("[6] Saber la cantidad de nodos de la lista\n");
        printf("[7] Mostrar la lista\n");
        printf("[0] Salir (se eliminará la lista)\n\nElegir: ");
        leerNumero (&eleccion, 0, 7);

        switch (eleccion)
        {
        case 1:
            insertarNodosUsuario();
            break;
        case 2:
            eliminarNodosUsuario();
            break;
        case 3:
            eliminarLista();
            break;
        case 4:
            pedirBuscarNodo();
            break;
        case 5:
            imprimirListaVacia();
            break;
        case 6:
            imprimirCantidadNodos ();
            break;
        case 7:
            imprimirListaUsuario();
            break;
        }

    } while (eleccion != 0);
    eliminarLista();
}

// Main --------------------------------------------------------------------------------------------
void main(void)
{
    srand(time(NULL));

    int eleccion = 0;
    do
    {
        printf("MENÚ\n\n");
        printf("[1] Ejecutar programa predeterminado\n");
        printf("[2] Ejecutar programa de usuario\n");
        printf("[0] Salir\n\nElección: ");
        leerNumero (&eleccion, 0, 2);

        switch (eleccion)
        {
        case 1:
            ejecucionPredeterminada();
            break;
        case 2:
            ejecucionUsuario();
            break;
        }

        if (eleccion != 0)
        {
            system("pause");
            system("cls");
        }
    } while (eleccion != 0);
    eliminarLista();
}