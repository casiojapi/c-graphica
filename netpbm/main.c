#include <stdio.h>

#include "netpbm.h"

// ej-1 defines

#define ANCHO 400
#define ALTO 400
#define MAXIMO 255

#define X0 (ANCHO / 2)
#define Y0 (ALTO / 2)

#define FRECUENCIA 0.002

// ej-1 defines

int main(int argc, char const *argv[]){
    if (argc != 2){
        fprintf(stderr, "ARGUMENTS\n");
        return 1;
    }
    FILE *image = fopen(argv[1], "w");
    if (image == NULL){
        fprintf(stderr, "error opening file\n");
        return 1;
    }
    fprintf(image, "P3\n");
    fprintf(image, "%d %d\n %d\n", ANCHO, ALTO, MAXIMO);
    for (size_t i = 0; i < ALTO; i++){
        for (int j = 0; j < ANCHO; j++){
            double val = scaled_sin(distance(i, j ,X0, Y0), j * FRECUENCIA, MAXIMO);
            fprintf(image, "%d\t %d %d\n", (int)(val*0.01*j), (int)(val /2), (int)(val*.2));
        }
    }
    return 0;
}