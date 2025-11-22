# Proyecto: Estadísticas de Programa  
**Materia:** Lenguajes y Compiladores  
**Tema del Proyecto:** Nº 2 — Análisis de un Script en C  
**Integrantes:** *Edison Quizhpe - Byron Salazar*  

---

## Descripción del Proyecto
Este proyecto consiste en desarrollar una herramienta capaz de analizar un archivo fuente escrito en lenguaje **C** para obtener estadísticas estructurales del programa.  
El objetivo principal es aplicar conceptos de **análisis léxico**, una etapa fundamental en el proceso de compilación.

---

## Objetivos del Sistema
El programa debe procesar un archivo `.c` y calcular:

- ✔ Número total de **líneas**  
- ✔ Número total de **palabras**  
- ✔ Cantidad de **enteros** presentes en el script  
- ✔ **Promedio de longitud** de las palabras  

El sistema lee el archivo completo, lo tokeniza y genera un reporte final con los valores obtenidos.

---

## Lógica del Algoritmo
1. Abrir y leer el archivo línea por línea.  
2. Incrementar el contador de líneas.  
3. Separar cada línea en *tokens* usando delimitadores.  
4. Por cada token:
   - Contar palabras.  
   - Sumar su longitud.  
   - Verificar si representa un número entero.  
5. Calcular el promedio de longitud.  
6. Imprimir todos los resultados.

---

## Tecnologías Utilizadas
El proyecto puede implementarse en:

- **C**  
  - Manejo manual de cadenas con `strtok`, `isdigit`.  
  - Lectura con `fgets`.  

**o**

- **Java**  


---





