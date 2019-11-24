/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find the largest square
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "bsqh.h"
#include "my.h"

int increment_index(int *i, int *k, int *y, int width);

void check_is_filled( char *map, int k, int i, int *is_filled);

int eval_digit(int **digit_map, int i, int j, bg_square_t *bg_square)
{
    int a, b, c;

    if (digit_map[i][j] == 0 || i == 0 || j == 0)
        return (0);
    a = digit_map[i][j - 1];
    b = digit_map[i - 1][j - 1];
    c = digit_map[i - 1][j];
    if (a <= b && a <= c)
        digit_map[i][j] = a + 1;
    else if (b <= a && b <= c)
        digit_map[i][j] = b + 1;
    else if (c <= a && c <= b)
        digit_map[i][j] = c + 1;
    if (bg_square->size < digit_map[i][j]) {
        bg_square->x = j;
        bg_square->y = i;
        bg_square->size = digit_map[i][j];
    }
    return (0);
}

void print_large_square(bg_square_t *square, char *map, long long size, int k)
{
    int i = -1;
    int j = -1;
    int width = get_width(map);

    while (++i < square->size) {
        while (++j < square->size) {
            map[(width * (square->y - i))
                + square->x - j + k + square->y - i] = 'x';
        }
        j = -1;
    }
    write(1, (map + k), size - k);
}

void make_sqr(bg_square_t *square, char *map,
    long long size_fd, int is_filled)
{
    int i = -1;
    int k = 0;

    while ((map[k] >= '0' && map[k] <= '9') || map[k] == '\n')
        ++k;
    if (is_filled == 1) {
        write(1, (map + k), size_fd - k);
        return ;
    }
    if (square->size == 1 || square->size == 0) {
        while (map[++i] != '.' && map[i + 1] != '\0');
        map[i] = 'x';
        write(1, (map + k), size_fd - k);
        return ;
    }
    print_large_square(square, map, size_fd, k);
    return ;
}

void free_alloc(char *map, bg_square_t *bg_square, int **digit_map, int length)
{
    int i = -1;

    while (++i < length)
        free(digit_map[i]);
    free(digit_map);
    free(map);
    free(bg_square);
}

int is_correct_map(char *map, int width, int length)
{
    int i = -1;
    int is_filled = 1;
    int k = -1;
    int y = 0;

    while (map[++i - 1] != '\n');
    while (map[i] != '\0') {
        while (map[++k + i] != '\n') {
            check_is_filled(map, k, i, &is_filled);
            if (map[k + i] != '\n' && map[i + k] != '.' && map[i + k] != 'o' &&
                map[k +  i] != '\0')
                return (84);
        }
        if (increment_index(&i, &k, &y, width) == 84)
            return (84);
    }
    if (y != length)
        return (84);
    else
        return (is_filled);
}