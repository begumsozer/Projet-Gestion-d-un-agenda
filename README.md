# Projet-Gestion-d-un-agenda
La partie 2 du projet aborde la complexité de la recherche dans une liste à niveaux. 
Cette approche permet d'accélérer les recherches en se rapprochant de la complexité de la recherche par dichotomie.
La construction de la liste à niveaux suit un schéma où chaque niveau pointe sur une cellule sur deux du niveau précédent. 
Ainsi, la liste stocke 2^n-1 cellules avec des valeurs de 1 à 2^n-1. 
La recherche débute au niveau le plus élevé, et si la valeur n'est pas trouvée, elle descend au niveau précédent en repartant de la cellule où elle était arrivée.

Objectifs : 
        -> Créer une structure avec une liste dynamique et cellule
        ->La cellule doit contenir : valeur / nombre de niveaux
        -> La liste dynamique : plusieurs niveaux/ nombre max de niveaux
        -> Fonction pour insérer une cellule en tête de liste (Attention aux niveaux)
        -> Fonction pour afficher l’ensemble des cellules en fonction du niveau
        -> Fonction pour afficher la liste avec tous les niveaux
        -> Insertion d’une cellule à un endroit précis (difficultés à garder l’ordre croissant)
