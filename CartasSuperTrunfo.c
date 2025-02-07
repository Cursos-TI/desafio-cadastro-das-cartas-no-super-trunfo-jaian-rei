  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 32

typedef struct {
    char codigo[5];
    char nome[20];
    int populacao;
    float area;
    float pib;
    char pontos_turisticos[100];
} Cidade;

void exibir_dados(Cidade cidade) {
    printf("Código: %s\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("População: %d habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Pontos Turísticos: %s\n", cidade.pontos_turisticos);
    printf("------------------------------\n");
}

Cidade cadastrar_cidade() {
    char estados[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char cidades[8][4][20] = {
        {"Cidade A1", "Cidade A2", "Cidade A3", "Cidade A4"},
        {"Cidade B1", "Cidade B2", "Cidade B3", "Cidade B4"},
        {"Cidade C1", "Cidade C2", "Cidade C3", "Cidade C4"},
        {"Cidade D1", "Cidade D2", "Cidade D3", "Cidade D4"},
        {"Cidade E1", "Cidade E2", "Cidade E3", "Cidade E4"},
        {"Cidade F1", "Cidade F2", "Cidade F3", "Cidade F4"},
        {"Cidade G1", "Cidade G2", "Cidade G3", "Cidade G4"},
        {"Cidade H1", "Cidade H2", "Cidade H3", "Cidade H4"}
    };
    printf("\n=== DESAFIO DO SUPER TRUNFO ===\n\n");

    printf("Escolha um estado (A-H):\n");
    for (int i = 0; i < 8; i++) {
        printf("%c\n", estados[i]);
    }
    
    char estado;
    scanf(" %c", &estado);
    
    int estado_index = estado - 'A';
    if (estado_index < 0 || estado_index > 7) {
        printf("Estado inválido!\n");
        exit(1);
    }
    
    printf("Escolha uma cidade:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d - %s\n", i + 1, cidades[estado_index][i]);
    }
    
    int cidade_index;
    scanf("%d", &cidade_index);
    cidade_index--;
    
    if (cidade_index < 0 || cidade_index > 3) {
        printf("Número inválido!\n");
        exit(1);
    }
    
    Cidade cidade;
    sprintf(cidade.codigo, "%c%02d", estado, cidade_index + 1);
    strcpy(cidade.nome, cidades[estado_index][cidade_index]);
    
    printf("Informe a população da cidade: ");
    scanf("%d", &cidade.populacao);
    
    printf("Informe a área da cidade em km²: ");
    scanf("%f", &cidade.area);
    
    printf("Informe o PIB da cidade em bilhões: ");
    scanf("%f", &cidade.pib);
    
    printf("Informe os pontos turísticos da cidade: ");
    getchar();
    fgets(cidade.pontos_turisticos, 100, stdin);
    cidade.pontos_turisticos[strcspn(cidade.pontos_turisticos, "\n")] = 0;
    
    return cidade;
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int total_cidades = 0;
    
    while (1) {
        printf("\n1 - Cadastrar nova cidade\n");
        printf("2 - Exibir todas as cidades\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        
        int opcao;
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            if (total_cidades < MAX_CIDADES) {
                cidades[total_cidades] = cadastrar_cidade();
                total_cidades++;
            } else {
                printf("Limite de cidades atingido!\n");
            }
        } else if (opcao == 2) {
            if (total_cidades == 0) {
                printf("Nenhuma cidade cadastrada ainda.\n");
            } else {
                for (int i = 0; i < total_cidades; i++) {
                    exibir_dados(cidades[i]);
                }
            }
        } else if (opcao == 3) {
            printf("Saindo do sistema...\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
    
    return 0;
}
  
    
    
    
    
    




