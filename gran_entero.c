#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gran_entero.h"

// Función auxiliar para crear un nodo con un dígito
static Nodo* crearNodo(int digito) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->digito = digito;
    nuevo->sig = NULL;
    return nuevo;
}

// Convierte un string a GranEntero
GranEntero* creaGranEnteroDesdeStr(char *numero) {
    if (numero == NULL || *numero == '\0') return NULL;

    GranEntero *nuevo = (GranEntero*)malloc(sizeof(GranEntero));
    nuevo->inicio = NULL;
    nuevo->cantidad = 0;

    int i = 0;

    // Determinar signo
    if (numero[0] == '-') {
        nuevo->signo = -1;
        i++;
    } else {
        nuevo->signo = 1;
        if (numero[0] == '+') i++;
    }

    // Saltar ceros iniciales
    while (numero[i] == '0') i++;

    // Si todo era cero
    if (numero[i] == '\0') {
        Nodo *nodo = crearNodo(0);
        nuevo->inicio = nodo;
        nuevo->cantidad = 1;
        return nuevo;
    }

    Nodo *ultimo = NULL;
    for (; numero[i] != '\0'; i++) {
        if (!isdigit(numero[i])) {
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

// Convierte GranEntero a string
char* creaStrDesdeGranEntero(GranEntero *numero) {
    if (numero == NULL || numero->inicio == NULL) return NULL;

    int len = numero->cantidad + 1; // +1 para '\0'
    if (numero->signo == -1)
        len++; // para el '-'

    char *str = (char*)malloc(len * sizeof(char));
    if (!str) return NULL;

    char *ptr = str;

    if (numero->signo == -1)
        *ptr++ = '-';

    Nodo *actual = numero->inicio;
    while (actual) {
        *ptr++ = actual->digito + '0';
        actual = actual->sig;
    }

    *ptr = '\0';
    return str;
}

// Libera memoria de un GranEntero
void eliminaGranEntero(GranEntero *numero) {
    if (!numero) return;

    Nodo *actual = numero->inicio;
    while (actual) {
        Nodo *temp = actual;
        actual = actual->sig;
        free(temp);
    }
    free(numero);
}
