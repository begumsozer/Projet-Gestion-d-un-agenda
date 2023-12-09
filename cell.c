#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

t_d_cell *create_cell(int value) {
    t_d_cell *cell = (t_d_cell *)malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->next = NULL;
    return cell;
}

void free_cell(t_d_cell *cell) {
    free(cell);
}
