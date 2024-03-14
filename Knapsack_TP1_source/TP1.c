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

// Convertir en minuscules et retirer les caractères non alphabétiques
void convertir_texte(const char* source, char* destination) {
    int j = 0;
    for (int i = 0; source[i] != '\0'; i++) {
        if (isalpha(source[i])) {
            destination[j++] = to_lower(source[i]);
        }
    }
    destination[j] = '\0'; // Terminer la chaîne
}

// Chiffrer une lettre
char chiffrer_lettre(char lettre, char cle) {
    return 'a' + (lettre - 'a' + (cle - 'a')) % 26;
}

// Chiffrement de Vigenère
void chiffrer_vigenere(const char* texte, const char* cle, char* texteChiffre) {
    int longueurCle = strlen(cle);
    int j = 0;
    for (int i = 0; texte[i] != '\0'; i++) {
        // Chiffrer seulement les lettres alphabétiques
        if (isalpha(texte[i])) {
            texteChiffre[i] = chiffrer_lettre(texte[i], cle[j % longueurCle]);
            j++;
        } else {
            texteChiffre[i] = texte[i];
        }
    }
    texteChiffre[j] = '\0'; // Terminer la chaîne
}

int main() {
    char texte[1000], cle[1000], texteConverti[1000], cleConvertie[1000], texteChiffre[1000];
    
    // Lire le texte non chiffré
    printf("Entrez le texte non chiffré : ");
    fgets(texte, sizeof(texte), stdin);
    convertir_texte(texte, texteConverti);
    
    // Lire la clé
    printf("Entrez la clé : ");
    fgets(cle, sizeof(cle), stdin);
    convertir_texte(cle, cleConvertie);
    
    // Chiffrement de Vigenère
    chiffrer_vigenere(texteConverti, cleConvertie, texteChiffre);
    
    printf("Texte chiffré : %s\n", texteChiffre);
    
    return 0;
}
