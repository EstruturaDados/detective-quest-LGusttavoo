#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

// ---------------------------
// Estrutura da Sala (Nó da Árvore)
// ---------------------------
typedef struct Sala {
    char nome[TAM_NOME];
    struct Sala *esq;   // Caminho para a esquerda
    struct Sala *dir;   // Caminho para a direita
} Sala;

// ---------------------------------------------------------
// Função "CriarSala"
// ---------------------------------------------------------
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));

    if (nova == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;

    return nova;
}

// ---------------------------------------------------------------------
// Função explorarSalas()
// ---------------------------------------------------------------------
void explorarSalas(Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está na sala: **%s**\n", atual->nome);

        // Se não há caminhos, a exploração acaba
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Esta sala não possui mais caminhos. Fim da exploração!\n");
            return;
        }

        printf("Escolha um caminho:\n");
        printf("(e) Ir para a sala à esquerda\n");
        printf("(d) Ir para a sala à direita\n");
        printf("(s) Sair da exploração\n");
        printf("Digite sua opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e') {
            if (atual->esq != NULL) {
                atual = atual->esq;
            } else {
                printf("Não existe sala à esquerda!\n");
            }
        } 
        else if (opcao == 'd') {
            if (atual->dir != NULL) {
                atual = atual->dir;
            } else {
                printf("Não existe sala à direita!\n");
            }
        }
        else if (opcao == 's') {
            printf("Exploração encerrada pelo jogador.\n");
            return;
        }
        else {
            printf("Opcao inválida! Tente novamente.\n");
        }
    }
}

// ---------------------------
// Função principal (main)
// ---------------------------
int main() {
    // Criando as salas da mansão (árvore binária fixa)
    Sala* hall        = criarSala("Hall de Entrada");
    Sala* sala_estar  = criarSala("Sala de Estar");
    Sala* biblioteca  = criarSala("Biblioteca");
    Sala* cozinha     = criarSala("Cozinha");
    Sala* jardim      = criarSala("Jardim");
    Sala* laboratorio = criarSala("Laboratório");

    // Montagem da árvore da mansão
    //
    //                 Hall
    //               /      \
    //        Sala Estar   Biblioteca
    //         /      \       /      \
    //   Cozinha   Jardim  Lab     (NULL)

    hall->esq = sala_estar;
    hall->dir = biblioteca;

    sala_estar->esq = cozinha;
    sala_estar->dir = jardim;

    biblioteca->esq = laboratorio;

    // Inicia a exploração
    printf("==== Detective Quest – Exploração da Mansão ====\n");
    explorarSalas(hall);

    return 0;
}
