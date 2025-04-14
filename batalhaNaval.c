#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For abs function

#define TAM_TAB 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HAB 5 // Tamanho 5x5 para matrizes de habilidade

// Protótipos de funções
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]);
void posicionarNavios(int tabuleiro[TAM_TAB][TAM_TAB]);
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]);
void criarHabilidadeCone(int habilidade[TAM_HAB][TAM_HAB]);
void criarHabilidadeCruz(int habilidade[TAM_HAB][TAM_HAB]);
void criarHabilidadeOctaedro(int habilidade[TAM_HAB][TAM_HAB]);
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int centro_x, int centro_y);

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona os navios
    posicionarNavios(tabuleiro);
    
    printf("=== BATALHA NAVAL COM HABILIDADES ESPECIAIS ===\n");
    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);
    
    // Cria as matrizes de habilidade
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];
    
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);
    
    // Aplica as habilidades em posições específicas
    printf("\nAplicando Habilidade Cone (centro em 2,2):\n");
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    exibirTabuleiro(tabuleiro);
    
    printf("\nAplicando Habilidade Cruz (centro em 5,5):\n");
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    exibirTabuleiro(tabuleiro);
    
    printf("\nAplicando Habilidade Octaedro (centro em 7,7):\n");
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);
    exibirTabuleiro(tabuleiro);
    
    return 0;
}

void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNavios(int tabuleiro[TAM_TAB][TAM_TAB]) {
    // Navio horizontal (tamanho 3)
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    
    // Navio vertical (tamanho 4)
    tabuleiro[5][8] = NAVIO;
    tabuleiro[6][8] = NAVIO;
    tabuleiro[7][8] = NAVIO;
    tabuleiro[8][8] = NAVIO;
    
    // Navio diagonal principal (tamanho 3)
    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;
    
    // Navio diagonal secundária (tamanho 4)
    tabuleiro[1][9] = NAVIO;
    tabuleiro[2][8] = NAVIO;
    tabuleiro[3][7] = NAVIO;
    tabuleiro[4][6] = NAVIO;
}

void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("\n   ");
    for (int j = 0; j < TAM_TAB; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAM_TAB; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLegenda:\n");
    printf("0 - Água\n3 - Navio\n5 - Área afetada por habilidade\n");
}

void criarHabilidadeCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Cone apontando para baixo (topo na linha 0)
            if (j >= (TAM_HAB/2 - i/2) && j <= (TAM_HAB/2 + i/2)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Forma de cruz (linha e coluna central)
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Forma de losango (octaedro)
            int distancia = abs(i - centro) + abs(j - centro);
            if (distancia <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int centro_x, int centro_y) {
    int desloc = TAM_HAB / 2;
    
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int x = centro_x + (i - desloc);
                int y = centro_y + (j - desloc);
                
                // Verifica se está dentro dos limites do tabuleiro
                if (x >= 0 && x < TAM_TAB && y >= 0 && y < TAM_TAB) {
                    tabuleiro[x][y] = HABILIDADE;
                }
            }
        }
    }
}