#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef uint8_t pixel_t;

typedef struct {
    pixel_t **lienzo;
    size_t ancho, alto;
} imagen_t;

imagen_t *_imagen_crear(size_t ancho, size_t alto);
void imagen_destruir(imagen_t *imagen);
imagen_t *imagen_leer_stdin();
void imagen_escribir(const imagen_t *imagen);
imagen_t *imagen_recortar(const imagen_t *imagen, size_t x0, size_t y0, size_t ancho, size_t alto);
imagen_t *imagen_clonar(const imagen_t *imagen);