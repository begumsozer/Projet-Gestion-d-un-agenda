#ifndef LIST_H
#define LIST_H

#include "cell.h"

typedef struct s_d_list {
    t_d_cell ***heads; // //Tableau 2D dynamique de pointeurs de niveau
    int max_level;
} t_d_list;

t_d_list *create_level_list(int n);
void insert_cell(t_d_list *list, int value, int num_levels);
void build_level_list(t_d_list *list, int n);
int search_level_list(t_d_list *list, int value);
int search_level_list_highest(t_d_list *list, int value);
void free_level_list(t_d_list *list);

#endif // LIST_H

