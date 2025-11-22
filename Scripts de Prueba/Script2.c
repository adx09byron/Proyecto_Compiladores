#include <stdio.h>

int main() {
    int opcion;

    do {
        printf("\nMENU BASE DE DATOS\n");
        printf("1. Insertar registro\n");
        printf("2. Mostrar registros\n");
        printf("3. Buscar registro\n");
        printf("4. Eliminar registro\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Insertando registro...\n");
                break;
            case 2:
                printf("Mostrando registros...\n");
                break;
            case 3:
                printf("Buscando registro...\n");
                break;
            case 4:
                printf("Eliminando registro...\n");
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while(opcion != 0);

    return 0;
}
