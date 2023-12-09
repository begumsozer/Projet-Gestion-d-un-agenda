#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "timer.h"
//part2.2(avec timer.c et timer.h)
#define NUM_SEARCHES 10000 //occurrence du symbole NUM_SEARCHES dans le code sera remplacée par 10000
//nous exécutons le programme 3 fois avec les valeurs de recherche 1000,10000,1000000
//avec ces différentes valeurs de recherche on trouve différents temps de recherche que nous mettrons ensuite dans un graphique
int main() {
    int n_values[] = {3, 4, 5};  // //Exemples de valeurs de n
    int num_n_values = sizeof(n_values) / sizeof(n_values[0]);//calcule le nombre d'éléments dans le tableau n_values
    for (int i = 0; i < num_n_values; i++) {
        int n = n_values[i];
        t_d_list *list = create_level_list(n);
        build_level_list(list, n);

        // recherche classique utilisant uniquement le niveau 0
        int classic_search_results[NUM_SEARCHES];
        startTimer();
        for (int j = 0; j < NUM_SEARCHES; j++) {
            int target = rand() % (int)pow(2, n);
            // À chaque itération de la boucle, une valeur cible aléatoire est générée.
            // rand() génère un entier pseudo-aléatoire et % (int)pow(2, n) garantit que la valeur est comprise dans la plage de la liste de niveaux, de 0 à 2^n - 1.
            // Ceci simule la recherche d'une valeur aléatoire dans la plage de la liste de niveaux.
            //Remarque pour la bibliothèque pow : utilisée pour l'exponentiation. [pouvoir(2,n)=2^n]
            int level = search_level_list(list, target);
            classic_search_results[j] = level;
        }
        stopTimer();
        printf("Classic search with n=%d: %s\n", n, getTimeAsString());

        // recherche en commençant par le niveau le plus élevé
        int level_search_results[NUM_SEARCHES];
        startTimer();
        for (int j = 0; j < NUM_SEARCHES; j++) {
            int target = rand() % (int)pow(2, n);
            int level = search_level_list_highest(list, target);
            level_search_results[j] = level;
        }
        stopTimer();
        printf("Search from highest level with n=%d: %s\n", n, getTimeAsString());

        free_level_list(list);
    }

    return 0;
}
