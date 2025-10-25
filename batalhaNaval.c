#include <stdio.h>
#include <stdlib.h> // Necessario para a funcao abs() usada no Octaedro

//====================================================================
// DEFINICOES GLOBAIS (CONSTANTES)
//====================================================================
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade (ex: 5x5)
#define AGUA 0
#define NAVIO 3
#define EFEITO_HABILIDADE 5 // Marcador para area afetada no tabuleiro principal
#define MARCADOR_HABILIDADE 1 // Marcador de area afetada DENTRO da matriz de habilidade

int main() {

    //====================================================================
    // DECLARACAO DE VARIAVEIS
    //====================================================================

    // Tabuleiro principal do jogo
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Matrizes para as areas de efeito das habilidades
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Coordenadas dos navios 
    int linha_navio_horizontal = 1;
    int coluna_navio_horizontal = 2;
    int linha_navio_vertical = 4;
    int coluna_navio_vertical = 7;
    // Adicionando coordenadas para mais 2 navios 
    int linha_navio_3 = 8; // Exemplo: um horizontal
    int coluna_navio_3 = 1;
    int linha_navio_4 = 1; // Exemplo: um vertical
    int coluna_navio_4 = 5;


    // Coordenadas de origem (centro) para cada habilidade no tabuleiro principal
    int origem_linha_cone = 4;    // Centro do Cone em [4, 4]
    int origem_coluna_cone = 4;
    int origem_linha_cruz = 2;    // Centro da Cruz em [2, 7]
    int origem_coluna_cruz = 7;
    int origem_linha_octaedro = 7; // Centro do Octaedro em [7, 2]
    int origem_coluna_octaedro = 2;


    int i, j; // Variaveis pro for

    // Flag para checar se a posicao e valida (sobreposicao/limite)
    int posicao_invalida;

    // Tamanho do navio (fixo em 3)
    int tamanho_do_navio = 3;

    // Centro da matriz de habilidade (para calculos de forma)
    int centro_habilidade = TAMANHO_HABILIDADE / 2; // Para 5x5, centro = 2

    //====================================================================
    // APRESENTANDO O JOGO
    //====================================================================

    printf("*** Bem vindos a Batalha Naval (Nivel Mestre) ***\n");
    printf("==================================================\n");
    printf("Instrucoes: Tabuleiro %dx%d. Navios posicionados.\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);
    printf("Visualizacao das areas de efeito das habilidades Cone, Cruz e Octaedro.\n\n");

    printf("--- COORDENADAS DOS NAVIOS ---\n");
    printf("Navio H1: [%d, %d] | Navio V1: [%d, %d]\n", linha_navio_horizontal, coluna_navio_horizontal, linha_navio_vertical, coluna_navio_vertical);
    printf("Navio H2: [%d, %d] | Navio V2: [%d, %d]\n", linha_navio_3, coluna_navio_3, linha_navio_4, coluna_navio_4);
    printf("----------------------------\n");
    printf("--- ORIGEM DAS HABILIDADES ---\n");
    printf("Cone: [%d, %d] | Cruz: [%d, %d] | Octaedro: [%d, %d]\n", origem_linha_cone, origem_coluna_cone, origem_linha_cruz, origem_coluna_cruz, origem_linha_octaedro, origem_coluna_octaedro);
    printf("----------------------------\n\n");


    //====================================================================
    // 1. INICIALIZACAO DO TABULEIRO (0 = água)
    //====================================================================
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Usando a constante AGUA
        }
    }

    //====================================================================
    // 2. POSICIONAMENTO E VALIDAÇÃO DOS NAVIOS (Exemplo com 4 navios)
    //====================================================================

    // --- NAVIO HORIZONTAL 1 ---
    if (coluna_navio_horizontal + tamanho_do_navio <= TAMANHO_TABULEIRO) { // checagem de limite
        posicao_invalida = 0;
        for (j = 0; j < tamanho_do_navio; j++) {
            if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] != AGUA) {
                posicao_invalida = 1; break;
            }
        }
        if (posicao_invalida == 0) {
            for (j = 0; j < tamanho_do_navio; j++) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] = NAVIO;
            }
            printf("Navio Horizontal 1 posicionado.\n");
        } else { printf("ERRO: Sobreposicao Navio Horizontal 1.\n"); }
    } else { printf("ERRO: Limite Navio Horizontal 1.\n"); }

    // --- NAVIO VERTICAL 1 ---
    if (linha_navio_vertical + tamanho_do_navio <= TAMANHO_TABULEIRO) { //  checagem de limite
        posicao_invalida = 0;
        for (i = 0; i < tamanho_do_navio; i++) {
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] != AGUA) {
                posicao_invalida = 1; break;
            }
        }
        if (posicao_invalida == 0) {
            for (i = 0; i < tamanho_do_navio; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = NAVIO;
            }
            printf("Navio Vertical 1 posicionado.\n");
        } else { printf("ERRO: Sobreposicao Navio Vertical 1.\n"); }
    } else { printf("ERRO: Limite Navio Vertical 1.\n"); }

     // --- NAVIO HORIZONTAL 2 (Exemplo) ---
    if (coluna_navio_3 + tamanho_do_navio <= TAMANHO_TABULEIRO) {
        posicao_invalida = 0;
        for (j = 0; j < tamanho_do_navio; j++) {
            if (tabuleiro[linha_navio_3][coluna_navio_3 + j] != AGUA) {
                posicao_invalida = 1; break;
            }
        }
        if (posicao_invalida == 0) {
            for (j = 0; j < tamanho_do_navio; j++) {
                tabuleiro[linha_navio_3][coluna_navio_3 + j] = NAVIO;
            }
            printf("Navio Horizontal 2 posicionado.\n");
        } else { printf("ERRO: Sobreposicao Navio Horizontal 2.\n"); }
    } else { printf("ERRO: Limite Navio Horizontal 2.\n"); }

    // --- NAVIO VERTICAL 2 (Exemplo) ---
    if (linha_navio_4 + tamanho_do_navio <= TAMANHO_TABULEIRO) {
        posicao_invalida = 0;
        for (i = 0; i < tamanho_do_navio; i++) {
            if (tabuleiro[linha_navio_4 + i][coluna_navio_4] != AGUA) {
                posicao_invalida = 1; break;
            }
        }
        if (posicao_invalida == 0) {
            for (i = 0; i < tamanho_do_navio; i++) {
                tabuleiro[linha_navio_4 + i][coluna_navio_4] = NAVIO;
            }
            printf("Navio Vertical 2 posicionado.\n");
        } else { printf("ERRO: Sobreposicao Navio Vertical 2.\n"); }
    } else { printf("ERRO: Limite Navio Vertical 2.\n"); }

    printf("\n"); // Linha em branco para separar

    //====================================================================
    // 3. CRIACAO DAS MATRIZES DE HABILIDADE (DINAMICA COM LOOPS/IFS)
    //====================================================================

    // --- INICIALIZANDO MATRIZES COM 0 ---
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_cone[i][j] = 0;
            habilidade_cruz[i][j] = 0;
            habilidade_octaedro[i][j] = 0;
        }
    }

    // --- FORMA DO CONE ---
    // O cone comeca no centro da linha superior (i=0, j=centro) e se expande
    // Para cada linha 'i', a area afetada vai de 'centro-i' ate 'centro+i' na coluna 'j'
    printf("Gerando matriz Cone %dx%d...\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Condicao para estar dentro do cone (triangulo invertido)
            if (j >= centro_habilidade - i && j <= centro_habilidade + i) {
                 // Verificando se a linha i esta dentro dos limites da matriz para o cone descendente
                 if (i <= centro_habilidade) { // O cone so vai ate a linha central neste exemplo 
                    habilidade_cone[i][j] = MARCADOR_HABILIDADE;
                 }
            }
        }
    }

    // --- GERANDO FORMA DA CRUZ ---
    // A cruz afeta toda a linha central (i=centro) e toda a coluna central (j=centro)
    printf("Gerando matriz Cruz %dx%d...\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Condicao para estar na linha ou coluna central
            if (i == centro_habilidade || j == centro_habilidade) {
                habilidade_cruz[i][j] = MARCADOR_HABILIDADE;
            }
        }
    }

    // --- GERANDO FORMA DO OCTAEDRO (LOSANGO) ---
    printf("Gerando matriz Octaedro %dx%d...\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
     for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Condicao da distancia de Manhattan
            if (abs(i - centro_habilidade) + abs(j - centro_habilidade) <= centro_habilidade) {
                habilidade_octaedro[i][j] = MARCADOR_HABILIDADE;
            }
        }
    }
    printf("\n");



    //====================================================================
    // 4. INTEGRACAO DAS HABILIDADES AO TABULEIRO (SOBREPOSICAO)
    //====================================================================
    int tab_linha, tab_coluna; // Variaveis temporarias para coordenadas do tabuleiro
    int hab_i, hab_j; // Variaveis para iterar sobre a matriz de habilidade

    printf("Aplicando efeitos das habilidades no tabuleiro...\n");

    // --- APLICANDO CONE ---
    for (hab_i = 0; hab_i < TAMANHO_HABILIDADE; hab_i++) {
        for (hab_j = 0; hab_j < TAMANHO_HABILIDADE; hab_j++) {
            // Se a posicao na matriz de habilidade esta marcada (== 1)
            if (habilidade_cone[hab_i][hab_j] == MARCADOR_HABILIDADE) {
                // Calcula a posicao correspondente no tabuleiro principal
                // O calculo considera o centro da matriz de habilidade
                tab_linha = origem_linha_cone - centro_habilidade + hab_i;
                tab_coluna = origem_coluna_cone - centro_habilidade + hab_j;

                // VALIDACAO DE LIMITES: Verifica se a posicao calculada esta DENTRO do tabuleiro
                if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                    tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                    // Marca a posicao no tabuleiro principal com o efeito
                    // (Pode sobrescrever AGUA ou NAVIO, apenas para visualizacao)
                     if (tabuleiro[tab_linha][tab_coluna] == AGUA) { // Opcional: Marcar apenas sobre agua
                         tabuleiro[tab_linha][tab_coluna] = EFEITO_HABILIDADE;
                     }
                }
            }
        }
    }
     printf("- Habilidade Cone aplicada.\n");

    // --- APLICANDO CRUZ ---
    for (hab_i = 0; hab_i < TAMANHO_HABILIDADE; hab_i++) {
        for (hab_j = 0; hab_j < TAMANHO_HABILIDADE; hab_j++) {
            if (habilidade_cruz[hab_i][hab_j] == MARCADOR_HABILIDADE) {
                tab_linha = origem_linha_cruz - centro_habilidade + hab_i;
                tab_coluna = origem_coluna_cruz - centro_habilidade + hab_j;

                if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                    tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                     if (tabuleiro[tab_linha][tab_coluna] == AGUA) {
                         tabuleiro[tab_linha][tab_coluna] = EFEITO_HABILIDADE;
                     }
                }
            }
        }
    }
    printf("- Habilidade Cruz aplicada.\n");

     // --- APLICANDO OCTAEDRO ---
    for (hab_i = 0; hab_i < TAMANHO_HABILIDADE; hab_i++) {
        for (hab_j = 0; hab_j < TAMANHO_HABILIDADE; hab_j++) {
            if (habilidade_octaedro[hab_i][hab_j] == MARCADOR_HABILIDADE) {
                tab_linha = origem_linha_octaedro - centro_habilidade + hab_i;
                tab_coluna = origem_coluna_octaedro - centro_habilidade + hab_j;

                if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                    tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                     if (tabuleiro[tab_linha][tab_coluna] == AGUA) {
                         tabuleiro[tab_linha][tab_coluna] = EFEITO_HABILIDADE;
                     }
                }
            }
        }
    }
     printf("- Habilidade Octaedro aplicada.\n\n");

    //====================================================================
    // 5. EXIBIÇÃO FINAL DO TABULEIRO COM NAVIOS E HABILIDADES
    //====================================================================

    printf("------- TABULEIRO FINAL (%d=Agua | %d=Navio | %d=Efeito Habilidade) -------\n", AGUA, NAVIO, EFEITO_HABILIDADE);

    //  letras das Colunas (A a J)
    printf("   A B C D E F G H I J\n");
     printf("  ---------------------\n");


    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Imprime o numero da Linha (1 a 10) - usei i+1 para ficar mais intuitivo
        printf("%2d|", i + 1);

        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            // if/else if para imprimir o caractere correto
            if (tabuleiro[i][j] == AGUA) {
                printf(" %d", AGUA); // Imprime AGUA (0)
            } else if (tabuleiro[i][j] == NAVIO) {
                printf(" %d", NAVIO); // Imprime NAVIO (3)
            } else if (tabuleiro[i][j] == EFEITO_HABILIDADE) {
                printf(" %d", EFEITO_HABILIDADE); // Imprime EFEITO (5)
            } else {
                 printf(" ?"); // Caso inesperado
            }
        }
        printf("\n"); // Quebra de linha ao final de cada linha do tabuleiro
    }
    printf("------------------------------------------------\n");


    //====================================================================
    // FIM DO PROGRAMA
    //====================================================================
    return 0;
}