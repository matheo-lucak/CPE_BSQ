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

void eval_digit(int **digit_map, int i, int j, bg_square_t *bg_square)
{
    int a = digit_map[i][j - 1];
    int b = digit_map[i - 1][j - 1];
    int c = digit_map[i - 1][j];

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

int is_correct_map(char *map)
{
    int i = 0;
    int is_filled = 1;

    while (map[i] >= '0' && map[i] <= '9')
        i++;
    while (map[++i] != '\0') {
        if (map[i] == '.')
            is_filled = 0;
        if (map[i] != '\n' && map[i] != '.' && map[i] != 'o' &&
            map[i] != '\0')
            return (84);
    }
    return (is_filled);
}
