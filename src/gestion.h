#ifndef GESTION_H
#define GESTION_H
/*! 
 *  \file gestion.h
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Tue 15 December 2020 - 11:32:33
 *
 *  \brief 
 *
 *
 */

// Inclusion des entetes de librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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


/*!
 *  \fn int saisie_entier(void)
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Tue 15 December 2020 - 11:35:51
 *  \brief fonction de saisie d'entier
 *  \param 
 *  \return n entier saisi
 *  \remarks 
 */

int saisie_entier(void);

/*!
 *  \char *saise_chaine(char *chaine)
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Tue 15 December 2020 - 11:39:49
 *  \brief fonction de saisie et de récupération d'une chaine de caractère
 *  \param *chaine chaine a saisir
 *  \return *chaine chaine saisie
 *  \remarks 
 */

char *saise_chaine(char *chaine);


/*!
 *  \fn char taper_caractere(void)
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Thu 17 December 2020 - 01:35:53
 *  \brief fonctionde saisie d'un caractère
 *  \param 
 *  \return caractere saisi
 *  \remarks 
 */

char taper_caractere(void);
#endif