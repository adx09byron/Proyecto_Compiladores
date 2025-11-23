import java.io.*;
import java.util.*;

public class EstadisticasPrograma {
    
    // Número Entero
    public static boolean esEntero(String str) {
        int i = 0;
        
        // Cadena vacía
        if (str.isEmpty()) {
            return false;
        }
        
        // Signo negativo o positivo
        if (str.charAt(0) == '-' || str.charAt(0) == '+') {
            i = 1;
        }
        
        // Todo debe ser dígito
        if (i >= str.length()) {
            return false; // Solo tiene el signo
        }
        
        while (i < str.length()) {
            if (!Character.isDigit(str.charAt(i))) {
                return false;
            }
            i++;
        }
        
        return true;
    }
    
    // Número Flotante
    public static boolean esFlotante(String str) {
        int i = 0;
        boolean tienePunto = false;
        int digitosDespuesPunto = 0;
        
        // Cadena vacía
        if (str.isEmpty()) {
            return false;
        }
        
        // Signo negativo o positivo
        if (str.charAt(0) == '-' || str.charAt(0) == '+') {
            i = 1;
        }
        
        if (i >= str.length()) {
            return false; // Solo tiene el signo
        }
        
        // Formato flotante
        while (i < str.length()) {
            if (str.charAt(i) == '.') {
                if (tienePunto) {
                    return false; // Más de un punto
                }
                tienePunto = true;
            } else if (!Character.isDigit(str.charAt(i))) {
                return false;
            } else if (tienePunto) {
                // Contar dígitos después del punto
                digitosDespuesPunto++;
            }
            i++;
        }
        
        // Debe tener punto Y al menos un dígito después del punto
        return (tienePunto && digitosDespuesPunto > 0);
    }
    
    // Función para tokenizar manualmente sin regex
    public static ArrayList<String> tokenizar(String linea) {
        ArrayList<String> tokens = new ArrayList<>();
        StringBuilder tokenActual = new StringBuilder();
        
        // Definir delimitadores
        String delimitadores = " \t\n\r(){}[];,<>=+-*/%&|!~^.\":\'#";
        
        for (int i = 0; i < linea.length(); i++) {
            char c = linea.charAt(i);
            
            // Si es delimitador
            if (delimitadores.indexOf(c) != -1) {
                // Guardar token si tiene contenido
                if (tokenActual.length() > 0) {
                    tokens.add(tokenActual.toString());
                    tokenActual = new StringBuilder();
                }
            } else {
                // Agregar carácter al token actual
                tokenActual.append(c);
            }
        }
        
        // Agregar último token si existe
        if (tokenActual.length() > 0) {
            tokens.add(tokenActual.toString());
        }
        
        return tokens;
    }
    
    public static void main(String[] args) {
        int totalLineas = 0;
        int lineasEscritas = 0;
        int totalPalabras = 0;
        int totalEnteros = 0;
        int totalFlotantes = 0;
        int totalCaracteresPalabras = 0;
        
        try {
            // Abrir el archivo
            BufferedReader archivo = new BufferedReader(new FileReader("Script1.java"));
            
            System.out.println();
            System.out.println("   ESTADISTICAS DEL PROGRAMA   ");
            System.out.println("           LENGUAJE JAVA        ");
            System.out.println();
            
            String linea;
            
            // Lectura línea por línea
            while ((linea = archivo.readLine()) != null) {
                totalLineas++;
                
                // Verificar si es línea vacía
                boolean esLineaVacia = true;
                for (int i = 0; i < linea.length(); i++) {
                    char c = linea.charAt(i);
                    if (c != ' ' && c != '\t' && c != '\n' && c != '\r') {
                        esLineaVacia = false;
                        break;
                    }
                }
                
                // Contar línea escrita
                if (!esLineaVacia) {
                    lineasEscritas++;
                }
                
                // Tokenizar la línea para contar palabras
                ArrayList<String> tokens = tokenizar(linea);
                
                for (String token : tokens) {
                    // Verificar si es un flotante
                    if (esFlotante(token)) {
                        totalFlotantes++;
                    }
                    // Verificar si es un entero
                    else if (esEntero(token)) {
                        totalEnteros++;
                    } else {
                        // Solo contar como palabra si NO es un número
                        totalPalabras++;
                        
                        // Calcular longitud de la palabra
                        totalCaracteresPalabras += token.length();
                    }
                }
            }
            
            // Calcular promedio
            double largoPromedio = 0.0;
            if (totalPalabras > 0) {
                largoPromedio = (double) totalCaracteresPalabras / totalPalabras;
            }
            
            // Mostrar resultados
            System.out.println("Numero total de lineas:        " + totalLineas);
            System.out.println("Lineas escritas (no vacias):   " + lineasEscritas);
            System.out.println("Numero total de palabras:      " + totalPalabras);
            System.out.println("Numero total de enteros:       " + totalEnteros);
            System.out.println("Numero total de flotantes:     " + totalFlotantes);
            System.out.printf("Largo promedio de palabras:    %.2f caracteres\n", largoPromedio);
            
            System.out.println();
            
            // Cerrar el archivo
            archivo.close();
            
        } catch (FileNotFoundException e) {
            System.out.println("Error: No se pudo abrir el archivo Script1.java");
            System.out.println("Asegurate de que el archivo existe en el mismo directorio.");
        } catch (IOException e) {
            System.out.println("Error al leer el archivo: " + e.getMessage());
        }
    }
}
