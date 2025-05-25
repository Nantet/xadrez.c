#include <stdio.h>

// numero das casas que as peças podem movimentar
// Torre, Bispo, Rainha e Cavalo
const int casasTorre = 3;
const int casasBispo = 3;
const int casasRainha = 2;
const int tabuleiroLimite = 8;

//torre-
void moverTorreCima(int casas) {
    if (casas <= 0) return;
    printf("Cima\n");
    moverTorreCima(casas - 1);
}

void moverTorreDireita(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorreDireita(casas - 1);
}

//bispo
void moverBispoDiagonal(int vertical, int horizontal) {
    if (vertical <= 0 || horizontal <= 0) return;

    printf("Diagonal: Cima + Direita\n");

    moverBispoDiagonal(vertical - 1, horizontal - 1);
}

void moverBispoComLoops(int limite) {
    for (int i = 1; i <= limite; i++) {
        for (int j = 1; j <= limite; j++) {
            if (i == j) {
                printf("Diagonal com loops: Cima + Direita (%d, %d)\n", i, j);
            }
        }
    }
}

//rainha
void moverRainha(int casas) {
    if (casas <= 0) return;

    printf("Cima\n");
    printf("Direita\n");
    printf("Diagonal: Cima + Direita\n");

    moverRainha(casas - 1);
}

//cavalo
void moverCavalo() {
    int movimentosMax = 8;

    for (int y = 1; y <= movimentosMax; y++) {
        for (int x = 1; x <= movimentosMax; x++) {
           //movimento do cavalo em formato de L
            int novoY = y - 2;
            int novoX = x + 1;

            if (novoY < 1 || novoX > movimentosMax) {
                continue; 
            }

            printf("Cavalo move: 2 Cima e 1 Direita (de [%d,%d] para [%d,%d])\n", y, x, novoY, novoX);
        }
    }
}

int main() {
    
    //torre
    printf("Movimentos da Torre:\n");
    moverTorreCima(casasTorre);
    moverTorreDireita(casasTorre);
    printf("\n");

    //bispo
    printf("Movimentos do Bispo (Recursivo):\n");
    moverBispoDiagonal(casasBispo, casasBispo);
    printf("\n");

    printf("Movimentos do Bispo (Loops Aninhados):\n");
    moverBispoComLoops(casasBispo);
    printf("\n");

    //rainha
    printf("Movimentos da Rainha:\n");
    moverRainha(casasRainha);
    printf("\n");

    // caalo
    printf("Movimentos do Cavalo:\n");
    moverCavalo();
    printf("\n");

    return 0;
}
