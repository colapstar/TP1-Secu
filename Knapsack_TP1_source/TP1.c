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

// Exercice 4 : Chiffrement de Vigenère
void exercice4() {
    char texte[1000], cle[1000], texteConverti[1000] = {0}, cleConvertie[1000] = {0}, texteChiffre[1000] = {0};
    printf("Entrez le texte non chiffré : ");
    fgets(texte, sizeof(texte), stdin); // Pour éviter les problèmes avec le buffer après scanf dans exercice 3
    fgets(texte, sizeof(texte), stdin);
    printf("Entrez la clé : ");
    fgets(cle, sizeof(cle), stdin);
    
    int j = 0, k = 0;
    for (int i = 0; texte[i] != '\0'; i++) {
        if (isalpha(texte[i])) {
            texteConverti[j++] = to_lower(texte[i]);
        }
    }
    texteConverti[j] = '\0'; // Terminer la chaîne
    
    for (int i = 0; cle[i] != '\0'; i++) {
        if (isalpha(cle[i])) {
            cleConvertie[k++] = to_lower(cle[i]);
        }
    }
    cleConvertie[k] = '\0'; // Terminer la chaîne
    
    for (int i = 0, length = strlen(texteConverti), keyLength = strlen(cleConvertie); i < length; i++) {
        texteChiffre[i] = 'a' + (texteConverti[i] - 'a' + (cleConvertie[i % keyLength] - 'a')) % 26;
    }
    
    printf("Texte chiffré : %s\n", texteChiffre);
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

    return 0;
}
