#ifndef GRAN_ENTERO_H
#define GRAN_ENTERO_H

// Estructura para nodo de un dígito
typedef struct Nodo {
    int digito;
    struct Nodo *sig;
} Nodo;

// Estructura para GranEntero
typedef struct {
    Nodo *inicio;     // Apunta al primer dígito (más significativo)
    int signo;        // 1 para positivo, -1 para negativo
    int cantidad;     // Número de dígitos
} GranEntero;

// Prototipos de funciones
GranEntero *creaGranEnteroDesdeStr(char *numero);
char *creaStrDesdeGranEntero(GranEntero *numero);
void eliminaGranEntero(GranEntero *numero);

#endif
