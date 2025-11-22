#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funcion Número Entero
int esEntero(char *str) {
    int i = 0;
    
    // Cadena vacia
    if (str[0] == '\0') {
        return 0;
    }
    
    // Signo negativo o positivo
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
    }
    
    // Todo debe ser dígito
    if (str[i] == '\0') {
        return 0; // Solo tiene el signo
    }
    
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    
    return 1;
}

// Funcion Número Flotante
int esFlotante(char *str) {
    int i = 0;
    int tienePunto = 0;
    int digitosDespuesPunto = 0;
    
    // Cadena vacia
    if (str[0] == '\0') {
        return 0;
    }
    
    // Signo negativo o positivo
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
    }
    
    if (str[i] == '\0') {
        return 0; // Solo tiene el signo
    }
    
    // Formato flotante
    while (str[i] != '\0') {
        if (str[i] == '.') {
            if (tienePunto) {
                return 0; // Mas de un punto
            }
            tienePunto = 1;
        } else if (!isdigit(str[i])) {
            return 0;
        } else if (tienePunto) {
            // Contar digitos despues del punto
            digitosDespuesPunto++;
        }
        i++;
    }
    
    // Debe tener punto Y al menos un digito despues del punto
    return (tienePunto && digitosDespuesPunto > 0);
}

int main() {
    FILE *archivo;
    char linea[1000];
    int totalLineas = 0;
    int lineasEscritas = 0;
    int totalPalabras = 0;
    int totalEnteros = 0;
    int totalFlotantes = 0;
    int totalCaracteresPalabras = 0;
    
    // Abrir el archivo
    archivo = fopen("Script1.c", "r");
    
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo Script1.c\n");
        printf("Asegurate de que el archivo existe en el mismo directorio.\n");
        return 1;
    }
    
    printf("\n");
    printf("   ESTADISTICAS DEL PROGRAMA   \n");
    printf("           LENGUAJE C          \n");
    printf("\n");
    
    // Lectura linea por linea
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        totalLineas++;
        
        // Leer linea y verificar si es vacia
        int esLineaVacia = 1;
        for (int i = 0; linea[i] != '\0'; i++) {
            if (linea[i] != ' ' && linea[i] != '\t' && linea[i] != '\n' && linea[i] != '\r') {
                esLineaVacia = 0;
                break;
            }
        }
        
        // Contar linea escrita
        if (!esLineaVacia) {
            lineasEscritas++;
        }
        
        // Tokenizar la linea para contar palabras
        char *token;
        char lineaCopia[1000];
        strcpy(lineaCopia, linea);
        
        // Delimitadores: espacios, tabs, newlines, y caracteres especiales
        token = strtok(lineaCopia, " \t\n\r(){}[];,<>=+-*/%&|!~^.\":\'#");
        
        while (token != NULL) {
            // Verificar si es un flotante
            if (esFlotante(token)) {
                totalFlotantes++;
            }
            // Verificar si es un entero
            else if (esEntero(token)) {
                totalEnteros++;
            } else {
                // Solo contar como palabra si NO es un numero
                totalPalabras++;
                
                // Calcular longitud de la palabra
                int longitud = strlen(token);
                totalCaracteresPalabras += longitud;
            }
            
            token = strtok(NULL, " \t\n\r(){}[];,<>=+-*/%&|!~^.\":\'#");
        }
    }
    
    // Calcular promedio
    double largoPromedio = 0.0;
    if (totalPalabras > 0) {
        largoPromedio = (double)totalCaracteresPalabras / totalPalabras;
    }
    
    // Mostrar resultados
    printf("Numero total de lineas:        %d\n", totalLineas);
    printf("Lineas escritas (no vacias):   %d\n", lineasEscritas);
    printf("Numero total de palabras:      %d\n", totalPalabras);
    printf("Numero total de enteros:       %d\n", totalEnteros);
    printf("Numero total de flotantes:     %d\n", totalFlotantes);
    printf("Largo promedio de palabras:    %.2f caracteres\n", largoPromedio);
    
    printf("\n");
    
    // Cerrar el archivo
    fclose(archivo);
    
    return 0;
}
