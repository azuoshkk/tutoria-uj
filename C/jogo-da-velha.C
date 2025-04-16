#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tamanho do tabuleiro (3x3 para o Jogo da Velha)
#define TAM 3

// Declaração do menu principal
void menu();

// Declaração de variáveis globais
char tabuleiro[TAM][TAM]; // Matriz bidimensional representando o tabuleiro
char jog1[50], jog2[50];  // Vetores unidimensionais para armazenar os nomes dos jogadores
int vitorias_jog1 = 0, vitorias_jog2 = 0, empates = 0; // Contadores de resultados
char jogadorAtual = 'X'; // Indica qual jogador está na vez
char ultimoJogador = 'X'; // Armazena quem jogou por último

// Função para inicializar o tabuleiro com números de 1 a 9
void inicializarTabuleiro() {
    int num = '1';
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = num++;
        }
    }
}

// Função para exibir o tabuleiro formatado
void exibirTabuleiro() {
    system("clear");  // Limpa a tela para melhor visualização
    
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) printf("|");  // Adiciona separadores verticais
        }
        printf("\n");
        if (i < TAM - 1) printf("---+---+---\n"); // Adiciona separadores horizontais
    }
    printf("\n\n");
}

// Função para verificar se houve um vencedor
int verificarVencedor() {
    // Lista das 8 combinações possíveis para vitória (linhas, colunas e diagonais)
    int combinacoes[8][3][2] = {
        {{0,0}, {0,1}, {0,2}}, {{1,0}, {1,1}, {1,2}}, {{2,0}, {2,1}, {2,2}}, // Linhas
        {{0,0}, {1,0}, {2,0}}, {{0,1}, {1,1}, {2,1}}, {{0,2}, {1,2}, {2,2}}, // Colunas
        {{0,0}, {1,1}, {2,2}}, {{0,2}, {1,1}, {2,0}}  // Diagonais
    };
    
    // Verifica se alguma das combinações contém três símbolos iguais
    for (int i = 0; i < 8; i++) {
        if (tabuleiro[combinacoes[i][0][0]][combinacoes[i][0][1]] ==
            tabuleiro[combinacoes[i][1][0]][combinacoes[i][1][1]] &&
            tabuleiro[combinacoes[i][1][0]][combinacoes[i][1][1]] ==
            tabuleiro[combinacoes[i][2][0]][combinacoes[i][2][1]]) {
            return 1; // Retorna verdadeiro caso haja um vencedor
        }
    }
    return 0; // Retorna falso se não houver vencedor
}

// Função para verificar se ocorreu um empate
int verificarEmpate() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O') return 0; // Ainda há espaço livre
        }
    }
    return 1; // Retorna verdadeiro se o tabuleiro estiver cheio
}

// Função que controla a jogada de um jogador
void jogar() {
    int jogada;
    int linha, coluna;
    char jogadorNome[50];
    strcpy(jogadorNome, jogadorAtual == 'X' ? jog1 : jog2);

    while (1) {
        printf("%s (%c), faca sua jogada (1-9): ", jogadorNome, jogadorAtual);
        if (scanf("%d", &jogada) != 1) {
            printf("Entrada invalida! Digite um numero entre 1 e 9.\n");
            while (getchar() != '\n'); 
            continue;
        }
        
        linha = (jogada - 1) / TAM;
        coluna = (jogada - 1) % TAM;

        if (jogada < 1 || jogada > 9 || tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O') {
            printf("Posicao invalida ou ja ocupada. Tente novamente.\n");
        } else {
            tabuleiro[linha][coluna] = jogadorAtual;
            break;
        }
    }
}

// Função que gerencia a partida completa
void partida() {
    inicializarTabuleiro();
    jogadorAtual = (ultimoJogador == 'X') ? 'O' : 'X';
    ultimoJogador = jogadorAtual;

    while (1) {
        exibirTabuleiro();
        jogar();

        if (verificarVencedor()) {
            exibirTabuleiro();
            printf("%s (%c) venceu!\n", jogadorAtual == 'X' ? jog1 : jog2, jogadorAtual);
            if (jogadorAtual == 'X') vitorias_jog1++;
            else vitorias_jog2++;
            break;
        } else if (verificarEmpate()) {
            exibirTabuleiro();
            printf("Empate!\n");
            empates++;
            break;
        }
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    int opcao;
    while (1) {
        printf("\nDeseja jogar novamente?\n1 - Sim\n2 - Voltar ao menu\nEscolha: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, escolha 1 ou 2.\n");
            while (getchar() != '\n');
            continue;
        }
        if (opcao == 1) {
            partida();
            break;
        } else if (opcao == 2) {
            menu();
            break;
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

// Exibe as estatísticas das partidas
void estatisticas() {
    printf("\n==== Estatisticas ====\n");
    printf("%s (X) - Vitorias: %d\n", jog1, vitorias_jog1);
    printf("%s (O) - Vitorias: %d\n", jog2, vitorias_jog2);
    printf("Empates: %d\n", empates);
    printf("Total de jogos: %d\n\n", vitorias_jog1 + vitorias_jog2 + empates);
    printf("Pressione qualquer tecla para voltar ao menu...\n");
    getchar(); getchar();
}

// Função que exibe o menu principal do jogo
void menu() {
    int opcao;
    while (1) {
        system("clear");
        printf("********************************\n"
               "*        JOGO DA VELHA         *\n"
               "********************************\n"
               "*    1 - JOGAR                 *\n"
               "*    2 - ESTATISTICAS          *\n"
               "*    3 - SAIR                  *\n"
               "********************************\n\n"
               "Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, escolha uma opcao valida.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (opcao) {
            case 1: partida(); 
                break;
            case 2: estatisticas(); 
                break;
            case 3:
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }
}

// Função principal do programa
int main() {
    printf("Jogador(a) 1, digite seu nome: ");
    scanf("%s", jog1);
    printf("Jogador(a) 2, digite seu nome: ");
    scanf("%s", jog2);
    menu();
    return 0;
}
