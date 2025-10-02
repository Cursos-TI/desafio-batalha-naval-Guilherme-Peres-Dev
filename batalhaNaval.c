#include <stdio.h>

int main() {
    
    // Aqui declarei variais pro tabuleiro e coordenadas
    int tabuleiro[10][10];
    
    // Variaveis para as coordenada
    int linha_navio_horizontal; 
    int coluna_navio_horizontal; 
    int linha_navio_vertical; 
    int coluna_navio_vertical; 
    
    int i, j; // Variaveis pro for
    
    // aq vejo se aposicao ta invalida
    int posicao_invalida; 
    
    // tamanho do navio 
    int tamanho_do_navio = 3; 

    //====================================================================
    // APRESENTANDO O JOGO E DEFININDO AS COORDENADAS
    //====================================================================
    
    printf("***Bem vindos a Batalha Naval ***\n");
    printf("==================================================\n");
    printf("Instrucoes: Tabuleiro 10x10. Dois navios de tamanho 3 serao posicionados.\n");
    
    // Coordenadas escolhidas para o desafio:
    linha_navio_horizontal = 1;      
    coluna_navio_horizontal = 2;     
    
    linha_navio_vertical = 4;      
    coluna_navio_vertical = 7;     
    
    printf("---COORDENADAS ESCOLHIDAS---\n");
    printf("Navio Horizontal: Linha %d, Coluna %d\n", linha_navio_horizontal, coluna_navio_horizontal);
    printf("Navio Vertical: Linha %d, Coluna %d\n", linha_navio_vertical, coluna_navio_vertical);
    printf("----------------------------\n");
    
    
    //====================================================================
    // 1. INICIALIZACAO DO TABULEIRO 0 = água
    //====================================================================
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 á a agua
        }
    }


    //====================================================================
    // 2. POSICIONAMENTO E VALIDAÇÃO DA POSICAO HORIZONTAL
    //====================================================================

    // VALIDACAO 1: Checa se o navio horizontal cabe 
    if (coluna_navio_horizontal + tamanho_do_navio - 1 < 10) {
        
        // VALIDACAO 2: Checa se a posicao é valida
        posicao_invalida = 0;
        for (j = 0; j < tamanho_do_navio; j++) {
            // Se a posicao ja tem um navio (3), ela fica invalida
            if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] != 0) { 
                posicao_invalida = 1;
                break; // aqui ela deu sobreposicao
            }
        }

        // Padrao de validacao com if/else
        if (posicao_invalida == 0) {
            // Se ta OK, posiciona o navio na horizontal
            for (j = 0; j < tamanho_do_navio; j++) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] = 3; // 3 e o navio
            }
            printf("Navio Horizontal posicionado com sucesso!\n");
        } else {
            printf("ERRO: Posição invalida do navio horizontal.\n");
        }

    } else {
        printf("ERRO: Navio Horizontal sai dos limites do tabuleiro! Posicao invalida.\n");
    }

    //====================================================================
    // 3. POSICIONAMENTO E VALIDAÇÃO DO NAVIO VERTICAL
    //====================================================================

    // VALIDACAO 1: verifica se o navio vertical cabe (linha final deve ser <= 9)
    if (linha_navio_vertical + tamanho_do_navio - 1 < 10) {
        
        // VALIDACAO 2: verifica se sobrepoe (aqui ja vejo o navio horizontal tb)
        posicao_invalida = 0;
        for (i = 0; i < tamanho_do_navio; i++) {
            // Se a posicao ja tem um navio (3)
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] != 0) {
                posicao_invalida = 1;
                break; 
            }
        }

        // Padrao de validacao 
        if (posicao_invalida == 0) {
            // Se ta OK, posiciona o navio na vertical
            for (i = 0; i < tamanho_do_navio; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3; // 3 e o navio
            }
            printf("Navio Vertical posicionado com sucesso!\n");
        } else {
            printf("ERRO: Navio Vertical se sobrepoe! Posicao invalida.\n");
        }

    } else {
        printf("ERRO: Navio Vertical sai dos limites do tabuleiro! Posicao invalida.\n");
    }


    //====================================================================
    // 4. EXIBIÇÃO FINAL DO TABULEIRO (NOVO FORMATO VISUAL)
    //====================================================================

    printf("\nTABULEIRO BATALHA NAVAL\n");

    // Imprime as letras das Colunas (A B C D E F G H I J)
    printf("  A B C D E F G H I J\n"); 

    for (i = 0; i < 10; i++) {
        // Imprime o numero da Linha (1, 2, 3... 10)
        printf("%2d", i + 1); 
        
        for (j = 0; j < 10; j++) {
            // Usa a logica de if/else para imprimir . (ponto) para ÁGUA (0) e 3 para NAVIO
            if (tabuleiro[i][j] == 0) {
                printf(" 0"); // Imprime o ponto com um espaço antes
            } else {
                printf(" 3"); // Imprime o 3 com um espaço antes
            }
        }
        printf("\n"); // Quebra de linha
    }
    printf("------------------------------------------------\n");
    return 0;
}