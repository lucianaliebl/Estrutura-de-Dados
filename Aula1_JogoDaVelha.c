#include <stdio.h>

void imprimirMatriz( char mat[3][3]){
    for(int l = 0; l < 3; l++){
        for(int c = 0; c < 3; c++){
             printf("\t%c", mat[l][c]);
        }
        printf("\n");
    }

}

int main(){
    
    int jogadas = 0;
    char jogador = 'X';
    int i, j;
    char matriz[3][3] = {{'0', '0', '0'},
                         {'0', '0', '0'},
                         {'0', '0', '0'}};

    printf("Tabuleiro incial:\n");
    
    imprimirMatriz(matriz);

    do{
        //Permite o jogador fazer a jogada
        printf("Jogador %c, escolha uma posicao pela linha e coluna: ", jogador);
        scanf("%d %d", &i, &j);

        //Verifica se a jogada será em uma posição válida e conta as jogadas
        if(i >= 0 && i < 3 && j >= 0 && j < 3 && matriz[i][j] == '0'){
            matriz[i][j] = jogador;
            imprimirMatriz(matriz);
            jogadas++;

            //Alterna os jogadores
            if(jogador == 'X'){
                jogador = 'O';
            } else{
                jogador = 'X';
            }
        } else{
            printf("Posicao invalida! Escolha outra posicao\n");
        }
       
        //Verifica se alguém ganhou
        if(jogadas >= 5 &&(
           (matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz [0][2] && matriz[0][0] != '0') ||
           (matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz [1][2] && matriz[1][0] != '0') ||
           (matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz [2][2] && matriz[2][0] != '0') ||
           (matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz [2][0] && matriz[0][0] != '0') ||
           (matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz [2][1] && matriz[0][1] != '0') ||
           (matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz [2][2] && matriz[0][2] != '0') ||
           (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz [2][2] && matriz[0][0] != '0') ||
           (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz [2][0] && matriz[0][2] != '0')
        )){
            printf("Jogador %c venceu!\n", jogador == 'X' ? 'O' : 'X');
            break;//sai do loop se alguém vencer
        }

        //Verifica se deu empate
        if(jogadas == 9){
            printf("Empate!");
            break;
        }
    }while(1);

    printf("Tabuleiro final:\n");
    
    imprimirMatriz(matriz);
    
    return 0; 
}
