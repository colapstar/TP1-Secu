#include <stdio.h>

char chiffrement_vigenere(char lettre_texte, char lettre_cle) {
    // Décalage correspondant à la lettre de la clé
    int decalage = lettre_cle - 'a';
    
    // Calcul de la lettre chiffrée
    char lettre_chiffree = ((lettre_texte - 'a' + decalage) % 26) + 'a';
    
    return lettre_chiffree;
}

int main() {
    char lettre_texte, lettre_cle;
    
    printf("Entrez une lettre du texte (minuscule) : ");
    scanf("%c", &lettre_texte);
    getchar(); // pour consommer le caractère de nouvelle ligne restant
    
    printf("Entrez une lettre de la clé (minuscule) : ");
    scanf("%c", &lettre_cle);
    getchar(); // pour consommer le caractère de nouvelle ligne restant
    
    char lettre_chiffree = chiffrement_vigenere(lettre_texte, lettre_cle);
    
    printf("%c = %d\n", lettre_cle, lettre_cle - 'a');
    printf("%c + %d = %c\n", lettre_texte, lettre_cle - 'a', lettre_chiffree);
    
    return 0;
}
