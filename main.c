/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main func for bsq
*/

#include <stdio.h>
#include <stdlib.h>
#include "bsqh.h"
#include "my.h"

int eval_digit_map(char *map, long long size)
{
    bg_square_t *bg_square = malloc(sizeof(bg_square_t));
    int **digit_map = make_digit_map(map);
    int width = get_width(map);
    int length = get_length(map);
    int i = -1;
    int j = -1;
    int is_filled = is_correct_map(map, width, length);

    bg_square->size = 0;
    if (is_filled == 84)
        return (84);
    while (++i < length) {
        while (++j < width)
            eval_digit(digit_map, i, j, bg_square);
    j = -1;
    }
    make_sqr(bg_square, map, size, is_filled);
    free_alloc(map, bg_square, digit_map, length);
    return (0);
}

int main (int ac, char **av)
{
    long long size = get_byte_size(av[1]);
    char *buffer;

    if (ac != 2 || size == 0)
        return (84);
    buffer = read_map(av[1], size);
    if (buffer == NULL)
        return (84);
    return (eval_digit_map(buffer, size));
}
