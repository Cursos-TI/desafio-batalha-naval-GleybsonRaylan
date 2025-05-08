#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define NAVIO 3

int tabuleiro[TAM][TAM];


int direcoes[4][2] = {
    {0, 1},
    {1, 0},
    {1, 1},
    {1, -1}
};


void inicializarTabuleiro() {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}


int podePosicionar(int x, int y, int tamanho, int dx, int dy) {
    for (int i = 0; i < tamanho; i++) {
        int nx = x + dx * i;
        int ny = y + dy * i;

        if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM)
            return 0;

        if (tabuleiro[nx][ny] != 0)
            return 0;
    }
    return 1;
}


void posicionarNavio(int tamanho, int direcaoIndex) {
    int dx = direcoes[direcaoIndex][0];
    int dy = direcoes[direcaoIndex][1];

    int x, y;
    do {
        x = rand() % TAM;
        y = rand() % TAM;
    } while (!podePosicionar(x, y, tamanho, dx, dy));

    for (int i = 0; i < tamanho; i++) {
        int nx = x + dx * i;
        int ny = y + dy * i;
        tabuleiro[nx][ny] = NAVIO;
    }
}


void exibirTabuleiro() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    inicializarTabuleiro();


    posicionarNavio(4, 0);
    posicionarNavio(3, 1);

 
    posicionarNavio(3, 2); 
    posicionarNavio(2, 3);

    printf("Tabuleiro 10x10 com 4 navios:\n\n");
    exibirTabuleiro();

    return 0;
}
