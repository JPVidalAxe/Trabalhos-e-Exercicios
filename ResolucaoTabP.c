#include <stdio.h>
#include <string.h>

typedef struct {
	char placa[16];
	char marca[32];
	char modelo[32];
	char cpf[32];
} t_veiculo;

typedef struct {
	int tam;
	t_veiculo vet[50];
} t_tabela_veics;

typedef struct {
	char cpf[16];
	char nome[32];
	char email[32];
	char celular[32];
} t_props;

typedef struct {
	int tam;
	t_props vet[50];
} t_tabela_props;

t_tabela_veics ler_tab_veiculos(char filename[]){
	FILE *arq = fopen(filename,"rt");
	t_tabela_veics aux;
	char linha[64];
	char *token;
   
	fgets(linha,63,arq);

	aux.tam = 0;

	while(!feof(arq)){
		fgets(linha,63,arq);
		if(linha[strlen(linha)-1] == '\n')
			linha[strlen(linha)-1] = '\0';

		token = strtok(linha, ",");
		strcpy(aux.vet[aux.tam].placa,token);

		token = strtok(NULL, ",");
		strcpy(aux.vet[aux.tam].marca,token);

		token = strtok(NULL, ",");
		strcpy(aux.vet[aux.tam].modelo,token);

		token = strtok(NULL, ",");
		strcpy(aux.vet[aux.tam].cpf,token);

		aux.tam++;
	} // fim while..


    fclose(arq);

	return aux;
}

t_tabela_props ler_tab_props(char filename[]){
	FILE *arq = fopen(filename,"rt");
	t_tabela_props aux;
	char linha[90];
	char *token;
   
	fgets(linha,80,arq);

	aux.tam = 0;

	while(!feof(arq)){
		fgets(linha,80,arq);

		if(linha[strlen(linha)-1] == '\n')
			linha[strlen(linha)-1] = '\0';

		token = strtok(linha, ",");
		strcpy(aux.vet[aux.tam].cpf,token);

		token = strtok(NULL, ",");
		strcpy(aux.vet[aux.tam].nome,token);

		token = strtok(NULL, ",");
		strcpy(aux.vet[aux.tam].email,token);

		token = strtok(NULL, ",");
		strcpy(aux.vet[aux.tam].celular,token);

		aux.tam++;
	} // fim while..

    fclose(arq);

	return aux;
}


int main(){
	t_tabela_veics tabV = ler_tab_veiculos("tabveiculos.txt");
	t_tabela_props tabP = ler_tab_props("tabproprietarios.txt");

	for(int i=0; i < tabP.tam; i++){
		printf("Nome: %s; email: %s\n", tabP.vet[i].nome, tabP.vet[i].email);
		for(int j=0; j < tabV.tam; j++){
			if(strcmp(tabP.vet[i].cpf, tabV.vet[j].cpf) == 0)
				printf("placa: %s; modelo: %s; marca: %s\n", tabV.vet[j].placa, tabV.vet[j].modelo, tabV.vet[j].marca);
		}
		printf("\n");
	}

	return 0;
}
