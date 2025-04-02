//Implementação da funções
//As aspas duplas indica para o compilador procurar o arquivo no diretório do projeto, se não encontrar então procure no diretório padrão
#include "Aula2_3_PrototiposFuncoes.h" //inclui o arquivo dos prototipos
#include <stdio.h> //os sinais <> indica para o compilador que ele deve procurar esse arquivo no direitório padrão do C
#include <stdlib.h>


/*static garante que a variável seja inicializada apenas uma vez e mantenha seu valor entre chamadas de função. 
Isso significa que o valor de contador_produto não será reiniciado para toda vez que a função onde ela é usada for chamada.*/
static int contador_produto = 0; //Quantos produtos foram cadastrados
static int contador_carrinho = 0; //Quantos itens estão no carrinho
static Produto produtos[50]; //Os produtos disponíveis no mercado
static Carrinho carrinho[50]; //Os itens no carrinho do usuário


void infoProduto(Produto prod);
Produto pegarProdutoPorCodigo(int codigo);
int * temNoCarrinho(int codigo);

void menu(){
    int opcoes;

    printf("\nEscolha uma opcao:\n1 - Cadastrar Produto\n2 - Listar Produto\n3 - Comprar Produto\n4 - Visualizar Carrinho\n5 - Fechar Pedido\n6 - Sair\n");
    scanf("%d", &opcoes);
    getchar();

    switch(opcoes){
        case 1: 
            cadastrarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            comprarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            fecharPedido();
            break;
        case 6:
            printf("Sistema encerrado");
            break;
        default: 
            printf("Opcao invalida!\n");
            menu();
            break;
    }   
}

void cadastrarProduto(){
    printf("=====Cadatro de Produto=====\n");
    printf("----------------------------\n");
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

void infoProduto(Produto prod){
    printf("Codigo: %d\nNome: %s\nPreco: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void listarProdutos(){
    if(contador_produto > 0){
        printf("=======Listagem de Podutos======\n");
        printf("--------------------------------\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
            printf("--------------------------------\n");
        }
        menu();
    } else{
        printf("Nenhum produto cadastrado\n");
        menu();
    }
}

void comprarProduto(){
    //Verifica se há produtos disponíveis (variável  indica a quantidade de produtos cadastrados).
    if(contador_produto > 0){
        printf("Informe o codigo do produto que deseja adicionar ao carrinho:\n");
        printf("=======Produtos Disponiveis=======\n");

        //Inicia um loop para percorrer todos os produtos disponíveis.
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
            printf("-------------------------------\n");
        }

        int codigo; //armazena o código do produto escolhido pelo usuário.
        scanf("%d", &codigo);
        getchar();
        int tem_mercado = 0;// essa variável será usada para verificar se o código do produto existe

        //Inicia outro loop para percorrer todos os produtos e verificar se o código inserido corresponde a algum produto disponível.
        for(int i = 0; i < contador_produto; i++){
            if(produtos[i].codigo == codigo){ //Verifica se o código do produto atual corresponde ao código inserido pelo usuário.
                tem_mercado = 1; //Define  como 1, indicando que o produto foi encontrado
            
                if(contador_carrinho > 0){
                    int * retorno = temNoCarrinho(codigo); //Chama a função  para verificar se o produto já está no carrinho e retorna um ponteiro.
                
                    if(retorno[0] == 1){ //Verifica se o produto já está no carrinho (retorno[0] == 1 significa "sim")
                        carrinho[retorno[1]].quantidade++; //Aumenta a quantidade do produto existente no carrinho.
                        printf("Aumentei a quantidade do %s ja existente no carrinho\n",
                                strtok(carrinho[retorno[1]].produto.nome, "\n"));
                                menu();
                    }else{ //Caso o produto não esteja no carrinho, prossegue para adicioná-lo
                        Produto p = pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produto = p; //Adiciona o produto ao carrinho
                        carrinho[contador_carrinho].quantidade = 1; //Define a quantidade inicial como 1
                        contador_carrinho++; //Incrementa o contador de itens no carrinho.
                        printf("O produto %s foi adicionado ao carrinho\n", strtok(p.nome, "\n"));
                        menu();
                    }
                }else{
                    Produto p = pegarProdutoPorCodigo(codigo);
					carrinho[contador_carrinho].produto = p;
					carrinho[contador_carrinho].quantidade = 1;
					contador_carrinho++;
					printf("O produto %s foi adicionado ao carrinho.\n", strtok(p.nome, "\n"));
                    menu();
                }
            }
        }
        if(tem_mercado < 1){ //Verifica se nenhum produto foi encontrado com o código inserido
            printf("Nao foi encontrado o prduto com o codigo %d\n", codigo);
            menu();
        }
    }else{ //Caso não existam produtos cadastrados (), executa este bloco.
        printf("Ainda nao ha produtos cadastrados\n");
        menu();
    }
}

void visualizarCarrinho(){
    if(contador_carrinho > 0){ //Verifica se há produtos no carrinho. A variável  indica a quantidade de itens.
        printf("========Produtos do Carrinho======\n");
        printf("----------------------------------\n");
        //Inicia um loop para percorrer todos os itens no carrinho.
        for(int i = 0; i < contador_carrinho; i++){
            infoProduto(carrinho[i].produto);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
            printf("----------------------------------\n");
        }
        menu();
    }else{
        printf("Ainda nao ha produtos no carrinho\n");
        menu();
    }
}

Produto pegarProdutoPorCodigo(int codigo){
    Produto p; //Declaração da variável  do tipo . Esta variável será utilizada para armazenar o produto encontrado.
    //Inicia um loop que percorre todos os produtos cadastrados. A variável  indica o número total de produtos
    for(int i = 0; i < contador_produto; i++){
        if(produtos[i].codigo == codigo){ //Verifica se o código do produto atual () é igual ao código fornecido como argumento na função.
            p = produtos[i]; //Caso a condição seja verdadeira, atribui o produto correspondente ao código para a variável .
        }

    }
    return p; //Retorna o objeto  armazenado na variável . Caso nenhum produto com o código fornecido seja encontrado,  será retornado com seu valor padrão (provavelmente vazio ou não inicializado).
}

//Declaração da função , que recebe um parâmetro  do tipo inteiro e retorna um ponteiro para um array de inteiros.
int * temNoCarrinho(int codigo){
    /*Declaração de um array estático . Ele possui dois elementos:
    retorno[0]: indica se o produto está no carrinho (1 para sim, 0 para não)
    retorno[1]: armazena o índice do produto no carrinho, caso ele esteja presente.
    O uso de  mantém o valor do array entre as chamadas da função.
*/
    static int retorno[] = {0, 0};
    //nicia um loop para percorrer todos os itens no carrinho. A variável  indica o número de produtos atualmente no carrinho.
    for(int i = 0; i < contador_carrinho; i++){
        if(carrinho[i].produto.codigo == codigo){ //Verifica se o código do produto () corresponde ao código fornecido como argumento da função.
            retorno[0] = 1; //tem o produto com este código no carrinho
            retorno[1] = i; //o índice do produto no carrinho
        }
    }
    return retorno;
    /*Retorna o array , contendo:
    retorno[0]: 1 se o prduto está no carrinho, 0 caso contrário
    retorno[1]: O índice do produto no carrinho, ou 0 caso ele não esteja
*/
}

void fecharPedido(){
    if(contador_carrinho > 0){ //Verifica se há produtos no carrinho. A variável  indica a quantidade de itens
        float valorTotal = 0.0;
        printf("========Produtos do Carrinho======\n");
        printf("----------------------------------\n");
        for(int i = 0; i < contador_carrinho; i++){ //Inicia um loop para percorrer todos os itens no carrinho
            Produto p = carrinho[i].produto; //Obtém o produto atual no carrinho e armazena na variável p
            int quantidade = carrinho[i].quantidade; //Obtém a quantidade do produto no carrinho e armazena na variável quantidade
            valorTotal += p.preco * quantidade; //Incrementa o valor total da compra, calculando o preço do produto multiplicado pela sua quantidade
            infoProduto(p);
            printf("Quantidade: %d\n", quantidade);
            printf("-----------------------\n");
        }
        printf("O valor total da compra e R$ %.2f\n", valorTotal);

        contador_carrinho = 0; //reseta o carrinho
        printf("Obrigado pela preferencia!");
        menu();
    }else{ //Caso o carrinho esteja vazio (), executa este bloco.
        printf("Nao ha nenhum produto no carrinho\n");
        menu();
    }

}