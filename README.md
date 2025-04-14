
---description in english and in french

#Project – Agenda Management System (C Programming) 
The objective of this project was to develop an application that manages a digital agenda using a data structure between linked lists and trees, known as a skip list.

Our main goals were to strengthen our proficiency in C programming, particularly in managing a `main.c` file with numerous custom functions, handling complex data structures, and mastering one of the core concepts of the C language: pointers.

#Part 2: Advanced Search Using Skip Lists 
The second part of the project focused on implementing efficient search operations within a multi-level linked list (skip list), reducing the search complexity to approximate that of binary search.

- Each level in the skip list points to every second element of the level below.  
- The structure stores `2^n - 1` cells with values ranging from 1 to `2^n - 1`.  
- Searches start at the top level and move down one level when the target is not found, resuming from the current position.

#Key Objectives & Functionalities: 
- Create a dynamic list structure and define a cell structure.  
- Each cell must contain: a value and the number of levels it appears in.  
- The list must support multiple levels with a defined maximum number of levels.  
- Implement a function to insert a cell at the head of the list, considering its level.  
- Display all cells by level.  
- Display the entire skip list with all levels.  
- Insert a cell at a specific position, maintaining ascending order (challenging aspect).  

---

# Projet-Gestion-d-un-agenda
Le but de ce projet est de réaliser une application qui permet de gérer un
agenda en utilisant une structure de données intermédiaire entre les listes
chaînées et les arbres.
Nos principaux objectifs sont de consolider nos connaissances en langage C,
notamment savoir manipuler le fichier main avec les nombreuses fonctions
crées, gérer des structures de données complexes et apprendre à maitriser
une des notions les plus importantes en langage C les pointeurs.

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
