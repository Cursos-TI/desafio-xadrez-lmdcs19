/*
 * ============================================================
 * MateCheck — Desafio: Movimentação de Peças de Xadrez
 * Nível: Novato
 * ============================================================
 *
 * Peças e movimentos:
 *   - Bispo : 5 casas na diagonal superior direita
 *             (cada casa = 1x "Cima" + 1x "Direita")
 *             → usa laço FOR
 *
 *   - Torre : 5 casas para a direita
 *             → usa laço WHILE
 *
 *   - Rainha: 8 casas para a esquerda
 *             → usa laço DO-WHILE
 *
 * Cada estrutura de repetição diferente atende ao requisito
 * de demonstrar os três tipos de loop em C.
 * ============================================================
 */

#include <stdio.h>

/* ---- Constantes de movimentação ---------------------------------- */

/* Número de casas que o Bispo percorre na diagonal */
#define CASAS_BISPO  5

/* Número de casas que a Torre percorre para a direita */
#define CASAS_TORRE  5

/* Número de casas que a Rainha percorre para a esquerda */
#define CASAS_RAINHA 8

/* ------------------------------------------------------------------ */

int main() {

    /* Contadores de iteração para cada laço */
    int passo;

    /* ============================================================
     * BISPO — diagonal superior direita
     * Estrutura de repetição: FOR
     *
     * A diagonal é composta pela combinação de duas direções
     * básicas executadas simultaneamente a cada casa:
     *   1. Cima   (componente vertical)
     *   2. Direita (componente horizontal)
     * ============================================================ */
    printf("============================================\n");
    printf("  BISPO — %d casas na diagonal superior direita\n", CASAS_BISPO);
    printf("  (loop: FOR)\n");
    printf("============================================\n");

    /*
     * O FOR é ideal aqui porque sabemos exatamente quantas
     * iterações serão feitas (CASAS_BISPO).
     * A cada iteração imprimimos "Cima" e "Direita",
     * representando o deslocamento diagonal.
     */
    for (passo = 1; passo <= CASAS_BISPO; passo++) {
        printf("  Casa %d -> Cima\n",    passo);
        printf("  Casa %d -> Direita\n", passo);
    }

    printf("  Bispo moveu %d casas na diagonal.\n\n", CASAS_BISPO);


    /* ============================================================
     * TORRE — 5 casas para a direita
     * Estrutura de repetição: WHILE
     *
     * O WHILE é adequado para situações onde a condição de
     * parada é verificada ANTES de cada iteração.
     * ============================================================ */
    printf("============================================\n");
    printf("  TORRE — %d casas para a direita\n", CASAS_TORRE);
    printf("  (loop: WHILE)\n");
    printf("============================================\n");

    /*
     * Inicializamos passo em 1 antes do laço.
     * O WHILE verifica se ainda há casas a percorrer;
     * caso contrário, nem entra no bloco.
     */
    passo = 1;
    while (passo <= CASAS_TORRE) {
        printf("  Casa %d -> Direita\n", passo);
        passo++; /* avança para a próxima casa */
    }

    printf("  Torre moveu %d casas para a direita.\n\n", CASAS_TORRE);


    /* ============================================================
     * RAINHA — 8 casas para a esquerda
     * Estrutura de repetição: DO-WHILE
     *
     * O DO-WHILE garante que o bloco seja executado pelo menos
     * uma vez, pois a condição é verificada APÓS cada iteração.
     * ============================================================ */
    printf("============================================\n");
    printf("  RAINHA — %d casas para a esquerda\n", CASAS_RAINHA);
    printf("  (loop: DO-WHILE)\n");
    printf("============================================\n");

    /*
     * Inicializamos passo em 1 antes do laço.
     * O DO-WHILE executa o bloco e só então verifica
     * se deve continuar — útil quando ao menos um
     * movimento sempre precisa ocorrer.
     */
    passo = 1;
    do {
        printf("  Casa %d -> Esquerda\n", passo);
        passo++; /* avança para a próxima casa */
    } while (passo <= CASAS_RAINHA);

    printf("  Rainha moveu %d casas para a esquerda.\n\n", CASAS_RAINHA);

    printf("============================================\n");
    printf("  Simulacao de movimentacao concluida!\n");
    printf("============================================\n");

    return 0;
}