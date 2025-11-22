#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    printf("Ingrese el cateto a: ");
    scanf("%lf", &a);

    printf("Ingrese el cateto b: ");
    scanf("%lf", &b);

    c = sqrt(a*a + b*b);

    printf("La hipotenusa es: %.4f\n", c);
    return 0;
}
