#include <stdio.h>
#include <stdlib.h>
#include "gran_entero.h"  // Asegúrate de que defines creaGranEnteroDesdeStr ahí

int main() {
    char *input = "-00789";

    GranEntero *g = creaGranEnteroDesdeStr(input);
    if (!g) {
        printf("Error al crear GranEntero.\n");
        return 1;
    }

    char *str = creaStrDesdeGranEntero(g);
    if (!str) {
        printf("Error al convertir a string.\n");
        eliminaGranEntero(g);
        return 1;
    }

    printf("Input original: %s\n", input);
    printf("GranEntero -> string: %s\n", str);

    free(str);
    eliminaGranEntero(g);

    return 0;
}
