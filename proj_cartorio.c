#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel pelo funcionamento das strings

int cadastro() // Tela de cadastro de novos usu�rios - Fun��o respons�vel pelo cadastro
{
		// Inicio vari�veis
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// Fim vari�veis
	
	printf("Digite o CPF para cadastro: "); // Cadastro CPF
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Fun��o respons�vel por copiar valores das Strings
	
		FILE *file; // Criando o Arquivo
		file = fopen(arquivo, "w"); // Criando o Arquivo - "w" para "escrever"
		fprintf(file,cpf); // Salvando o valor da vari�vel
		fclose(file); // Fecha o arquivo
	
		file = fopen(arquivo, "a"); // Adicionando separa��o entre as informa��es salvas no arquivo
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o nome para cadastro: "); // Cadastro nome
	scanf("%s",nome);
	
		file = fopen(arquivo, "a"); // Atualizando arquivo - "a" para "atualizar"
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a"); // Adicionando separa��o entre as informa��es salvas no arquivo
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o sobrenome para cadastro: "); // Cadastro sobrenome
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a"); // Atualizando arquivo
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a"); // Adicionando separa��o entre as informa��es salvas no arquivo
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o cargo para cadastro: "); // Cadastro cargo
	scanf("%s",cargo);
	
		file = fopen(arquivo, "a"); // Atualizando arquivo
		fprintf(file,cargo);
		fclose(file);
	
	system("pause");
	
}

int deletar() // Tela de exclus�o de usu�rios - Fun��o para deletar usu�rios
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra em nosso banco de dados!\n"); // Mensagem ap�s exclus�o
		system("pause");
	}
}

int consulta() // Tela para consulta de todos os usu�rios cadastrados
{
	setlocale(LC_ALL, "Portuguese"); // Definindo idioma do c�digo
	
	char cpf[40];
	char conteudo[200];
		
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf);
	
		FILE *file;
		file = fopen(cpf, "r"); // Abrindo arquivo solicitado
	
	if(file == NULL)
	{
		printf("CPF n�o localizado. Verifique e tente novamente! \n"); // Mensagem em caso de consulta invalida
		system("pause"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio cadastrado: "); // Devolvendo as informa��es solicitadas
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // Limpando a polui��o da tela
	fclose(file);
}



int main () //Inicio do Menu - Op��es
{
		int opcao=0; // Defini��o de Vari�veis
		int laco=1;
		
		char senhadigitada[10]="a";
		int comparacao;
		
		printf("Bem vindo ao sistema de Registro de Nomes da EBAC!\n\n");
		printf("Digite sua senha para utilizar: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");
		
		if(comparacao == 0)
		{
			system("cls");
			for(laco=1;laco=1;) // Looping menu
			{
	
				system("cls");
		
				setlocale(LC_ALL, "Portuguese"); // Definindo idioma do c�digo
	
				printf("\t\t\tCart�rio EBAC - Sistema de Registro de Nomes\n\n\n"); // Mensagem inicial ao abrir o programa
				printf("Escolha uma op��o para prosseguir\n\n"); // Inicio menu
				printf("\t 1 - Cadastrar um novo usu�rio\n");
				printf("\t 2 - Deletar usu�rios\n");
				printf("\t 3 - Consultar todos os usu�rios\n");
				printf("\t 4 - Fechar o programa\n\n");
				printf("Digite sua op��o: "); // Fim menu
		
				scanf("%d", &opcao); // Entendendo a op��o do usu�rio
	
				system("cls"); // Limpando a polui��o da tela
		
				switch(opcao) // Escolhas do usu�rio
				{
					case 1: // Op��o 1
						cadastro();
						break;
				
					case 2: // Op��o 2
						deletar();
						break;
				
					case 3: // Op��o 3
						consulta();
						break;
			
					case 4: // Op��o 4
						printf("Obrigado por utilizar o sistema de Registro de Nomes da EBAC!");
						return 0;
						break;
				
					default: // Op��o n�o existente
						printf("Oops! Esta op��o n�o existe. Retorne ao Menu e escolha uma op��o valida para prosseguir!\n");
						system("pause");
						break;
				} // Fim das escolhas
	
			}
		}
	
		else
			printf("Senha incorreta! Tente novamente.");
	
}


