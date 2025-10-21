#include <stdio.h>

int main() {
    
    // Aqui declarei variais pro tabuleiro e coordenadas
    int tabuleiro[10][10];
    
    // Variaveis para as coordenadas, longas e descritivas
    int linha_navio_horizontal; 
    int coluna_navio_horizontal; 
    int linha_navio_vertical; 
    int coluna_navio_vertical; 
    
    // NOVAS VARIAVEIS PARA OS NAVIOS DIAGONAIS
    int linha_navio_diag_desc;  // Navio Diagonal Descendente (Linha e Coluna aumentam)
    int coluna_navio_diag_desc; 
    int linha_navio_diag_asc;   // Navio Diagonal Ascendente (Linha aumenta, Coluna diminui)
    int coluna_navio_diag_asc;  
    
    int i, j; // Variaveis pro for
    
    // Flag para checar se a posicao e valida (se deu sobreposicao ou limite)
    int posicao_invalida; 
    
    // tamanho do navio, fixo em 3
    int tamanho_do_navio = 3; 

    //====================================================================
    // APRESENTANDO O JOGO E DEFININDO AS COORDENADAS
    //====================================================================
    
    printf("***Bem vindos a Batalha Naval (Nivel Aventureiro)***\n");
    printf("==================================================\n");
    printf("Instrucoes: Tabuleiro 10x10. Quatro navios de tamanho 3 serao posicionados.\n\n");
    
    // Coordenadas dos 4 navios (escolhidas para nao sobrepor)
    
    // Navios 1 e 2 (Horizontal e Vertical)
    linha_navio_horizontal = 0;      
    coluna_navio_horizontal = 0;     
    
    linha_navio_vertical = 7;      
    coluna_navio_vertical = 9;     
    
    // Navios 3 e 4 (Diagonais)
    linha_navio_diag_desc = 2;      // Comeca em [2][2]
    coluna_navio_diag_desc = 2;     // Ocupa [2][2], [3][3], [4][4]
    
    linha_navio_diag_asc = 5;       // Comeca em [5][7]
    coluna_navio_diag_asc = 7;      // Ocupa [5][7], [6][6], [7][5] (Linha Aumenta, Coluna Diminui)

    
    printf("---COORDENADAS ESCOLHIDAS---\n");
    printf("Navio H: [%d, %d] | Navio V: [%d, %d]\n", linha_navio_horizontal, coluna_navio_horizontal, linha_navio_vertical, coluna_navio_vertical);
    printf("Navio D-Desc: [%d, %d] | Navio D-Asc: [%d, %d]\n", linha_navio_diag_desc, coluna_navio_diag_desc, linha_navio_diag_asc, coluna_navio_diag_asc);
    printf("----------------------------\n");
    
    
    //====================================================================
    // 1. INICIALIZACAO DO TABULEIRO 0 = água
    //====================================================================
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 e a agua
        }
    }


    //====================================================================
    // 2. POSICIONAMENTO E VALIDAÇÃO DOS NAVIOS HORIZONTAL E VERTICAL 
    //====================================================================
    
    // Posicionamento Horizontal (Linha Fixa, Coluna Variável)
    if (coluna_navio_horizontal + tamanho_do_navio - 1 < 10) {
        posicao_invalida = 0;
        for (j = 0; j < tamanho_do_navio; j++) {
            // Checa Limites (ja checado acima) e Sobreposicao (checa se e diferente de 0)
            if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] != 0) { 
                posicao_invalida = 1; break;
            }
        }
        if (posicao_invalida == 0) {
            for (j = 0; j < tamanho_do_navio; j++) {
                tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] = 3; 
            }
            printf("Navio Horizontal posicionado com sucesso!\n");
        } else {
            printf("ERRO: Navio Horizontal invalido (Sobreposicao/Limite).\n");
        }
    } else {
        printf("ERRO: Navio Horizontal fora dos limites (Coluna).\n");
    }

    // Posicionamento Vertical (Coluna Fixa, Linha Variável)
    if (linha_navio_vertical + tamanho_do_navio - 1 < 10) {
        posicao_invalida = 0;
        for (i = 0; i < tamanho_do_navio; i++) {
            // Checa Sobreposicao
            if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] != 0) {
                posicao_invalida = 1; break; 
            }
        }
        if (posicao_invalida == 0) {
            for (i = 0; i < tamanho_do_navio; i++) {
                tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3; 
            }
            printf("Navio Vertical posicionado com sucesso!\n");
        } else {
            printf("ERRO: Navio Vertical invalido (Sobreposicao/Limite).\n");
        }
    } else {
        printf("ERRO: Navio Vertical fora dos limites (Linha).\n");
    }


    //====================================================================
    // 3. POSICIONAMENTO E VALIDAÇÃO DOS NOVOS NAVIOS DIAGONAIS
    //====================================================================

    // Navio Diagonal DESCENDENTE (Linha e Coluna AUMENTAM)
    // VALIDACAO: Checa se a linha final E a coluna final estao dentro do limite (9)
    if (linha_navio_diag_desc + tamanho_do_navio - 1 < 10 && 
        coluna_navio_diag_desc + tamanho_do_navio - 1 < 10) {
        
        posicao_invalida = 0;
        for (i = 0; i < tamanho_do_navio; i++) {
            // Checa Sobreposicao: Linha e Coluna aumentam juntas (i)
            if (tabuleiro[linha_navio_diag_desc + i][coluna_navio_diag_desc + i] != 0) { 
                posicao_invalida = 1; break;
            }
        }
        if (posicao_invalida == 0) {
            // Posiciona o Navio: Linha e Coluna aumentam juntas
            for (i = 0; i < tamanho_do_navio; i++) {
                tabuleiro[linha_navio_diag_desc + i][coluna_navio_diag_desc + i] = 3; 
            }
            printf("Navio Diagonal Descendente posicionado!\n");
        } else {
            printf("ERRO: Navio Diagonal Descendente invalido (Sobreposicao).\n");
        }
    } else {
        printf("ERRO: Navio Diagonal Descendente fora dos limites.\n");
    }


    // Navio Diagonal ASCENDENTE (Linha AUMENTA, Coluna DIMINUI)
    // VALIDACAO: Checa se a linha final E a coluna final estao dentro do limite (0 a 9)
    if (linha_navio_diag_asc + tamanho_do_navio - 1 < 10 && 
        coluna_navio_diag_asc - tamanho_do_navio + 1 >= 0) { // Coluna nao pode ser negativa
        
        posicao_invalida = 0;
        for (i = 0; i < tamanho_do_navio; i++) {
            // Checa Sobreposicao: Linha aumenta (i), Coluna diminui (i)
            if (tabuleiro[linha_navio_diag_asc + i][coluna_navio_diag_asc - i] != 0) { 
                posicao_invalida = 1; break;
            }
        }
        if (posicao_invalida == 0) {
            // Posiciona o Navio: Linha aumenta, Coluna diminui
            for (i = 0; i < tamanho_do_navio; i++) {
                tabuleiro[linha_navio_diag_asc + i][coluna_navio_diag_asc - i] = 3; 
            }
            printf("Navio Diagonal Ascendente posicionado!\n");
        } else {
            printf("ERRO: Navio Diagonal Ascendente invalido (Sobreposicao).\n");
        }
    } else {
        printf("ERRO: Navio Diagonal Ascendente fora dos limites.\n");
    }


    //====================================================================
    // 4. EXIBIÇÃO FINAL DO TABULEIRO (10x10)
    //====================================================================

    printf("\n-------TABULEIRO FINAL (0=Agua | 3=Navio)-------\n");

    // Imprime o cabecalho das Colunas
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    printf("  ---------------------\n"); 

    for (i = 0; i < 10; i++) { 
        // Imprime o indice da Linha
        printf("%d |", i); 
        
        for (j = 0; j < 10; j++) { 
            // Imprime o valor da posicao
            printf(" %d", tabuleiro[i][j]); 
        }
        printf("\n"); 
    }
    printf("------------------------------------------------\n");

    //FIM DO PROGRAMA
    return 0;
}