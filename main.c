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

int eval_digit_map(char *map)
{
    bg_square_t *bg_square = malloc(sizeof(bg_square_t));
    int length = get_length(map);
    int width = get_width(map);
    int **digit_map = make_digit_map(map);
    int i, j = i = -1;

    if (is_correct_map(map) == 84)
        return (84);
    while (++i < length) {
        while (++j < width)
            if (digit_map[i][j] != 0 && i != 0 && j != 0)
                eval_digit(digit_map, i, j, bg_square);
    j = -1;
    }
    make_square(bg_square, digit_map, length, width);
    free_allocs(map, bg_square, digit_map, length);
    return (0);
}

int main (int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (eval_digit_map(read_map(av[1])));
}