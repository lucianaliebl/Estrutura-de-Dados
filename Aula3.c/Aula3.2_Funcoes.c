//Implementação das funções
#include <stdio.h>
#include <stdlib.h>
#include "Aula3.3_PrototiposFuncoes.h" //importar o arquivo com os protótipos da função

void adicao(int n, int m){
    printf("O resultado da adicao de %d mais %d e igual a %d\n", n, m, n + m);
}

void subtracao(int n, int m){
    printf("O resultado da subtracao de %d menos %d e igual a %d\n", n, m, n - m);
}

void multiplicacao(int n, int m){
    printf("O resultado da multiplicacao de %d vezes %d e igual a %d\n", n, m, n * m);
}

void divisao(int n, int m){
    if(m == 0){
        printf("Resultado indefinido\n");
    }else{
        printf("O resultado da divisao de %d por %d e igual a %d\n", n, m, n / m);
    }
}

void menu(){
    int opcao;
    int a, b;

    printf("Qual operacao deseja fazer?\n");
    printf("1 - Adicao\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n5 - Sair\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1: 
            printf("Qual o valor de a:\n");
            scanf("%d", &a);
    
            printf("Qual o valor de b:\n");
            scanf("%d", &b);

            adicao(a, b);
            menu();
            break;
        case 2:
            printf("Qual o valor de a:\n");
            scanf("%d", &a);
    
            printf("Qual o valor de b:\n");
            scanf("%d", &b);

            subtracao(a, b);
            menu();
            break;
        case 3: 
            printf("Qual o valor de a:\n");
            scanf("%d", &a);
    
            printf("Qual o valor de b:\n");
            scanf("%d", &b);    

            multiplicacao(a, b);
            menu();
            break;
        case 4:
            printf("Qual o valor de a:\n");
            scanf("%d", &a);
        
            printf("Qual o valor de b:\n");
            scanf("%d", &b);

            divisao(a, b);
            menu();
            break;
        case 5: 
            printf("Sistema encerrado!\n");
            break;
        default:
            printf("Opcao invalida. Escolha uma opcao disponivel\n");
            menu();
            break;
    }
}