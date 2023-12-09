#include "list.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_d_list *create_level_list(int n) { // pour créer une structure de données de liste double (double linked list) avec plusieurs niveaux
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->max_level = n;
    list->heads = (t_d_cell ***)malloc(sizeof(t_d_cell **) * n);
    //allouer pour les niveaux dans la t_d_list
    //le triple pointeur t_d_cell *** est utilisé pour représenter le tableau dynamique de pointeurs vers différents niveaux de cellules dans la t_d_list,
    // et c'est nécessaire car les niveaux peuvent varier en taille
    for (int i = 0; i < n; i++) {
        int num_cells = (int)pow(2, i);
        list->heads[i] = (t_d_cell **)malloc(sizeof(t_d_cell *) * num_cells);
        for (int j = 0; j < num_cells; j++) {
            list->heads[i][j] = NULL;
        }
    }

    return list;
}

void insert_cell(t_d_list *list, int value, int num_levels) {
    int level = 0;
    t_d_cell *cell = create_cell(value);
    for (int i = 0; i < num_levels; i++) {
        int num_cells = (int)pow(2, i);
        int index = value % num_cells;
        cell->next = list->heads[i][index];
        list->heads[i][index] = cell;
    }
}
// nous n'utilisons pas insert_cell dans part2.2 mais il a été utilisé dans part1 et part2.1

void build_level_list(t_d_list *list, int n) {
    for (int i = 0; i < n; i++) {
        int num_cells = (int)pow(2, i);
        for (int j = 0; j < num_cells; j++) {
            int value = j;
            t_d_cell *cell = create_cell(value);
            cell->next = list->heads[i][j];
            list->heads[i][j] = cell;
        }
    }
}
//build_level_list est utilisé pour construire la structure de données de la liste de niveaux en fonction du nombre spécifié de niveaux (n).
// Il crée des cellules et les relie entre elles à chaque niveau, créant ainsi une structure hiérarchique.
//On peut le décrire comme un type d'arbre binaire, mais il n'a pas les mêmes caractéristiques qu'un arbre binaire de recherche
int search_level_list(t_d_list *list, int value) {
    for (int i = list->max_level - 1; i >= 0; i--) { //on fait i--; il fait le recherche sans une seule niveau
        int num_cells = (int)pow(2, i);//chaque niveau a deux cellules potentielles pour chaque position
        // donc ca nous donne le nombre des cellules possibles au niveau i
        int index = value % num_cells;
        t_d_cell *current = list->heads[i][index];
        while (current != NULL) {
            if (current->value == value) {
                return i;
            }
            current = current->next;
        }
    }
    return -1; // "not found"
}

int search_level_list_highest(t_d_list *list, int value) {
    for (int i = 0; i < list->max_level; i++) { //i++ pour qu'il puisse aller a max_level
        int num_cells = (int)pow(2, i);
        int index = value % num_cells;
        t_d_cell *current = list->heads[i][index];
        while (current != NULL) {
            if (current->value == value) {
                return i;
            }
            current = current->next;
        }
    }
    return -1; // "not found"
}

void free_level_list(t_d_list *list) {
    for (int i = 0; i < list->max_level; i++) {
        int num_cells = (int)pow(2, i);
        for (int j = 0; j < num_cells; j++) {
            t_d_cell *current = list->heads[i][j];
            while (current != NULL) {
                t_d_cell *temp = current;
                current = current->next;
                free_cell(temp);
            }
        }
        free(list->heads[i]);
    }
    free(list->heads);
    free(list);
}
