#include <stdio.h>

/**
 *  Desafio Super Trunfo - Países
 *  Programa simples no qual o usuário cadastra duas cartas e depois realiza comparações dos valores
 *  Nenhum tipo de validação de dados, tamanho máximo de array ou loop infinito foi realizada, então se digitar dado errado o sistema trava
 *  */

//Classe usada para armazenar os dados das cartas
typedef struct
{
    char estado;
    char codigoCarta[3];
    char nomeCidade[50];
    unsigned int populacao;
    float area;
    float pib;
    unsigned int qtdePontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

//Método responsável por calcular a Densidade
float calcularDensidade(int populacao, float area) {
    return (float) populacao / area; 
}

//Método responsável por calcular o PIB per Capita
float calcularPIB(float pib, int populacao) {
    return pib / (float) populacao;
}

/**
 * Método responsável por calcular o super poder
 * (carta.densidade/100): Foi realizado para usar o valor invertido
 */

long double calcularSuperPoder(Carta carta){
    return (float) carta.populacao + carta.area + carta.pib + (float) carta.qtdePontosTuristicos + (carta.densidade/100) + carta.pibPerCapita;
}

//Método responsável pelo cadastro das informações da carta
Carta cadastro()
{
    Carta carta;

    printf("\nDigite uma letra entre A e H para o estado:");
    scanf("%s", &carta.estado);

    printf("\nDigite dois números para o código da carta(ex: 01,02...):");
    scanf("%2s", carta.codigoCarta);

    printf("\nDigite o nome da cidade(Máximo 50 letras):");
    scanf("%s", carta.nomeCidade);

    printf("\nDigite a População:");
    scanf("%d", &carta.populacao);

    printf("\nDigite a Área:");
    scanf("%f", &carta.area);

    printf("\nDigite o PIB:");
    scanf("%f", &carta.pib);

    printf("\nDigite a Qtde de Pontos Turísticos:");
    scanf("%d", &carta.qtdePontosTuristicos);

    carta.densidade = calcularDensidade(carta.populacao, carta.area);
    carta.pibPerCapita = calcularPIB(carta.pib, carta.populacao);

    printf("\n---- Cidade cadastrada com Sucesso! ----");

    printf("\nEstado:%c", carta.estado);
    printf("\nCódigo Carta:%s", carta.codigoCarta);
    printf("\nNome Cidade:%s", carta.nomeCidade);
    printf("\nPopulação:%d", carta.populacao);
    printf("\nÁrea:%.2f km²", carta.area);
    printf("\nPIB:R$%.2f", carta.pib);
    printf("\nQuantidade de Pontos Turísticos:%d", carta.qtdePontosTuristicos);
    printf("\nDensidade Populacional:%.2f",  carta.densidade);
    printf("\nPIB per Capita:%.2f \n", carta.pibPerCapita);

    return carta;
}

/**
 * Método responsável por comparar e exibir os valores conforme documentação 
 * A saída da comparação será 1 ou 0, caso a relação seja verdadeira ou falsa. Se o resultado da comparação for 1, a carta 1 ganhou; se o resultado for 0, a carta 2 ganhou.
 */
void compararExibirValores(Carta arrayCartasComparacao[2]){
    Carta carta1 = arrayCartasComparacao[0];
    Carta carta2 = arrayCartasComparacao[1];

    printf("\n#### Comparações ####\n");
    printf("---- Se for 1 a Carta 1 ganhou -- Se for 0 Carta 2 ganhou ----\n");
    printf("\nPopulação:%d", carta1.populacao > carta2.populacao);
    printf("\nÁrea:%d", carta1.area > carta2.area);
    printf("\nPIB:%d", carta1.pib > carta2.pib);
    printf("\nQuantidade de Pontos Turísticos:%d", carta1.qtdePontosTuristicos > carta2.qtdePontosTuristicos);
    printf("\nDensidade Populacional:%d",  carta1.densidade < carta2.densidade);
    printf("\nPIB per Capita:%d", carta1.pibPerCapita > carta2.pibPerCapita);
    printf("\nSuper Poder:%d \n", calcularSuperPoder(carta1) > calcularSuperPoder(carta2));
}

/**
 * Função principal, resposável por iniciar o programa e gerenciar o menu
 */
int main()
{
    int menuOption;
    int posicaoNovaCarta = 0;
    Carta arrayCartas[2];
    
    do
    {
        printf("\n******* Menu *******\n");
        printf("1 - Cadastro de cartas\n");// Não está salvando
        printf("2 - Comparar Cartas\n");//Compara as duas cartas cadastradas
        printf("0 - Sair\n");
        printf("Digite o número da opção desejada:");
        scanf("%d", &menuOption);

        switch (menuOption)
        {
        case 0:
            printf("\nPrograma finalizado!\n");
            break;
        case 1:
            arrayCartas[posicaoNovaCarta++] = cadastro();
            break;
        case 2:
            if(posicaoNovaCarta < 2) {
                printf("\nDuas cartas precisam ser cadastras!\n");
            } else {
                compararExibirValores(arrayCartas);
            }
            break;
        default:
            printf("\nOpção inválida\n");
            break;
        }
    } while (menuOption != 0);

    return 0;
}
