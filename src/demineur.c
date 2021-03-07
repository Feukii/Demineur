#include"gestion.h"
#include "demineur.h"


void init(int taille, case_plateau **jeu) {
 //declaration de variables   
    int i,j;
  // boucle d'initialisation 
   for(i=0; i<taille; i++) {
       for (j = 0; j < taille; j++)
       {
           jeu[i][j].contenu = '-';
           jeu[i][j].voisins = 0;
           jeu[i][j].demineur = 0;
       }
       
   }

}

void PlaceMines(int nb_mines, int taille, case_plateau **jeu) {
    // declaration de variables
    int i;
    int j;
    //initilisateion du generateur aleatoire de nb
    srand(time(NULL));
    //
    while(nb_mines){
        //assignation aleatoire des nombres aleatoires de ligne et de colonnes
         i = rand() % taille;
         j = rand() % taille;
        // boucle d'actualisation des voisins en fonction dde la case de la bombe choisie
        do{
           
            jeu[i][j].demineur = 1;
            jeu[i][j].contenu = '@';
            if(i==0 && j== 0){
                jeu[i+1][j].voisins =  jeu[i+1][j].voisins +1;
                jeu[i][j+1].voisins =  jeu[i+1][j].voisins +1;
                jeu[i+1][j+1].voisins =  jeu[i+1][j].voisins +1;
            }
            if(i==(taille-1) && j==(taille-1)){
                jeu[i-1][j].voisins =  jeu[i-1][j].voisins +1;
                jeu[i][j-1].voisins =  jeu[i][j-1].voisins +1;
                jeu[i-1][j-1].voisins =  jeu[i-1][j-1].voisins +1;
            }
            if(i==0 && j== (taille -1)){
                jeu[i+1][j].voisins =  jeu[i+1][j].voisins +1;
                jeu[i][j-1].voisins =  jeu[i][j-1].voisins +1;
                jeu[i+1][j-1].voisins =  jeu[i+1][j-1].voisins +1;
            } 
            if(i==(taille -1) && j== 0){
                jeu[i-1][j].voisins =  jeu[i-1][j].voisins +1;
                jeu[i-1][j+1].voisins =  jeu[i-1][j+1].voisins +1;
                jeu[i][j+1].voisins =  jeu[i][j+1].voisins +1;
            }
            if(i>0 && i<(taille-1) && j>0 && j<(taille-1)){
                jeu[i-1][j].voisins =  jeu[i-1][j].voisins +1;
                jeu[i+1][j].voisins =  jeu[i+1][j].voisins +1;
                jeu[i][j+1].voisins =  jeu[i][j+1].voisins +1;
                jeu[i][j-1].voisins =  jeu[i][j-1].voisins +1;
                jeu[i-1][j-1].voisins =  jeu[i-1][j-1].voisins +1;
                jeu[i-1][j+1].voisins =  jeu[i-1][j+1].voisins +1;
                jeu[i+1][j-1].voisins =  jeu[i+1][j-1].voisins +1;
                jeu[i+1][j+1].voisins =  jeu[i+1][j+1].voisins +1;

            }
            if(i==0 && j>0 && j<(taille-1)){
                jeu[i][j-1].voisins =  jeu[i][j-1].voisins +1;
                jeu[i][j+1].voisins =  jeu[i][j+1].voisins +1;
                jeu[i+1][j+1].voisins =  jeu[i+1][j+1].voisins +1;
                jeu[i+1][j].voisins =  jeu[i+1][j].voisins +1;
                jeu[i+1][j-1].voisins =  jeu[i+1][j-1].voisins +1;
                

            }
            if(i== (taille -1)  && j>0 && j<(taille-1)){
                jeu[i][j-1].voisins =  jeu[i][j-1].voisins +1;
                jeu[i][j+1].voisins =  jeu[i][j+1].voisins +1;
                jeu[i-1][j+1].voisins =  jeu[i-1][j+1].voisins +1;
                jeu[i-1][j].voisins =  jeu[i-1][j].voisins +1;
                jeu[i-1][j-1].voisins =  jeu[i-1][j-1].voisins +1;
                

            }
            if(j== (taille -1)  && i>0 && i<(taille-1)){
                jeu[i-1][j].voisins =  jeu[i-1][j].voisins +1;
                jeu[i+1][j].voisins =  jeu[i+1][j].voisins +1;
                jeu[i-1][j-1].voisins =  jeu[i-1][j-1].voisins +1;
                jeu[i][j-1].voisins =  jeu[i][j-1].voisins +1;
                jeu[i+1][j-1].voisins =  jeu[i+1][j-1].voisins +1;
                

            }
            if(j== 0  && i>0 && i<(taille-1)){
                jeu[i-1][j].voisins =  jeu[i-1][j].voisins +1;
                jeu[i+1][j].voisins =  jeu[i+1][j].voisins +1;
                jeu[i-1][j+1].voisins =  jeu[i-1][j+1].voisins +1;
                jeu[i][j+1].voisins =  jeu[i][j+1].voisins +1;
                jeu[i+1][j+1].voisins =  jeu[i+1][j+1].voisins +1;
            }
        
        }while (jeu[i][j].demineur != 1);
    nb_mines --;    
    }


    
}

int saisie_donne(char *invite, int taille) {
    //declaration  de variable
    int valeur;
    //saisie de l'entier
    do{
        printf("%s", invite);
       valeur =  saisie_entier();
    } while((valeur < 0) || (valeur > taille));

    //retour de la valeur saisie
    return (valeur);
}

int est_Mine(int x, int y,char choix, case_plateau **jeu){
    //declaration de variable
  int resultat;  
  //vérification du choix en fonction de la realite
   if(jeu[x][y].contenu == choix && jeu[x][y].demineur == 1) {
     resultat = 1;
   }else if (jeu[x][y].contenu == choix && jeu[x][y].demineur == 0){
       resultat = 1;
   // echec de la comparaison    
   }else {
       resultat = 0;

   }
       
   return (resultat); 
}


int gagne_vide(case_plateau **jeu, int taille){
    //declaration de variables
    int x;
    int y;
    int retour;
    //initilisation du retour
    retour =0;
    //boucle de verification et de comptage des cases vides decouvertes
     for(x=0; x<taille; x++) {
       for (y = 0; y < taille; y++) {
           if(jeu[x][y].decouvert == 1 && jeu[x][y].contenu == '-' ) {
                retour = retour+1;
           }
           
       }
       
   }

return (retour);
}

int gagne_bombe(case_plateau **jeu, int taille){
    //declaration de variables
    int x;
    int y;
    int  retour;
    //initialisation des variables
    retour =0;
    //decompte des bombes decouvertes
     for(x=0; x<taille; x++) {
       for(y = 0; y < taille; y++)  
       {
           if(jeu[x][y].decouvert == 1 && jeu[x][y].contenu == '@' ) {
                retour = retour+1;
           }
           
       }
       
   }

return (retour);
}

int verifier_case (case_plateau **jeu, int x, int y) {
    //declaration de variable
    int retour;
    //verification si la case a ete decouverte
    if(jeu[x][y].decouvert == 0){
        retour = 1;
    }
    else {
        retour = 0;
    }
return (retour);    

}

void dessine_plateau(case_plateau **plateau, int taille) {
    //declaration de variable
    int ligne;
    int colonne;
    int i_taille;

    // plateau[posX][posY].decouvert = 1;
    printf("  "); 
    for(i_taille=0; i_taille<taille; i_taille++) {
      printf("  %d ", i_taille);
    }
    printf("\n");

    for(ligne = 0 ; ligne < taille; ligne ++){
    printf("  ");    
        for(i_taille=0; i_taille<taille; i_taille++){
            printf("+---");
        }
    printf("+");
    printf(" \n %d", ligne);
        for(colonne=0; colonne <taille; colonne++){

            if(plateau[ligne][colonne].decouvert == 1){
                if(plateau[ligne][colonne].demineur ==1){
                    printf("| %c ", plateau[ligne][colonne].contenu);
                }else {
                    printf("| %d ", plateau[ligne][colonne].voisins);
                }
                 
            }
            else {
                printf("|   "); 
            }            
    
        }  
    printf("|  \n");
    }
    printf("  ");
    for(i_taille=0; i_taille<taille; i_taille++){
            printf("+---");
    }
    printf("\n");


}


void dessine_initial(case_plateau **plateau, int taille) {
    //declaration de variable
    int ligne;
    int colonne;
    int i_taille;

    // plateau[posX][posY].decouvert = 1;
    printf("  "); 
    for(i_taille=0; i_taille<taille; i_taille++) {
      printf("  %d ", i_taille);
    }
    printf("\n");

    for(ligne = 0 ; ligne < taille; ligne ++){
    printf("  ");    
        for(i_taille=0; i_taille<taille; i_taille++){
            printf("+---");
        }
    printf("+");
    printf(" \n %d", ligne);
        for(colonne=0; colonne <taille; colonne++){

            
            if(plateau[ligne][colonne].demineur ==1){
                    printf("| %c ", plateau[ligne][colonne].contenu);
            }else {
                    printf("| %d ", plateau[ligne][colonne].voisins);
            }
                             
    
        }  
    printf("|  \n");
    }
    printf("  ");
    for(i_taille=0; i_taille<taille; i_taille++){
            printf("+---");
    }
    printf("\n");


}

void jeu(case_plateau **jeu, int taille, int nb_mine) {

     //declaration de variables   
        int vide;
        int  bombe;
        int nb_cases_vide;
        int abscisse, ordonnee;
        char choix;
//initilisation des variables
    nb_cases_vide = ((taille*taille) - nb_mine); 
    vide = 0;
    bombe = 0;

  //verification du nombre de cases de bombes et cases normales decouvertes  
 while ( bombe != nb_mine && vide != nb_cases_vide){
        
             do{
                    printf(" \n tapez le caractere @ si vous voulez découvrir une bombe et le caractere  -  pour découvrir une case vide  \n ");
                    choix = taper_caractere();
                } while ((choix != '@') & (choix != '-'));
            do {
                    printf("choissisez une case que vous n'avez pas encore choisi \n");
                    abscisse = saisie_donne("Ligne : ", taille);
                    ordonnee = saisie_donne("Colonne : ", taille);
            }while ( verifier_case(jeu, abscisse,ordonnee) != 1);

             if(est_Mine(abscisse,ordonnee, choix, jeu) == 1){
                 jeu[abscisse][ordonnee].decouvert = 1;
                dessine_plateau(jeu, taille);
                vide = gagne_vide(jeu, taille);
                bombe = gagne_bombe(jeu, taille);
        

             }else {
                  printf(" \n vous avez perdu la partie \n");
                 printf(" \n TABLEAU INITIAL \n"); 
                dessine_initial(jeu,taille);
                  exit(ERREUR_SAISIE);
             }

        
         
}

    if(bombe == nb_mine){
        printf(" \n vous avez gagnez !!! vous avez découvert toutes les mines \n");
    }

    if (vide == nb_cases_vide) {
        printf(" \n vous avez gagnez !!! vous avez decouvert toutes les cases vides\n");

    } 
  printf(" \n TABLEAU INITIAL \n"); 
  dessine_initial(jeu,taille);
 

}

int principale(int taille, int nombre_bombes, case_plateau **affiche) {
// execution du jeu
 jeu(affiche, taille, nombre_bombes);

return (0);

}
