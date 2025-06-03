#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Nodo {
    int digito;
    struct Nodo *sig;
} Nodo;

typedef struct {
    Nodo *inicio;
    int signo;     // 1 positivo, -1 negativo
    int cantidad;
} GranEntero;

// Función auxiliar para crear un nodo
Nodo* crearNodo(int digito) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->digito = digito;
    nuevo->sig = NULL;
    return nuevo;
}

GranEntero* creaGranEnteroDesdeStr(char *numero) {
    if (numero == NULL || *numero == '\0') return NULL;

    GranEntero *nuevo = (GranEntero*)malloc(sizeof(GranEntero));
    nuevo->inicio = NULL;
    nuevo->cantidad = 0;

    int i = 0;
    // Signo
    if (numero[0] == '-') {
        nuevo->signo = -1;
        i++;
    } else {
        nuevo->signo = 1;
        if (numero[0] == '+') i++;
    }

    // Saltar ceros iniciales
    while (numero[i] == '0') i++;

    // Si todo eran ceros, agregar solo un nodo con 0
    if (numero[i] == '\0') {
        Nodo *nodo = crearNodo(0);
        nuevo->inicio = nodo;
        nuevo->cantidad = 1;
        return nuevo;
    }

    // Agregar dígitos a la lista
    Nodo *ultimo = NULL;
    for (; numero[i] != '\0'; i++) {
        if (!isdigit(numero[i])) {
            // Manejo de error: carácter no válido
            free(nuevo);
            return NULL;
        }

        int digito = numero[i] - '0';
        Nodo *nodo = crearNodo(digito);
        if (nuevo->inicio == NULL) {
            nuevo->inicio = nodo;
        } else {
            ultimo->sig = nodo;
        }
        ultimo = nodo;
        nuevo->cantidad++;
    }

    return nuevo;
}
