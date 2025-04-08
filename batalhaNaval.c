#include <stdio.h>

#include <stdio.h>

int main() {
    // Criando o tabuleiro
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com zeros
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            tabuleiro[j][i] = 0;
        }
    }

    // Posicionando os navios no tabuleiro
    // Navio vertical
    tabuleiro[3][4] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[1][4] = 3;

    // Navio horizontal
    tabuleiro[7][5] = 3;
    tabuleiro[7][6] = 3;
    tabuleiro[7][7] = 3;

    // Imprimindo o tabuleiro com os navios posicionados
    printf("  a b c d e f g h i j\n");
    for (int j = 0; j < 10; j++) {
        printf("%d ", j); // Imprime o número da linha
        for (int i = 0; i < 10; i++) {
            printf("%d ", tabuleiro[j][i]);
        }
        printf("\n");
    }

        return 0;
    }
    