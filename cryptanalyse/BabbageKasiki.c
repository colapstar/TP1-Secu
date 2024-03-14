#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fonction pour calculer le PGCD de deux nombres
int pgcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void trouver_sequences_repetees_et_calculer_pgcd(const char* texte) {
    int longueur = strlen(texte);
    int distances[1000]; // Tableau pour stocker les distances entre les séquences répétées
    int nb_distances = 0; // Nombre de distances stockées

    for (int taille_seq = 3; taille_seq <= longueur / 2; taille_seq++) {
        for (int i = 0; i <= longueur - taille_seq; i++) {
            char sequence[100] = {0}; // Tableau pour stocker la séquence temporaire
            strncpy(sequence, texte + i, taille_seq);
            int compteur = 0;
            for (int j = i + taille_seq; j <= longueur - taille_seq; j++) {
                char sequence_verif[100] = {0};
                strncpy(sequence_verif, texte + j, taille_seq);
                if (strcmp(sequence, sequence_verif) == 0) {
                    compteur++;
                    // Calculer et stocker la distance entre les répétitions
                    int distance = j - i;
                    distances[nb_distances++] = distance;
                }
            }
            if (compteur > 0) {
                printf("%s trouvé %d fois\n", sequence, compteur + 1);
            }
        }
    }

    // Calculer le PGCD des distances
    if (nb_distances > 0) {
        int pgcd_val = distances[0];
        for (int i = 1; i < nb_distances; i++) {
            pgcd_val = pgcd(pgcd_val, distances[i]);
        }
        printf("La longueur possible de la clé est %d\n", pgcd_val);
    } else {
        printf("Aucune séquence répétée trouvée pour calculer la longueur de la clé.\n");
    }
}

int main() {
    char texteChiffre[1000];
    printf("Entrez le texte chiffré : ");
    fgets(texteChiffre, sizeof(texteChiffre), stdin);
    texteChiffre[strcspn(texteChiffre, "\n")] = 0; // Enlever le caractère de nouvelle ligne

    trouver_sequences_repetees_et_calculer_pgcd(texteChiffre);

    return 0;
}
