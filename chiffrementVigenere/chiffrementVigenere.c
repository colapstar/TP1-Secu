#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Fonction pour convertir une lettre en minuscule
char to_lower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    else
        return c;
}

// Exercice 1 : Afficher le texte non chiffré
void exercice1() {
    char texte[1000];
    printf("Entrez un texte : ");
    fgets(texte, sizeof(texte), stdin);
    printf("Texte non chiffré : %s\n", texte);
}

// Exercice 2 : Convertir en minuscules et retirer les caractères non alphabétiques
void exercice2() {
    char texte[1000], texteFinal[1000];
    printf("Entrez un texte : ");
    fgets(texte, sizeof(texte), stdin);
    
    int j = 0;
    for (int i = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            texteFinal[j++] = to_lower(texte[i]);
        }
    }
    texteFinal[j] = '\0'; // Ne pas oublier de terminer la chaîne
    
    printf("Texte converti : %s\n", texteFinal);
}

// Exercice 3 : Chiffrer une lettre
void exercice3() {
    char lettre, cle;
    printf("Entrez une lettre non chiffrée et la clé : ");
    scanf(" %c %c", &lettre, &cle);
    printf("%c + %c = %c\n", lettre, cle, 'a' + (to_lower(lettre) - 'a' + (to_lower(cle) - 'a')) % 26);
}

// Chiffrement de Vigenère
void chiffrer_vigenere(const char* texte, const char* cle, char* texteChiffre) {
    int longueurCle = strlen(cle);
    int j = 0;
    for (int i = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            texteChiffre[i] = 'a' + (to_lower(texte[i]) - 'a' + (to_lower(cle[j % longueurCle]) - 'a')) % 26;
            j++;
        }
    }
    texteChiffre[j] = '\0'; // Terminer la chaîne
}

// Exercice 4 : Chiffrement de Vigenère avec saisie utilisateur
void exercice4() {
    char texte[1000], cle[1000], texteChiffre[1000];
    printf("Entrez le texte non chiffré : ");
    fgets(texte, sizeof(texte), stdin); // Pour capturer le '\n' restant de l'exercice 3
    fgets(texte, sizeof(texte), stdin);
    printf("Entrez la clé : ");
    fgets(cle, sizeof(cle), stdin);
    
    chiffrer_vigenere(texte, cle, texteChiffre);
    printf("Texte chiffré : %s\n", texteChiffre);
}

// Déchiffrement de Vigenère
void dechiffrer_vigenere(const char* texteChiffre, const char* cle, char* texteDechiffre) {
    int longueurCle = strlen(cle);
    int j = 0;
    for (int i = 0; texteChiffre[i] != '\0'; i++) {
        if (isalpha(texteChiffre[i])) {
            int decalage = to_lower(cle[j % longueurCle]) - 'a';
            int lettre = to_lower(texteChiffre[i]) - 'a' - decalage;
            if (lettre < 0) lettre += 26;
            texteDechiffre[i] = 'a' + lettre;
            j++;
        }
    }
    texteDechiffre[j] = '\0'; // Terminer la chaîne
}

// Exercice 5 : Déchiffrement de Vigenère avec saisie utilisateur
void exercice5() {
    char texteChiffre[1000], cle[1000], texteDechiffre[1000];
    printf("Entrez le texte chiffré : ");
    fgets(texteChiffre, sizeof(texteChiffre), stdin);
    printf("Entrez la clé : ");
    fgets(cle, sizeof(cle), stdin);
    
    dechiffrer_vigenere(texteChiffre, cle, texteDechiffre);
    printf("Texte déchiffré : %s\n", texteDechiffre);
}

int main() {
    // Exercice 1
    printf("Exercice 1 :\n");
    exercice1();
    
    // Exercice 2
    printf("\nExercice 2 :\n");
    exercice2();
    
    // Exercice 3
    printf("\nExercice 3 :\n");
    exercice3();
    
    // Exercice 4
    printf("\nExercice 4 :\n");
    getchar(); // Pour nettoyer le buffer après exercice 3
    exercice4();
    
    // Exercice 5
    printf("\nExercice 5 :\n");
    exercice5();

    return 0;
}
