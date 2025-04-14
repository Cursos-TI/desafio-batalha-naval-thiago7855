#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se a posição está dentro do tabuleiro
bool posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO;
}

// Verifica se pode posicionar navio sem sobreposição
bool posicaoLivre(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

// Posiciona navio horizontal ou vertical
bool posicionarNavioReto(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, bool horizontal) {
    // Verifica se todas as posições estão livres
    for (int i = 0; i < tamanho; i++) {
        int novaLinha = horizontal ? linha : linha + i;
        int novaColuna = horizontal ? coluna + i : coluna;
        
        if (!posicaoValida(novaLinha, novaColuna) || !posicaoLivre(tabuleiro, novaLinha, novaColuna)) {
            return false;
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < tamanho; i++) {
        int novaLinha = horizontal ? linha : linha + i;
        int novaColuna = horizontal ? coluna + i : coluna;
        tabuleiro[novaLinha][novaColuna] = NAVIO;
    }
    
    return true;
}

// Posiciona navio diagonal
bool posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, bool diagonalPrincipal) {
    // Verifica se todas as posições estão livres
    for (int i = 0; i < tamanho; i++) {
        int novaLinha = linha + i;
        int novaColuna = diagonalPrincipal ? coluna + i : coluna - i;
        
        if (!posicaoValida(novaLinha, novaColuna) || !posicaoLivre(tabuleiro, novaLinha, novaColuna)) {
            return false;
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < tamanho; i++) {
        int novaLinha = linha + i;
        int novaColuna = diagonalPrincipal ? coluna + i : coluna - i;
        tabuleiro[novaLinha][novaColuna] = NAVIO;
    }
    
    return true;
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    // Cabeçalho com letras A-J
    printf("\n   ");
    for (char c = 'A'; c <= 'J'; c++) {
        printf(" %c ", c);
    }
    printf("\n");
    
    // Linha separadora
    printf("  +");
    for (int j = 0; j < TAMANHO; j++) {
        printf("---");
    }
    printf("+\n");
    
    // Conteúdo do tabuleiro
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d|", i + 1); // Linhas numeradas de 1 a 10
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    
    // Linha separadora
    printf("  +");
    for (int j = 0; j < TAMANHO; j++) {
        printf("---");
    }
    printf("+\n\n");
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    printf("=== BATALHA NAVAL ===\n");
    printf("Posicionando navios...\n");
    
    // Posiciona navios retos (horizontal/vertical)
    posicionarNavioReto(tabuleiro, 2, 3, 3, true);  // Horizontal (linha 3, colunas D-F)
    posicionarNavioReto(tabuleiro, 5, 8, 4, false); // Vertical (coluna I, linhas 6-9)
    
    // Posiciona navios diagonais
    posicionarNavioDiagonal(tabuleiro, 0, 0, 3, true);  // Diagonal principal (A1, B2, C3)
    posicionarNavioDiagonal(tabuleiro, 1, 9, 4, false); // Diagonal secundária (J2, I3, H4, G5)
    
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}