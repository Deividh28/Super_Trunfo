#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados das cartas
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular atributos derivados
void calcularAtributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar duas cartas com base em um atributo específico
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("\nComparando cartas\n");
    switch (atributo) {
        case 1:
            printf("Atributo: População\n");
            printf("%s (%s): %d\n", c1.nome, c1.estado, c1.populacao);
            printf("%s (%s): %d\n", c2.nome, c2.estado, c2.populacao);
            if (c1.populacao > c2.populacao) printf("%s venceu!\n", c1.nome);
            else if (c1.populacao < c2.populacao) printf("%s venceu!\n", c2.nome);
            else printf("Empate!\n");
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("%s (%s): %.2f km²\n", c1.nome, c1.estado, c1.area);
            printf("%s (%s): %.2f km²\n", c2.nome, c2.estado, c2.area);
            if (c1.area > c2.area) printf("%s venceu!\n", c1.nome);
            else if (c1.area < c2.area) printf("%s venceu!\n", c2.nome);
            else printf("Empate!\n");
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("%s (%s): %.2f bilhões\n", c1.nome, c1.estado, c1.pib);
            printf("%s (%s): %.2f bilhões\n", c2.nome, c2.estado, c2.pib);
            if (c1.pib > c2.pib) printf("%s venceu!\n", c1.nome);
            else if (c1.pib < c2.pib) printf("%s venceu!\n", c2.nome);
            else printf("Empate!\n");
            break;
        case 4:
            printf("Atributo: Densidade Populacional\n");
            printf("%s (%s): %.2f hab/km²\n", c1.nome, c1.estado, c1.densidade_populacional);
            printf("%s (%s): %.2f hab/km²\n", c2.nome, c2.estado, c2.densidade_populacional);
            if (c1.densidade_populacional < c2.densidade_populacional) printf("%s venceu!\n", c1.nome);
            else if (c1.densidade_populacional > c2.densidade_populacional) printf("%s venceu!\n", c2.nome);
            else printf("Empate!\n");
            break;
        case 5:
            printf("Atributo: PIB per Capita\n");
            printf("%s (%s): %.2f\n", c1.nome, c1.estado, c1.pib_per_capita);
            printf("%s (%s): %.2f\n", c2.nome, c2.estado, c2.pib_per_capita);
            if (c1.pib_per_capita > c2.pib_per_capita) printf("%s venceu!\n", c1.nome);
            else if (c1.pib_per_capita < c2.pib_per_capita) printf("%s venceu!\n", c2.nome);
            else printf("Empate!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 699.28, 20};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6700000, 1182.3, 415.26, 15};
    
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);
    
    int escolha;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);
    
    compararCartas(carta1, carta2, escolha);
    
    return 0;
}
