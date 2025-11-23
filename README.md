# Proyecto: Estadísticas de Programa  
**Materia:** Lenguajes y Compiladores  
**Tema del Proyecto:** Nº 2 — Análisis Léxico de un Script en C y Java  
**Integrantes:** *Edison Quizhpe - Byron Salazar*  

---

## Descripción del Proyecto
Este proyecto implementa una herramienta de **análisis léxico básico** para archivos fuente escritos en C o Java.  
El sistema procesa línea por línea y tokeniza manualmente el contenido para obtener estadísticas del programa, tales como conteo de números enteros, números flotantes, palabras y líneas escritas.

El objetivo principal es comprender cómo funciona la fase de **análisis léxico** dentro de un compilador.

---

## Estadísticas Calculadas por el Sistema

El programa analiza un archivo (`Script1.c` o `Script1.java`) y calcula:

- ✔ Número total de **líneas**  
- ✔ Número de **líneas escritas** (no vacías)  
- ✔ Número total de **palabras**  
- ✔ Cantidad de **números enteros**  
- ✔ Cantidad de **números flotantes**  
- ✔ **Promedio de longitud** de palabras  

---

## Lógica General del Algoritmo
1. Abrir el archivo fuente.  
2. Leer cada línea con `fgets` (C) o `readLine` (Java).  
3. Contar líneas totales y líneas vacías.  
4. Tokenizar texto usando delimitadores manuales.  
5. Por cada token:  
   - Verificar si es **entero**.  
   - Verificar si es **flotante**.  
   - Caso contrario, contarlo como **palabra** y sumar su longitud.  
6. Calcular estadísticas finales.  
7. Mostrar resultados en consola.

---

# 📌 Implementación en C

### `int esEntero(char *str)`
Determina si una cadena representa un número entero válido.  
- Acepta signo `+` o `-`.  
- Evalúa dígitos con `isdigit`.  
- Retorna 1 si es entero, 0 si no lo es.

### `int esFlotante(char *str)`
Verifica si el token es un número flotante válido.  
- Detecta el uso correcto del punto decimal.  
- Requiere al menos un dígito después del punto.  
- Retorna 1 si es flotante.

### `int main()`
Realiza todo el análisis:  
- Abre `Script1.c`.  
- Cuenta líneas vacías y no vacías.  
- Tokeniza con `strtok` usando delimitadores extensos.  
- Llama a `esEntero` y `esFlotante`.  
- Acumula palabras y longitud total.  
- Calcula largo promedio.  
- Imprime todas las estadísticas.

---

# 📌 Implementación en Java

### `static boolean esEntero(String str)`
Función que determina si un string es un número entero.  
- Maneja signo inicial.  
- Recorre carácter por carácter.  
- Similar al comportamiento del código en C.

### `static boolean esFlotante(String str)`
Comprueba si un string es un número flotante válido.  
- Solo permite un punto decimal.  
- Requiere dígitos después del punto.  
- Evita errores como `"12.."` o `"-.5"`.

### `static ArrayList<String> tokenizar(String linea)`
Tokeniza una línea manualmente **sin usar regex**.  
- Recorre cada carácter.  
- Divide según delimitadores manuales (coinciden con los usados en C).  
- Genera una lista de tokens limpios.

### `public static void main(String[] args)`
- Abre `Script1.java`.  
- Repite todo el procedimiento del código en C pero en Java.  
- Usa `BufferedReader` para lectura eficiente.  
- Imprime las métricas finales del análisis.

---

## Tecnologías Utilizadas

### Lenguaje C
- `stdio.h`, `ctype.h`, `string.h`  
- Tokenización con `strtok`  
- Clasificación manual de tokens  
- Lectura secuencial de archivo

### Lenguaje Java
- `BufferedReader`, `FileReader`  
- Tokenización manual con `ArrayList`  
- Métodos propios para enteros y flotantes  
- Manejo de excepciones

---

## Conclusiones
Este proyecto permitió comprender el funcionamiento interno del análisis léxico, simulando cómo un compilador separa tokens y clasifica tipos de datos.  
Se mostró cómo un mismo análisis puede implementarse en dos lenguajes distintos, comparando la manipulación de cadenas y manejo de archivos entre C y Java.

---






