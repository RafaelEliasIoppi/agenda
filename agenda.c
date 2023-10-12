#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char nome[50];
    char telefone[15];
    char celular[15];
    char endereco[100];
    char aniversario[20];
} Contato;

int main() {
    Contato* agenda[MAX_CONTACTS];
    int opcao;
    int totalContatos = 0;

    for (int i = 0; i < MAX_CONTACTS; i++) {
        agenda[i] = NULL;
    }

    while (1) {
        printf("Opções:\n");
        printf("1 - Inserir um contato\n");
        printf("2 - Visualizar os dados de uma posição\n");
        printf("3 - Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        if (opcao == 1) {
            if (totalContatos < MAX_CONTACTS) {
                agenda[totalContatos] = (Contato*)malloc(sizeof(Contato));

                if (agenda[totalContatos] == NULL) {
                    printf("Erro: Falha na alocação de memória.\n");
                    return 1;
                }

                printf("Inserir contato #%d\n", totalContatos + 1);
                printf("Nome: ");
                fgets(agenda[totalContatos]->nome, sizeof(agenda[totalContatos]->nome), stdin);
                printf("Telefone: ");
                fgets(agenda[totalContatos]->telefone, sizeof(agenda[totalContatos]->telefone), stdin);
                printf("Celular: ");
                fgets(agenda[totalContatos]->celular, sizeof(agenda[totalContatos]->celular), stdin);
                printf("Endereço: ");
                fgets(agenda[totalContatos]->endereco, sizeof(agenda[totalContatos]->endereco), stdin);
                printf("Aniversário: ");
                fgets(agenda[totalContatos]->aniversario, sizeof(agenda[totalContatos]->aniversario), stdin);

                totalContatos++;
            } else {
                printf("Erro: Limite de contatos atingido. Não é possível adicionar mais contatos.\n");
            }
        } else if (opcao == 2) {
            if (totalContatos > 0) {
                int posicao;
                printf("Digite a posição do contato que deseja visualizar (0 a %d): ", totalContatos - 1);
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < totalContatos) {
                    Contato* contato = agenda[posicao];
                    printf("Contato #%d:\n", posicao);
                    printf("Nome: %s", contato->nome);
                    printf("Telefone: %s", contato->telefone);
                    printf("Celular: %s", contato->celular);
                    printf("Endereço: %s", contato->endereco);
                    printf("Aniversário: %s", contato->aniversario);
                } else {
                    printf("Erro: Posição inválida.\n");
                }
            } else {
                printf("A agenda está vazia. Nenhum contato para visualizar.\n");
            }
        } else if (opcao == 3) {
            // Libera a memória alocada para os contatos
            for (int i = 0; i < totalContatos; i++) {
                free(agenda[i]);
            }
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
