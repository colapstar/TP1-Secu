#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Fonction pour calculer le PGCD de deux nombres
int pgcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Calculer la moyenne des distances
double calculer_moyenne(int distances[], int nb_distances) {
    double somme = 0;
    for (int i = 0; i < nb_distances; i++) {
        somme += distances[i];
    }
    return somme / nb_distances;
}

// Calculer l'écart type des distances
double calculer_ecart_type(int distances[], int nb_distances, double moyenne) {
    double somme_ecarts = 0;
    for (int i = 0; i < nb_distances; i++) {
        somme_ecarts += pow(distances[i] - moyenne, 2);
    }
    return sqrt(somme_ecarts / nb_distances);
}

void filtrer_et_trouver_longueur_cle(const int distances[], int nb_distances, double moyenne, double ecart_type) {
    // Filtre basé sur l'écart type pour éliminer les outliers
    int distances_filtrees[1000];
    int nb_distances_filtrees = 0;
    double seuil = ecart_type * 1.5;
    for (int i = 0; i < nb_distances; i++) {
        if (fabs(distances[i] - moyenne) <= seuil) {
            distances_filtrees[nb_distances_filtrees++] = distances[i];
        }
    }

    // Calculer le PGCD des distances filtrées
    if (nb_distances_filtrees > 0) {
        int pgcd_val = distances_filtrees[0];
        for (int i = 1; i < nb_distances_filtrees; i++) {
            pgcd_val = pgcd(pgcd_val, distances_filtrees[i]);
        }
        printf("La longueur probable de la clé, après filtrage, est %d\n", pgcd_val);
    } else {
        printf("Pas assez de données après filtrage pour déterminer la longueur de la clé.\n");
    }
}

void trouver_sequences_repetees_et_calculer_longueur_cle(const char* texte) {
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
                    int distance = j - i;
                    distances[nb_distances++] = distance;
                }
            }
            if (compteur > 0) {
                printf("%s trouvé %d fois\n", sequence, compteur + 1);
            }
        }
    }

    if (nb_distances > 0) {
        double moyenne = calculer_moyenne(distances, nb_distances);
        double ecart_type = calculer_ecart_type(distances, nb_distances, moyenne);
        filtrer_et_trouver_longueur_cle(distances, nb_distances, moyenne, ecart_type);
    } else {
        printf("Aucune séquence répétée trouvée pour calculer la longueur de la clé.\n");
    }
}

int main() {
    char texteChiffre[1000];
    printf("Entrez le texte chiffré : ");
    fgets(texteChiffre, sizeof(texteChiffre), stdin);
    texteChiffre[strcspn(texteChiffre, "\n")] = 0; // Enlever le caractère de nouvelle ligne

    trouver_sequences_repetees_et_calculer_longueur_cle(texteChiffre);

    return 0;
}
