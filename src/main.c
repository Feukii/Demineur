#include "demineur.h"
#include "gestion.h"


/*!
 *  \fn int main(int argc, char **argv)
 *  \author FEUKENG ARIEL<feukengyem@eisti.eu>
 *  \version 0.1
 *  \date Tue 15 December 2020 - 11:51:04
 *  \brief fonction principale du programme
 *  \param argc nombre de parametres en entrée
 * \param argv valeur des paramètres en entrée
 *  \return 0 si tout est ok
 *  \remarks 
 */

int main(int argc, char **argv) {
   //declaration de variables
    int taille_tableau;
    int nb_demineur;
    int i;


case_plateau **affiche;



   
       printf(" ________________________________\n");
       printf("|                                |\n");
       printf("|        Jeu du demineur         |\n");
       printf("|________________________________|\n\n");
       
    printf(" \n Veuillez choisir la taille du taille du tableau dans lequel vous voudriez jouez \n ");
    taille_tableau = saisie_entier();
    printf("\n ***\n");
    printf("\n Veuillez choisir le nombre de démineur que vous aurez dans votre tableau \n");
    nb_demineur = saisie_entier();
    printf("\n ***\n");
   //allocation dynamique des lignes
    affiche = malloc(taille_tableau * sizeof(case_plateau*));
    //allocation dynamique des colonnes
    for(i = 0; i<taille_tableau; i++) {
        affiche[i] = malloc(taille_tableau * sizeof(case_plateau));
    }
   init(taille_tableau, affiche);
   
   PlaceMines(nb_demineur, taille_tableau, affiche);
   
    principale(taille_tableau, nb_demineur,affiche);
    


      printf(" ________________________________\n");
       printf("|                                |\n");
       printf("|         FIN DU DEMINEUR        |\n");
       printf("|________________________________|\n\n");
    for(i = 0; i<taille_tableau; i++) {
            free(affiche[i]);
        }
    free(affiche);   
     return (0);
}