#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void getname(char *nom);
char demander_une_lettre();
int lettre_pas_valide(char lettre);
void dessin(int tentatives);
void recuperer_mot(char mot[]);
void masquerMot(char *mot, char *mot_masque);

int main() {
    char nom[100];
    char mot[50];

    getname(nom);
    printf("Nom du joueur : %s\n", nom);

    int nbTentatives = 0;
    int partie_terminée = 0;

    recuperer_mot(mot);

    char mot_a_deviner[strlen(mot)];
    strcpy(mot_a_deviner, mot);

    char mot_partiellement_deviné[strlen(mot_a_deviner)];
    masquerMot(mot_a_deviner, mot_partiellement_deviné);

    while (nbTentatives < 8 && !partie_terminée) {
        printf("Mot à deviner : %s\n", mot_partiellement_deviné);
        char lettre = demander_une_lettre();

        int lettre_trouvée = 0;

        for (int i = 0; i < strlen(mot_a_deviner); i++) {
            if (lettre == mot_a_deviner[i] && mot_partiellement_deviné[i] == '_') {
                mot_partiellement_deviné[i] = lettre;
                lettre_trouvée = 1;
            }
        }

        if (!lettre_trouvée) {
            nbTentatives++;
            printf("Tentatives restantes : %d\n", 8 - nbTentatives);
            dessin(nbTentatives);
        }

        partie_terminée = 1;
        for (int i = 0; i < strlen(mot_a_deviner); i++) {
            if (mot_partiellement_deviné[i] == '_') {
                partie_terminée = 0;
                break;
            }
        }
    }

    if (partie_terminée) {
        printf("Félicitations, vous avez gagné! Le mot était : %s\n", mot_a_deviner);
    } else {
        printf("Désolé, vous avez perdu. Le mot était : %s\n", mot_a_deviner);
    }

    return 0;
}

void getname(char *nom) {
    printf("Donnez votre nom : ");
    scanf("%s", nom);
}

char demander_une_lettre() {
    char lettre;
    printf("Donnez une lettre : ");
    scanf(" %c", &lettre);
    return lettre;
}

int lettre_pas_valide(char lettre) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < strlen(alphabet); i++) {
        if (lettre == alphabet[i]) {
            return 0;
        }
    }
    return 1;
}

void recuperer_mot(char mot[]) {
    FILE *fichier = fopen("words.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        exit(1);
    }

    // Comptez le nombre de mots dans le fichier
    int nbMots = 0;
    char ligne[50];
    while (fgets(ligne, 50, fichier) != NULL) {
        nbMots++;
    }

    // Générez un nombre aléatoire pour choisir un mot
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires
    int motAleatoire = rand() % nbMots;

    // Revenez au début du fichier et lisez le mot aléatoire
    rewind(fichier);
    for (int i = 0; i < motAleatoire; i++) {
        fgets(ligne, 50, fichier);
    }

    fgets(mot, 50, fichier);

    fclose(fichier);
}

void masquerMot(char *mot, char *mot_masque) {
    int longueur = strlen(mot);
    for (int i = 0; i < longueur; i++) {
        if (mot[i] == ' ') {
            mot_masque[i] = ' ';
        } else {
            mot_masque[i] = '_';
        }
    }
    mot_masque[longueur] = '\0';
}

void dessin(int tentatives) {
   
   
    if (tentatives == 0) {
        printf(" ________\n");
        printf(" |       |\n");
        printf(" | \n");
        printf(" | \n ");
        printf("_|_\n");
        printf("| |_______\n");
        printf("|          |\n");
        printf("|__________|\n");
    
    
    } else if (tentatives == 1) {
        printf(" _______\n");
        printf(" |       |\n");
        printf(" |       o\n");
        printf(" | \n ");
        printf("_|_\n");
        printf("| |_______\n");
        printf("|          |\n");
        printf("|__________|\n");
  
  
    } else if (tentatives == 2) {
        printf(" _______\n");
        printf(" |       |\n");
        printf(" |       o\n");
        printf(" |       |\n");
        printf("_|_\n");
        printf("|  |_______\n");
        printf("|          |\n");
        printf("|__________|\n");
  
  
    } else if (tentatives == 3) {
        printf(" _______\n");
        printf(" |       |\n");
        printf(" |       o\n");
        printf(" |      ||\n");
        printf("_|_\n");
        printf("| |_______\n");
        printf("|          |\n");
        printf("|__________|\n");


    } else if (tentatives == 4) {
        printf("  ________\n");
        printf(" |       |\n");
        printf(" |       o\n");
        printf(" |       |\n");
      printf("_|_     /  \n");
        printf("|  |_______\n");
        printf("|          |\n");
        printf("|__________|\n");
 
 
    } else if (tentatives == 5) {
        printf(" _______\n");
        printf(" |       |\n");
        printf(" |       o\n");
        printf(" |       |\n");
        printf("_|_     / \\\n");
        printf("| |    \n");
        printf("|  |_______\n");
        printf("|          |\n");
        printf("|__________|\n");
        
        
            } else if (tentatives == 6) {
        printf("  _______  \n");
        printf("  |        |\n");
        printf("  |        o  \n");
        printf("  |       /|  \n      ");
printf("_|_       |  \n");
        printf("| |      / \\  \n");
        printf("|  |_______ \n");
        printf("|          | \n");
        printf("|__________| \n");
 
 
    } else if (tentatives == 7) {
        printf("  ___________  \n");
        printf("  |         |\n");
        printf("  |         o  \n");
        printf("  |        /|\\  \n      ");
printf("_|_        |  \n");
        printf("| |      / \\  \n");
        printf("|  |_______ \n");
        printf("|          | \n");
        printf("|__________| \n");
    }
}
   









































