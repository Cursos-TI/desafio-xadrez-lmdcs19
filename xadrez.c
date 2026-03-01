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

/* Número de movimentos em L que o Cavalo executa */
#define MOVIMENTOS_CAVALO 5

/* Componente vertical do L: quantas casas desce por movimento */
#define CASAS_CAVALO_BAIXO 2

/* Componente horizontal do L: quantas casas vai à esquerda por movimento */
#define CASAS_CAVALO_ESQUERDA 1

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


    /* ============================================================
     * CAVALO — movimento em L (Baixo + Esquerda)
     * Nível Aventureiro
     *
     * O cavalo percorre MOVIMENTOS_CAVALO saltos em L.
     * Cada salto é composto por:
     *   - CASAS_CAVALO_BAIXO    casas para Baixo     (2 casas)
     *   - CASAS_CAVALO_ESQUERDA casas para Esquerda  (1 casa)
     *
     * Estruturas aninhadas utilizadas:
     *   - Loop EXTERNO : FOR   — controla cada salto completo em L
     *   - Loop INTERNO : WHILE — percorre os passos de "Baixo"
     *                            dentro de cada salto
     *   Após o while interno, um printf final registra o passo
     *   horizontal ("Esquerda") que completa o L.
     * ============================================================ */
    printf("============================================\n");
    printf("  CAVALO — %d saltos em L (Baixo + Esquerda)\n", MOVIMENTOS_CAVALO);
    printf("  Cada L: %d casa(s) Baixo + %d casa(s) Esquerda\n",
           CASAS_CAVALO_BAIXO, CASAS_CAVALO_ESQUERDA);
    printf("  (loops aninhados: FOR externo + WHILE interno)\n");
    printf("============================================\n");

    /*
     * Loop EXTERNO — FOR
     * Responsável por repetir o salto em L completo.
     * Sabemos de antemão quantos saltos o cavalo fará,
     * então o FOR é a escolha natural.
     *
     * Variável: salto → número do salto atual (1 até MOVIMENTOS_CAVALO)
     */
    {
        int salto;         /* contador do salto atual (loop externo) */
        int passo_baixo;   /* contador dos passos verticais (loop interno) */

        for (salto = 1; salto <= MOVIMENTOS_CAVALO; salto++) {

            printf("\n  -- Salto %d --\n", salto);

            /*
             * Loop INTERNO — WHILE
             * Percorre os passos verticais ("Baixo") do L.
             * O WHILE é usado aqui para contrastar com o FOR externo
             * e demonstrar o uso de loops aninhados diferentes.
             *
             * A condição é checada antes de cada passo vertical,
             * garantindo que o número exato de casas seja percorrido.
             */
            passo_baixo = 1;
            while (passo_baixo <= CASAS_CAVALO_BAIXO) {
                printf("  Baixo\n");
                passo_baixo++;
            }

            /*
             * Após descer CASAS_CAVALO_BAIXO casas, o cavalo
             * completa o L movendo-se CASAS_CAVALO_ESQUERDA
             * casa(s) para a esquerda.
             * Um segundo while aninhado garante flexibilidade
             * caso o valor da constante seja alterado.
             */
            {
                int passo_esq = 1;
                while (passo_esq <= CASAS_CAVALO_ESQUERDA) {
                    printf("  Esquerda\n");
                    passo_esq++;
                }
            }
        }
    }

    printf("\n  Cavalo completou %d saltos em L.\n\n", MOVIMENTOS_CAVALO);

    printf("============================================\n");
    printf("  Simulacao concluida! Pecas movimentadas:\n");
    printf("  Bispo  | Torre | Rainha | Cavalo\n");
    printf("============================================\n");

    return 0;
}