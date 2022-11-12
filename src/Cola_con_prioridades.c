#include <stdio.h>
#include <stdlib.h>

struct queue {
    int valor;
    int weight;
    struct queue *siguiente;
};

struct queue *tope = NULL;

int queueVacio_6() {
    if(tope == NULL)
        return 1;
    else
        return 0;
}
void imprimir() {
    if (queueVacio_6()) {
        printf("La cola esta vacia");
        return;
    }
    struct queue *aux = tope;
    printf("La lista contiene los siguientes elementos: \n");
    while (aux != NULL) {
        printf("%d con peso %d \n", aux->valor, aux->weight);
        aux = aux->siguiente;
    }
}
void eliminar_4() {
    struct queue *aux;
    while (tope != NULL) {
        aux = tope;
        tope = tope->siguiente;
        free(aux);
    }
}
void agregar_1(int valor, int weight) {
    struct queue *nuevo = malloc(sizeof(struct queue));
    if (nuevo == NULL)
        printf("No hay memoria disponible");
    nuevo->valor = valor;
    nuevo->weight = weight;
    nuevo->siguiente = NULL;
    if (queueVacio_6())
        tope = nuevo;
    else {
        if(weight >= tope->weight) {
            nuevo->siguiente = tope;
            tope = nuevo;
        }
        else {
            struct queue *aux = tope;
            while (aux->siguiente != NULL && weight < aux->siguiente->weight)
                aux = aux->siguiente;
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
    printf("Metiendo el numero %d con peso %d \n", valor, weight);
}
void agregar_2(int valor, int weight, int cantidad) {
    while(cantidad > 0) {
        struct queue *nuevo = malloc(sizeof(struct queue));
        if (nuevo == NULL)
            printf("No hay memoria disponible");
        nuevo->valor = valor;
        nuevo->weight = weight;
        nuevo->siguiente = NULL;
        if (queueVacio_6())
            tope = nuevo;
        else {
            if(weight >= tope->weight) {
                nuevo->siguiente = tope;
                tope = nuevo;
            }
            else {
                struct queue *aux = tope;
                while (aux->siguiente != NULL && weight < aux->siguiente->weight)
                    aux = aux->siguiente;
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
            }
        }
        cantidad--;
    }
}
void buscarNodo_5(int valor) {
    if (queueVacio_6()) {
        printf("La cola esta vacia");
        return;
    }
    int i = 0;
    struct queue *aux = tope;
    while (aux != NULL) {
        if(aux->valor == valor) {
            printf("El numero %d esta en la cola con peso %d, en la posicion %d\n", valor, aux->weight, i);
        }
        aux = aux->siguiente;
        i++;
    }
    printf("El nodo %d no esta en la cola \n", valor);
}
void eliminar_3() {
    if (queueVacio_6())
        printf("La cola esta vacia");
    else {
        printf("Sacando el numero %d con peso %d \n", tope->valor, tope->weight);
        struct queue *aux = tope;
        tope = tope->siguiente;
        free(aux);
    }
}
void contarNodos() {
    if(queueVacio_6()) {
        printf("La cola esta vacia");
        return;
    }
    int i = 0;
    struct queue *aux = tope;
    while (aux != NULL) {
        aux = aux->siguiente;
        i++;
    }
    printf("La cola tiene %d nodos \n", i);
}

void sumarMismoPeso(int peso) {
    if(queueVacio_6()) {
        printf("La cola esta vacia");
        return;
    }
    int suma = 0;
    struct queue *aux = tope;
    while (aux != NULL) {
        if(aux->weight == peso) {
            suma += aux->valor;
        }
        aux = aux->siguiente;
    }
    printf("La suma de los nodos con peso %d es %d \n", peso, suma);
}

void promedioPorPeso(int peso) {
    if(queueVacio_6()) {
        printf("La cola esta vacia");
        return;
    }
    int suma = 0;
    int cantidad = 0;
    struct queue *aux = tope;
    while (aux != NULL) {
        if(aux->weight == peso) {
            suma += aux->valor;
            cantidad++;
        }
        aux = aux->siguiente;
    }
    printf("El promedio de los nodos con peso %d es %d \n", peso, suma/cantidad);
}

int main() {
    agregar_1(1, 1);
    agregar_1(2, 2);
    agregar_1(3, 4);
    agregar_1(3, 4);
    agregar_1(5, 4);
    agregar_1(1, 3);
    agregar_1(4, 5);
    agregar_1(1, 4);
    agregar_1(9, 6);
    agregar_1(2, 8);
    agregar_1(4, 3);
    agregar_1(2, 3);
    agregar_1(6, 3);
    agregar_1(1, 6);
    agregar_1(5, 6);
    printf("\n");
    imprimir();
    printf("\n");
    eliminar_3();
    printf("\n");
    printf("Push consecutivos: \n");
    printf("\n");
    agregar_2(5, 1, 3);
    printf("\n");
    imprimir();
    printf("\n");
    printf("Buscar nodos: \n");
    printf("\n");
    buscarNodo_5(5);
    printf("Contar nodos: \n");
    printf("\n");
    contarNodos();
    printf("Promedio por pesos: \n");
    printf("\n");
    promedioPorPeso(3);
    printf("Sumas de un peso especifico: \n");
    printf("\n");
    sumarMismoPeso(3);
    printf("\n");
    printf("Eliminar: \n");
    printf("\n");
    eliminar_4();
    printf("\n");
    imprimir();
}