#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Nessa primeira etapa criei um menu com apenas a opção de cadastro simples, no momento não sendo realizada nenhuma validação.
int main()
{
    int menuOption;

    int populacao;
    float area;
    float pib;
    int countTouristic;


    do {
        printf("\n******* Menu *******\n");
        printf("1 - Cadastro de cartas\n");
        printf("0 - Sair\n");
        printf("Digite o número da opção desejada:");
        scanf("%d", &menuOption);

        switch (menuOption) {
            case 0:
                printf("\nPrograma finalizado\n");
                break;
            case 1:
                printf("\nPopulação:");
                scanf("%d", &populacao);

                printf("\nÁrea:");
                scanf("%f", &area);

                printf("\nPIB:");
                scanf("%f", &pib);

                printf("\nQuantidade de Pontos Turísticos:");
                scanf("%d", &countTouristic);

                printf("\n---- Cidade cadastrada com Sucesso! ----");

                printf("\nPopulação:%d", populacao);
                printf("\nÁrea:%.2f", area);
                printf("\nPIB:%.2f", pib);
                printf("\nQuantidade de Pontos Turísticos:%d \n", countTouristic);
                break;
            
            default:
                printf("\nOpção inválida\n");
                break;
        }
    } while (menuOption != 0);

    return 0;
}
