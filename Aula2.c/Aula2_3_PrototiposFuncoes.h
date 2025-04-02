//Evita a duplicação da estrutura de cabeçalho
#ifndef AULA2_3_PROTOTIPOSFUNCOES_H //if not define, se ainda n tiver uma definição com o nome AULA3_3_PROTOTIPOSFUNCOES_H, então ele faz tudo o que tiver dentro desse if
#define AULA2_3_PROTOTIPOSFUNCOES_H // se a definição n existe, cria essa definição 

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct {
    Produto produto;
    int quantidade;
}Carrinho;

//Protótipos das funções
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();

#endif //finaliza o if. Se a definição já existe, vem para o final do if
