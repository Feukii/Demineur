#include "gestion.h"


int saisie_entier(void) {
        //declaration de variable
        int back;
        int n;
        //affichage du souhait
        printf("\n entrez un entier \n");
        //récupération résultat entré
        back = scanf("%d", &n);
        //vérification saisie
        if(back == 0) {
            //traitement en cas de succes
             fprintf(stderr, "Erreur de saisie entier");
             exit(ERREUR_SAISIE);
            
        }
      return n;    
    }

char *saise_chaine(char *chaine) {
// recuperation de la chaine entree par l'utilisateur
    scanf("%[^\n]s", chaine);
//retour de la valeur saisie
    return chaine;

}
char taper_caractere(void) {
char caractere;
printf("\n saisissez un caractere \n");
caractere = getchar();
printf("\n %c",caractere);
//test de la valeur entrée par l'utilisateur
if(caractere == '\0') {
//cas d'erreur affichage message d'erreur
fprintf(stderr, "Erreur de saisie de caractere");
exit (ERREUR_SAISIE);
 }
//cas de succès
else {
return caractere;
 }
}