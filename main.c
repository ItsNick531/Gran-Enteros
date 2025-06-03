#include <stdio.h>
#include <stdlib.h>
#include "gran_entero.h"

int main() {
    char *input = "-00789";

    // Convertir string a GranEntero
    GranEntero *g = creaGranEnteroDesdeStr(input);
    if (!g) {
        printf("Error al crear GranEntero.\n");
        return 1;
    }

    // Convertir GranEntero a string
    char *str = creaStrDesdeGranEntero(g);
    if (!str) {
        printf("Error al convertir GranEntero a string.\n");
        eliminaGranEntero(g);
        return 1;
    }

    // Mostrar resultado
    printf("Input original: %s\n", input);
    printf("GranEntero → string: %s\n", str);

    // Liberar memoria
    free(str);
    eliminaGranEntero(g);

    return 0;
}
