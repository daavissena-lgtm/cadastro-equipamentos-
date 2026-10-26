#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int opcao;
    char nome[100];
    char codigo[50];
    char localizacao[100];
    char linha[300];
    FILE *arquivo;

    do {
        printf("\n===== CADASTRAR SEUS EQUIPAMENTOS =====\n");
        printf("1 - Cadastrar equipamentos\n");
        printf("2 - Listar equipamentos\n");
        printf("3 - Sair\n");
        printf("Escolha uma das opções: ");

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;
        }

        if (sscanf(linha, "%d", &opcao) != 1) {
            printf("Opcao invalida! Digite um numero.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\nNome do equipamento: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Codigo de identificação: ");
                fgets(codigo, sizeof(codigo), stdin);
                codigo[strcspn(codigo, "\n")] = '\0';

                printf("Localização: ");
                fgets(localizacao, sizeof(localizacao), stdin);
                localizacao[strcspn(localizacao, "\n")] = '\0';

                arquivo = fopen("equipamentos.txt", "a");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo!\n");
                    break;
                }

                fprintf(arquivo, "%s | %s | %s\n",
                        nome, codigo, localizacao);

                fclose(arquivo);

                printf("Equipamento cadastrado com sucesso!\n");
                break;

            case 2:
                arquivo = fopen("equipamentos.txt", "r");

                if (arquivo == NULL) {
                    printf("Nenhum equipamento cadastrado ainda.\n");
                    break;
                }

                printf("\n===== EQUIPAMENTOS CADASTRADOS =====\n");

                int encontrou = 0;

                while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                    printf("%s", linha);
                    encontrou = 1;
                }

                if (!encontrou) {
                    printf("Nenhum equipamento cadastrado ainda.\n");
                }

                fclose(arquivo);
                break;

            case 3:
                printf("Programa encerrado!\n");
                break;

            default:
                printf("Opcão invalida! Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
