%{
#include <stdio.h>
int total_lineas = 0;
int total_palabras = 0;
int total_enteros = 0;
int total_longitud_palabras = 0;
%}

%%
\n                      { total_lineas++; }
[0-9]+                  { total_enteros++; }
[a-zA-Z_][a-zA-Z0-9_]*  { 
                            total_palabras++;
                            total_longitud_palabras += yyleng;
                        }
.                       ;   /* Ignorar otros caracteres */
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Total de líneas: %d\n", total_lineas);
    printf("Total de palabras: %d\n", total_palabras);
    printf("Total de enteros: %d\n", total_enteros);
    if (total_palabras > 0)
        printf("Promedio longitud de palabras: %.2f\n",
               (float)total_longitud_palabras / total_palabras);
    else
        printf("Promedio longitud de palabras: 0\n");
    return 0;
}
