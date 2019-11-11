/*
** EPITECH PROJECT, 2019
** bsqh
** File description:
** bsq header
*/

#ifndef BSQH_H_
#define BSQH_H_

typedef struct bg_square{
    int x;
    int y;
    int size;
} bg_square_t;

int get_length(char const *map);

int get_width(char const *map);

long long get_byte_size(char const *filepath);

int **make_digit_map(char *map);

char *read_map(char const *filepath, long long size);

void eval_digit(int **digit_map, int i, int j, bg_square_t *bg_square);

void print_square(int i);

void make_sqr(bg_square_t *square, char *map,
    long long size_fd, int is_filled);

void free_alloc(char *map, bg_square_t *bg_square, int **digit_map, int length);

int is_correct_map(char *map);

#endif
