#ifndef L2PROJECT_23_10_23_CELL_H
#define L2PROJECT_23_10_23_CELL_H

typedef struct s_d_cell {
    int value;
    struct s_d_cell *next;//au lieu de creer next_0 et next_1
} t_d_cell;

t_d_cell *create_cell(int value);
void free_cell(t_d_cell *cell);

#endif //L2PROJECT_23_10_23_CELL_H
