/*
 * ============================================================
 * MateCheck — Desafio: Movimentação de Peças de Xadrez
 * Nível Novato    : Bispo (FOR), Torre (WHILE), Rainha (DO-WHILE)
 * Nível Aventureiro: Cavalo em L com loops aninhados FOR + WHILE
 * Nível Mestre    : Bispo/Torre/Rainha com recursão;
 *                   Cavalo com loops aninhados, variáveis múltiplas,
 *                   continue e break.
 * ============================================================
 *
 * Peças — Nível Novato:
 *   - Bispo : 5 casas na diagonal superior direita  → FOR
 *   - Torre : 5 casas para a direita                → WHILE
 *   - Rainha: 8 casas para a esquerda               → DO-WHILE
 *
 * Peças — Nível Aventureiro:
 *   - Cavalo: 5 saltos em L (Baixo + Esquerda)
 *             loops aninhados: FOR externo + WHILE interno
 *
 * Peças — Nível Mestre:
 *   - Bispo : 5 casas diagonal direita-cima  → recursão + loop aninhado
 *   - Torre : 5 casas para a direita         → recursão
 *   - Rainha: 8 casas para a esquerda        → recursão
 *   - Cavalo: 1 L para cima à direita        → loops aninhados com
 *             variáveis múltiplas, continue e break
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
/*  Nível Mestre — constantes adicionais para o Cavalo                */
/* ------------------------------------------------------------------ */

/* Passos verticais do L do Cavalo Mestre (sobe 2 casas) */
#define MESTRE_CAVALO_CIMA    2

/* Passos horizontais do L do Cavalo Mestre (vai 1 casa à direita) */
#define MESTRE_CAVALO_DIREITA 1

/* ------------------------------------------------------------------ */
/*  Nível Mestre — funções recursivas                                  */
/* ------------------------------------------------------------------ */

/*
 * mestre_bispo()
 *
 * Move o Bispo recursivamente na diagonal superior direita.
 * Cada chamada representa UMA casa diagonal, composta por dois
 * passos elementares exibidos via loop aninhado interno:
 *   - loop vertical   : imprime "Cima"
 *   - loop horizontal : imprime "Direita"
 *
 * Parâmetros:
 *   casa_atual   → número da casa sendo processada (começa em 1)
 *   total_casas  → limite máximo de casas (base da recursão)
 *
 * Caso base: casa_atual > total_casas → para a recursão.
 * Passo recursivo: processa a casa atual e chama a si mesmo
 *                  para a casa seguinte.
 */
void mestre_bispo(int casa_atual, int total_casas) {
    int v, h; /* contadores dos loops aninhados internos */

    /* Caso base: todas as casas já foram percorridas */
    if (casa_atual > total_casas) {
        return;
    }

    printf("  Casa %d:\n", casa_atual);

    /*
     * Loop aninhado obrigatório dentro da função recursiva.
     *
     * Loop externo (v): representa o componente VERTICAL (Cima).
     *   Executa 1 vez por casa diagonal — o Bispo sobe 1 passo.
     *
     * Loop interno (h): representa o componente HORIZONTAL (Direita).
     *   Executa 1 vez por casa diagonal — o Bispo avança 1 passo.
     *
     * A separação em dois loops aninhados torna explícita a
     * decomposição do movimento diagonal em eixos independentes.
     */
    for (v = 0; v < 1; v++) {          /* loop externo: eixo vertical   */
        for (h = 0; h < 1; h++) {      /* loop interno: eixo horizontal  */
            printf("    Cima\n");
            printf("    Direita\n");
        }
    }

    /* Chamada recursiva: processa a próxima casa */
    mestre_bispo(casa_atual + 1, total_casas);
}

/*
 * mestre_torre()
 *
 * Move a Torre recursivamente para a direita.
 *
 * Parâmetros:
 *   casa_atual   → número da casa atual
 *   total_casas  → limite máximo
 *
 * Caso base: casa_atual > total_casas → encerra a recursão.
 */
void mestre_torre(int casa_atual, int total_casas) {

    /* Caso base: movimento concluído */
    if (casa_atual > total_casas) {
        return;
    }

    printf("  Casa %d -> Direita\n", casa_atual);

    /* Chamada recursiva para a próxima casa */
    mestre_torre(casa_atual + 1, total_casas);
}

/*
 * mestre_rainha()
 *
 * Move a Rainha recursivamente para a esquerda.
 *
 * Parâmetros:
 *   casa_atual   → número da casa atual
 *   total_casas  → limite máximo
 *
 * Caso base: casa_atual > total_casas → encerra a recursão.
 */
void mestre_rainha(int casa_atual, int total_casas) {

    /* Caso base: movimento concluído */
    if (casa_atual > total_casas) {
        return;
    }

    printf("  Casa %d -> Esquerda\n", casa_atual);

    /* Chamada recursiva para a próxima casa */
    mestre_rainha(casa_atual + 1, total_casas);
}

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


    /* ============================================================
     * =====================  NÍVEL MESTRE  =======================
     * ============================================================ */

    printf("\n");
    printf("############################################\n");
    printf("#           NIVEL MESTRE                   #\n");
    printf("############################################\n\n");

    /* ----------------------------------------------------------
     * BISPO MESTRE — recursão + loops aninhados obrigatórios
     *
     * A função mestre_bispo() chama a si mesma para cada casa
     * diagonal. Dentro de cada chamada, dois loops aninhados
     * decompõem o movimento em Cima (eixo vertical) e
     * Direita (eixo horizontal).
     * ---------------------------------------------------------- */
    printf("============================================\n");
    printf("  [MESTRE] BISPO — %d casas diagonal direita-cima\n", CASAS_BISPO);
    printf("  (recursao + loops aninhados obrigatorios)\n");
    printf("============================================\n");

    mestre_bispo(1, CASAS_BISPO);  /* inicia na casa 1 */

    printf("  Bispo (Mestre) moveu %d casas na diagonal.\n\n", CASAS_BISPO);

    /* ----------------------------------------------------------
     * TORRE MESTRE — recursão pura
     * ---------------------------------------------------------- */
    printf("============================================\n");
    printf("  [MESTRE] TORRE — %d casas para a direita\n", CASAS_TORRE);
    printf("  (recursao)\n");
    printf("============================================\n");

    mestre_torre(1, CASAS_TORRE);

    printf("  Torre (Mestre) moveu %d casas para a direita.\n\n", CASAS_TORRE);

    /* ----------------------------------------------------------
     * RAINHA MESTRE — recursão pura
     * ---------------------------------------------------------- */
    printf("============================================\n");
    printf("  [MESTRE] RAINHA — %d casas para a esquerda\n", CASAS_RAINHA);
    printf("  (recursao)\n");
    printf("============================================\n");

    mestre_rainha(1, CASAS_RAINHA);

    printf("  Rainha (Mestre) moveu %d casas para a esquerda.\n\n", CASAS_RAINHA);

    /* ----------------------------------------------------------
     * CAVALO MESTRE — 1 salto em L para cima à direita
     *
     * Movimento: 2 casas para Cima + 1 casa para Direita.
     *
     * Técnicas obrigatórias neste nível:
     *   - Loops aninhados
     *   - Variáveis múltiplas no cabeçalho do for
     *   - Condições múltiplas (&&)
     *   - continue : pula passos já concluídos na fase anterior
     *   - break    : interrompe o loop externo ao terminar o L
     *
     * Lógica:
     *   O loop externo usa DUAS variáveis: eixo (0=vertical,
     *   1=horizontal) e passo. O loop interno percorre os
     *   passos de cada eixo.
     *
     *   - continue é usado para ignorar iterações do eixo
     *     horizontal enquanto ainda há passos verticais pendentes.
     *   - break é usado para encerrar o loop externo assim que
     *     o L está completo (ambos os eixos concluídos).
     * ---------------------------------------------------------- */
    printf("============================================\n");
    printf("  [MESTRE] CAVALO — 1 salto em L (Cima + Direita)\n");
    printf("  Movimento: %d casa(s) Cima + %d casa(s) Direita\n",
           MESTRE_CAVALO_CIMA, MESTRE_CAVALO_DIREITA);
    printf("  (loops aninhados, variaveis multiplas,\n");
    printf("   condicoes multiplas, continue, break)\n");
    printf("============================================\n");

    {
        /*
         * eixo  : 0 = fase vertical (Cima), 1 = fase horizontal (Direita)
         * passo : posição dentro do eixo atual (começa em 1)
         * total : quantos passos o eixo atual exige
         * concluido_vertical   : flag — fase Cima encerrada
         * concluido_horizontal : flag — fase Direita encerrada
         */
        int eixo, passo, total;
        int concluido_vertical   = 0;
        int concluido_horizontal = 0;

        /*
         * Loop EXTERNO com duas variáveis no cabeçalho:
         *   eixo  → qual fase do L está sendo processada
         *   passo → reinicia em 1 a cada mudança de eixo
         *
         * Condição múltipla: continua enquanto eixo <= 1
         * E o L ainda não foi completamente concluído.
         */
        for (eixo = 0, passo = 1;
             eixo <= 1 && !(concluido_vertical && concluido_horizontal);
             eixo++, passo = 1) {

            /* Define quantos passos este eixo exige */
            if (eixo == 0) {
                total = MESTRE_CAVALO_CIMA;    /* fase vertical */
            } else {
                total = MESTRE_CAVALO_DIREITA; /* fase horizontal */
            }

            /*
             * Loop INTERNO — percorre os passos do eixo atual.
             *
             * continue: se a fase vertical já terminou e estamos
             *           no eixo 0 novamente por algum motivo,
             *           pulamos com continue.
             *
             * break   : quando todos os passos do eixo atual
             *           foram concluídos, encerramos o loop interno.
             */
            while (passo <= total) {

                /* continue: pula re-entrada desnecessária no eixo 0 */
                if (eixo == 0 && concluido_vertical) {
                    continue; /* não deveria ocorrer, mas protege o fluxo */
                }

                /* Imprime a direção do passo atual */
                if (eixo == 0) {
                    printf("  Passo vertical   %d -> Cima\n", passo);
                } else {
                    printf("  Passo horizontal %d -> Direita\n", passo);
                }

                passo++;

                /* break: eixo concluído — sai do loop interno */
                if (passo > total) {
                    if (eixo == 0) concluido_vertical   = 1;
                    else           concluido_horizontal = 1;
                    break;
                }
            }
        }
    }

    printf("  Cavalo (Mestre) completou o salto em L.\n\n");

    printf("############################################\n");
    printf("#        SIMULACAO CONCLUIDA!              #\n");
    printf("#  Novato     : Bispo | Torre | Rainha     #\n");
    printf("#  Aventureiro: Cavalo (loops aninhados)   #\n");
    printf("#  Mestre     : Bispo | Torre | Rainha     #\n");
    printf("#              | Cavalo (recursao/break)   #\n");
    printf("############################################\n");

    return 0;
}