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
    // Navio vertical (valor 3 representa o navio)
    tabuleiro[3][4] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[1][4] = 3;

    // Navio horizontal (valor 3 representa o navio)
    tabuleiro[7][5] = 3;
    tabuleiro[7][6] = 3;
    tabuleiro[7][7] = 3;

    // Imprimindo o tabuleiro com os navios posicionados
    printf("    a b c d e f g h i j\n"); // Cabeçalho das colunas
    printf("  +---------------------+\n"); // Borda superior
    for (int j = 0; j < 10; j++) {
        printf("%d | ", j); // Número da linha com borda lateral
        for (int i = 0; i < 10; i++) {
            printf("%d ", tabuleiro[j][i]);
        }
        printf("|\n"); // Borda lateral direita
    }
    printf("  +---------------------+\n"); // Borda inferior

    return 0;
}