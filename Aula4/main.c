#include <stdio.h>
/*int main(){
    FILE *arq;
    arq=fopen("Arquivo.txt", "r"); //r = read

    if(arq){
        printf("Arquivo existe");
    }else{
        printf("Arquivo nao existe");
    }

    fclose(arq);

    return 0;
}
int main(){
    FILE *arq;
    char c;
    arq=fopen("Arquivo.txt", "r"); //r = read

    if(arq){
        //Captura caracter por caracter do arquvivo até o final e imprime
        while((c = getc(arq)) != EOF){ // EOF = end of file
            printf("%c", c); 
        }
    }else{
        printf("Arquivo nao existe");
    }

    fclose(arq);

    return 0;
}
int main(){
    FILE *arq;
    char nome[10], *resultado;
    arq=fopen("Arquivo.txt", "r"); //r = read

    if(arq){
        //Captura de 10 em 10 caracteres até o final do arquivo
        while(!feof(arq)){ // file end of file
            fgets(nome, 10, arq);
            printf("%s", nome); 
        }
    }else{
        printf("Arquivo nao existe");
    }

    fclose(arq);

    return 0;
}
int main(){
    FILE *arq;
    char nome[10], *resultado;
    arq=fopen("Arquivo.txt", "r"); //r = read

    if(arq){
        
        while(!feof(arq)){ // file end of file
            resultado = fgets(nome, 10, arq);
            if(resultado)
            printf("%s", nome); 
        }
    }else{
        printf("Arquivo nao existe");
    }

    fclose(arq);

    return 0;
}
int main(){
    FILE *arq;
    int num, resultado, soma = 0;
    arq=fopen("Arquivo.txt", "r"); //r = read
    // soma os nº do arquivo
    if(arq){
        
        while(!feof(arq)){ // file end of file
            fscanf(arq, "%d", &num);
            soma = soma + num;
        }
    }else{
        printf("Arquivo nao existe");
    }
    printf("A soma dos numeros e %d", soma);

    fclose(arq);

    return 0;
}*/
int main(){
    FILE *arq;
    char nome[10];

    arq=fopen("Arquivo.txt", "a"); // a = append/adiciona
    
    if(arq){
        printf("digite um nome ou 0 para sair:\n");
        fgets(nome, 10, stdin); //captura 10 caracteres digitados pelo user
        while(nome[0] != '0'){ //teste se o primeiro carectere do vetor e diferente de 0
            fputs(nome, arq);//insere o que foi digitado no arq
            printf("Digite um nome ou 0 para sair: \n");
            fgets(nome, 10, stdin);
        }
    }else{
        printf("Arquivo nao existe");
    }

    fclose(arq);

    return 0;
}
