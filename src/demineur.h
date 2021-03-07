#ifndef DEMINEUR_H
#define DEMINEUR_H
/*! 
 *  \file demineur.h
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Tue 15 December 2020 - 11:32:21
 *
 *  \brief 
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
/*! 
 \def EXIT_SUCCESS
  Code confirmant la bonne exécution du programme
*/
#define EXIT_SUCCESS 0 
/*! 
 \def ERREUR_SAISIE
  Code d'erreur attestant qu'une erreur de saisie s'est produite
*/
#define ERREUR_SAISIE -1

#define TRUE 1
#define FALSE 0



struct Case
{
 char contenu;
 int decouvert;
 int voisins;
 int demineur;
};
typedef struct Case case_plateau;



/*!
 *  \fn void  init(int taille, case_plateau **jeu);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:05:43
 *  \brief procedure d'initialisation du statut de toutes les cases du tableau
 *  \param taille taille du tableau 2D
 *  \param jeu structure repreésentant le plateau du jeu avec toutes ses colonnes
 *  \remarks 
 */

void  init(int taille, case_plateau **jeu);

/*!
 *  \fn void  PlaceMines(int nb_mines, int taille, case_plateau **jeu);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:08:20
 *  \brief precedure de choix aléatoire de la postion des bombes et de l'actualisation du statut des voisins de la bombe
 *  \param nb_mines nombre de bombes
 *  \param taille taille du tableau
 *  \param jeu structure repreésentant le plateau du jeu avec toutes ses colonnes
 *  \remarks 
 */

void  PlaceMines(int nb_mines, int taille, case_plateau **jeu);


/*!
 *  \fn int saisie_donne(char *invite, int taille);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:11:27
 *  \brief fonction de saisie des coordonees
 *  \param  invite message indicateur de saisi
 *  \param taille taille du tableau 2d
 *  \return  entier entre respectant la taille réquise
 *  \remarks 
 */

int saisie_donne(char *invite, int taille);

/*!
 *  \fn int est_Mine(int x, int y,char choix, case_plateau **jeu);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:14:16
 *  \brief fonction de vérification de l'état d'une case pour verifier le choix de l'utilisateur
 *  \param x abscisse de la case
 *  \param y ordonee de la case
 *  \param choix choix de l'utilisateur si le statut de la case
 *  \param jeu structure repreésentant le plateau du jeu avec toutes ses colonnes
 *  \return 1 si la case et le choix entree correspondent a la realite 0 sinon
 *  \remarks 
 */

int est_Mine(int x, int y,char choix, case_plateau **jeu);


/*!
 *  \fn int gagne_vide(case_plateau **jeu, int taille);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:18:13
 *  \brief calcul le nombre de cases vides decouvertes
 *  \param jeu structure representant le plateau du jeu avec toutes ses colonnes
 *  \param taille taille du tableau 2d
 *  \return n nombre instantanée de case vide découvertes
 *  \remarks 
 */

int gagne_vide(case_plateau **jeu, int taille);


/*!
 *  \fn int gagne_bombe(case_plateau **jeu, int taille);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:19:57
 *  \brief calcul le nombre de bombes decouvertes a un instant t
 *  \param jeu structure representant le plateau du jeu avec toutes ses colonnes
 *  \param taille taille du tableau 2d
 *  \return n nombre instanne de cases de bombes decouvertes
 *  \remarks 
 */

int gagne_bombe(case_plateau **jeu, int taille);



/*!
 *  \fn int verifier_case (case_plateau **jeu, int x, int y);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:22:53
 *  \brief vérifie si une case est découverte ou pas
 *  \param jeu structure representant le plateau du jeu avec toutes ses colonnes
 *  \param x abscisse de la case
 *  \param y ordonnee de la case
 *  \return 1 si elle case a deja ete decouverte et 0 sinon
 *  \remarks 
 */

int verifier_case (case_plateau **jeu, int x, int y);

/*!
 *  \fn void dessine_plateau(case_plateau **plateau, int taille);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:33:18
 *  \brief procedure de dessin du plateau en fonction des decouvertes des cases
 *  \param jeu structure representant le plateau du jeu avec toutes ses colonnes
 *  \param x abscisse de la case decouverte
 *  \param y ordonnee de la case decouverte
 *  \remarks 
 */

void dessine_plateau(case_plateau **plateau, int taille);


/*!
 *  \fn void dessine_initial(case_plateau **plateau, int taille);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:31:49
 *  \brief  procedure de dessin du tableau initial
 *  \param jeu structure representant le plateau du jeu avec toutes ses colonnes
 *  \param taille taille du tableau  2d
 *  \remarks 
 */

void dessine_initial(case_plateau **plateau, int taille);



/*!
 *  \fn void jeu(case_plateau **jeu, int taille, int nb_mine);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:30:12
 *  \brief procedure d'execution du jeu 
 *  \param taille taille du tableau 2d
 *  \param nb_mine nombre de bombes
 *  \param jeu structure representant le plateau du jeu avec toutes ses colonnes
 *  \remarks 
 */

void jeu(case_plateau **jeu, int taille, int nb_mine);



/*!
 *  \fn int principale(int taille, int nombre_bombes, case_plateau **affiche);
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Sun 20 December 2020 - 01:28:02
 *  \brief fonction a partir de laquelle le jeu est lancé
 *  \param taille taille du tableau 2d
 *  \param nombre_bombes nombres de bombes
 *  \param affiche structure representant le plateau du jeu avec toutes ses colonnes
 *  \return 0 si tout se passe bien
 *  \remarks 
 */

int principale(int taille, int nombre_bombes, case_plateau **affiche);


#endif