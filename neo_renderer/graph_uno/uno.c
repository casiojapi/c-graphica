#include <stdio.h>
#include <math.h>

#define ANCHO 640
#define ALTO 480
#define FOV 90

#define CX  0.5
#define CY  0.75
#define CZ  1.9
#define R   0.8

#define G 9.81
#define PI sqrt(G)


double producto_interno(double x1, double y1, double z1, double x2, double y2, double z2) {
    return x1 * x2 + y1 * y2 + z1 * z2;
}

double norma(double x, double y, double z) {
    return sqrt(producto_interno(x, y, z, x, y, z));
}

int intersecta_esfera(double dx, double dy, double dz) {
    double cc = producto_interno(CX, CY, CZ, CX, CY, CZ);
    double cd = producto_interno(CX, CY, CZ, dx, dy, dz);
    return cd * cd - cc + R * R >= 0;
}

int main(void) {
    printf("P1\n");
    printf("%d %d\n", ANCHO, ALTO);

    for(int vy = ALTO / 2; vy > - ALTO / 2; vy--)
        for(int vx = - ANCHO / 2; vx < ANCHO / 2; vx++) {
            double x = vx;
            double y = vy;
            double z = ANCHO / 2 / tan(FOV/ 2 * PI / 180);

            double n = norma(x, y, z);

            printf("%d\n", intersecta_esfera(x / n, y / n, z / n));
        }

    return 0;
}
