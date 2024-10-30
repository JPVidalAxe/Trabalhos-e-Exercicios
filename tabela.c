#include <stdio.h>
#include <string.h>

typedef struct{
    char placa[10];
    char marca[10];
    char modelo[10];
    char cpf[40];

}veiculo;

typedef struct{
    veiculo vei[50];
    int tam;
}tabela;

tabela ler_veic(char filename[]){
    FILE *arq = fopen(filename,"rt");

    tabela aux;
    char linha[64];
    char *token;

    fgets(linha,60,arq);
    
    aux.tam = 0;

    while (!feof(arq)){
        fgets(linha,60,arq);
        linha[strlen(linha) -1] = '\0';
        token = strtok(linha, ",");
        strcpy(aux.vei[aux.tam].placa,token);
        
        token = strtok(NULL, ",");
        strcpy(aux.vei[aux.tam].marca,token);

        token = strtok(NULL, ",");
        strcpy(aux.vei[aux.tam].modelo,token);

        token = strtok(NULL, ",");
        strcpy(aux.vei[aux.tam].cpf,token);

        aux.tam++;
    }



    fclose(arq);

    return aux;
}

int main(){
    tabela tabv = ler_veic("tabveiculos.txt");

    for(int i = 0; i <= tabv.tam; i++){
        printf("%s, %s, %s, %s\n", tabv.vei[i].placa, tabv.vei[i].marca, tabv.vei[i].modelo, tabv.vei[i].cpf);
    }
    return 0;
}