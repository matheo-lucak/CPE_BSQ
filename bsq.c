/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find the largest square
*/

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

void print_square(int i)
{
    if (i == 0)
        my_putchar('o');
    else if (i >= 0)
        my_putchar('.');
    else
        my_putchar('x');
}

void make_square(bg_square_t *square, int **digit_map, int length, int width)
{
    int i = -1;
    int j = -1;

    while (++i < square->size) {
        while (++j < square->size)
            digit_map[square->y - i][square->x - j] = -1;
        j = -1;
    }
    i = -1;
    j = -1;
    while (++i < length) {
        while (++j < width)
                print_square(digit_map[i][j]);
        my_putchar(10);
        j = -1;
    }
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

    while (map[i] >= '0' && map[i] <= '9')
        i++;
    i++;
    while (map[++i] != '\0')
        if (map[i] != '\n' && map[i] != '.' && map[i] != 'o' &&
            map[i] != '\0')
            return (84);
    return (0);
}
