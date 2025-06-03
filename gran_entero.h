#ifndef GRAN_ENTERO_H
#define GRAN_ENTERO_H

#include <stdio.h>

typedef struct Nodo {
    int digito;
    struct Nodo *sig;
} Nodo;

typedef struct {
    Nodo *inicio;
    int signo;
    int cantidad;
} GranEntero;

GranEntero *creaGranEnteroDesdeStr(char *numero);
char *creaStrDesdeGranEntero(GranEntero *numero);
void eliminaGranEntero(GranEntero *numero);

#endif
