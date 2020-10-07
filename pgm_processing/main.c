#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef unsigned char pixel_t;
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define BUFFER_SIZE 128

int read_int(FILE *f);
void print_pgm(pixel_t picture[MAX_HEIGHT][MAX_WIDTH], int width, int height, FILE *f);
void invert_values(pixel_t picture[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void horizontal_mirror(pixel_t picture[MAX_HEIGHT][MAX_WIDTH], int width, int height);

int read_int(FILE *f) {
    int c;
    while ((c = fgetc(f)) != EOF && (isspace(c) || c == '#')) {
        if (c == '#') {
            while ((c = fgetc(f)) != EOF && c != '\n');
            if (c == EOF) return -1;
        }
    }
    if (c == EOF) return -1;

    char buffer[128];
    size_t n = 0;

    do {
        buffer[n++] = c;
    } while ((c = fgetc(f)) != EOF && !isspace(c) && n < 99);

    buffer[n] = '\0';
    return atoi(buffer);
}

void print_pgm(pixel_t picture[MAX_HEIGHT][MAX_WIDTH], int width, int height, FILE *f) {
    fprintf(f, "P2\n%d %d\n255\n", width, height);
    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            fprintf(f, "%d\n", picture[i][j]);
}

void invert_values(pixel_t picture[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            picture[i][j] = 255 - picture[i][j];
}


void horizontal_mirror(pixel_t picture[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width / 2; j++) {
            pixel_t buffer = picture[i][j];
            picture[i][j] = picture[i][width - j];
            picture[i][width - j] = buffer;
        }
    }
}

int main(int argc, const char *argv[]) {
    
    char aux[BUFFER_SIZE];



    FILE *f = fopen(argv[1], "r");
    fgets(aux, BUFFER_SIZE, f);
    if (strcmp(aux, "P2\n")) return 1;
    size_t width = read_int(f);
    size_t height = read_int(f);

    read_int(f);
    pixel_t sample_pic[MAX_HEIGHT][MAX_WIDTH];

    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            sample_pic[i][j] = read_int(f);

    fclose(f);
    
    invert_values(sample_pic, width, height);
    horizontal_mirror(sample_pic, width, height);

    FILE *pgm = fopen(argv[2], "w");

    print_pgm(sample_pic, width, height, pgm);

    fclose(pgm);

    return 0;
}