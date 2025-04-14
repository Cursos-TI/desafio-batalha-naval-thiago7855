#include <stdio.h>

int main() {
    // Criando o tabuleiro
    // 0 representa uma célula vazia, 3 representa partes de um navio
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
    printf("    A B C D E F G H I J\n"); // Cabeçalho das colunas
    for (int j = 0; j < 10; j++) {
        printf("%2d  ", j); // Imprime o número da linha com alinhamento
        for (int i = 0; i < 10; i++) {
            printf("%d ", tabuleiro[j][i]);
        }
        printf("\n");
    }

    return 0;
}