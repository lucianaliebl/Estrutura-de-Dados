#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct {
    Produto produto;
    int quantidade;
}Carrinho;

/*static garante que a variável seja inicializada apenas uma vez e mantenha seu valor entre chamadas de função. 
Isso significa que o valor de contador_produto não será reiniciado para 0 toda vez que a função onde ela é usada for chamada.*/
static int contador_produto = 0; //Quantos produtos foram cadastrados
static int contador_carrinho = 0; //Quantos itens estão no carrinho
static Produto produtos[50]; //Os produtos disponíveis no mercado
static Carrinho carrinho[50]; //Os itens no carrinho do usuário

void menu(){
    int opcoes;

    printf("\nEscolha uma opcao:\n1 - Cadastrar Produto\n2 - Listar Produto\n3 - Comprar Produto\n4 - Visualizar Carrinho\n5 - Fechar Pedido\n6 - Tem no carrinho\n7 - Pegar produto por codigo\n8 - Informacoes do Produto\n9 - Sair\n");
    scanf("%d", &opcoes);
    getchar();

    switch(opcoes){
        case 1: 
            cadastrarProduto();
            break;
        /*case 2:
            listarProdutos(produtos);
            break;
        case 3:
            comprarProduto(produtos);
            break;
        case 4:
            visualizarCarrinho(produtos);
            break;
        case 5:
            fecharPedido(produtos);
            break;
        case 6:
            temNocarrinho(produtos);
            break;
        case 7: 
            pegarProdutoPorCodigo(produtos);
            break;*/
        case 8: 
            infoProduto();
            break;
        case 9:
            printf("Sistema encerrado");
            break;
        default: 
            printf("Opcao iinvalida!\n");
            menu();
            break;
    }   
}

void cadastrarProduto(){
    printf("=====Cadatro de Produto=====");
//produtos[contador_produto]: Refere-se ao produto atual, baseado no valor de contador_produto, que é o índice para o próximo produto livre.
    printf("Informe o nome do produto:\n");
    fgets(produtos[contador_produto].nome, 30, stdin);

    printf("Qual o preco do produto:\n");
    scanf("%f", &produtos[contador_produto].preco);

/* strtok(produtos[contador_produto].nome, "\n"): Remove o caractere de nova linha (\n) que foi inserido ao final do nome pelo fgets.
strtok funciona como um "separador", descartando o \n da string*/
    printf("O produto %s foi cadastrado com sucesso\n", strtok(produtos[contador_produto].nome, "\n"));

    produtos[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;

    menu();
}

void listarProdutos(Produto prod[50]){
    printf("Produtos cadastrados: %d\n", numProd);
    for(int i = 0; i < numProd; i++){
        printf("Produto %d: %s\n", i, prod[i].nome);
        printf("Codigo produto %d: %d\n", i, prod[i].codigo);
        printf("Preco produto %d: R$%.2f\n", i, prod[i].preco);
    }
}

void infoProduto(Produto prod[50]){
    int i;
    printf("Qual produto quer informacoes: %d\n", prod[i]);
    printf("Produto: %s\n", prod[i].nome);
    printf("Codigo do produto: %d\n", prod[i].codigo);
    printf("Preco do produto: R$%.2f\n", prod[i].preco);
}

int main(){

    menu();
    
    return 0;
}
