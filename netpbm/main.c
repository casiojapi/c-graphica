#include <stdio.h>

#include "netpbm.h"

// ej-1 defines

#define ANCHO 1000
#define ALTO 600
#define MAXIMO 255

#define X0 (ANCHO / 2)
#define Y0 (ALTO / 2)

#define FRECUENCIA 0.0000733
        
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
            double val = scaled_sin(distance(j, i , X0, Y0), i * FRECUENCIA, MAXIMO);
            fprintf(image, "%d\t %d %d\n", (int)(val*0.6333221), (int)(val * .8 * j), (int)(val*.91132));
        }
    }
    return 0;
}