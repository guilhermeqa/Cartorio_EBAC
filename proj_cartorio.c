#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável pelo funcionamento das strings

int cadastro() // Tela de cadastro de novos usuários - Função responsável pelo cadastro
{
		// Inicio variáveis
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// Fim variáveis
	
	printf("Digite o CPF para cadastro: "); // Cadastro CPF
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Função responsável por copiar valores das Strings
	
		FILE *file; // Criando o Arquivo
		file = fopen(arquivo, "w"); // Criando o Arquivo - "w" para "escrever"
		fprintf(file,cpf); // Salvando o valor da variável
		fclose(file); // Fecha o arquivo
	
		file = fopen(arquivo, "a"); // Adicionando separação entre as informações salvas no arquivo
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o nome para cadastro: "); // Cadastro nome
	scanf("%s",nome);
	
		file = fopen(arquivo, "a"); // Atualizando arquivo - "a" para "atualizar"
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a"); // Adicionando separação entre as informações salvas no arquivo
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o sobrenome para cadastro: "); // Cadastro sobrenome
	scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a"); // Atualizando arquivo
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a"); // Adicionando separação entre as informações salvas no arquivo
		fprintf(file, ",");
		fclose(file);
	
	printf("Digite o cargo para cadastro: "); // Cadastro cargo
	scanf("%s",cargo);
	
		file = fopen(arquivo, "a"); // Atualizando arquivo
		fprintf(file,cargo);
		fclose(file);
	
	system("pause");
	
}

int deletar() // Tela de exclusão de usuários - Função para deletar usuários
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra em nosso banco de dados!\n"); // Mensagem após exclusão
		system("pause");
	}
}

int consulta() // Tela para consulta de todos os usuários cadastrados
{
	setlocale(LC_ALL, "Portuguese"); // Definindo idioma do código
	
	char cpf[40];
	char conteudo[200];
		
	printf("Digite o CPF para consulta: ");
	scanf("%s",cpf);
	
		FILE *file;
		file = fopen(cpf, "r"); // Abrindo arquivo solicitado
	
	if(file == NULL)
	{
		printf("CPF não localizado. Verifique e tente novamente! \n"); // Mensagem em caso de consulta invalida
		system("pause"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário cadastrado: "); // Devolvendo as informações solicitadas
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // Limpando a poluição da tela
	fclose(file);
}



int main () //Inicio do Menu - Opções
{
		int opcao=0; // Definição de Variáveis
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
		
				setlocale(LC_ALL, "Portuguese"); // Definindo idioma do código
	
				printf("\t\t\tCartório EBAC - Sistema de Registro de Nomes\n\n\n"); // Mensagem inicial ao abrir o programa
				printf("Escolha uma opção para prosseguir\n\n"); // Inicio menu
				printf("\t 1 - Cadastrar um novo usuário\n");
				printf("\t 2 - Deletar usuários\n");
				printf("\t 3 - Consultar todos os usuários\n");
				printf("\t 4 - Fechar o programa\n\n");
				printf("Digite sua opção: "); // Fim menu
		
				scanf("%d", &opcao); // Entendendo a opção do usuário
	
				system("cls"); // Limpando a poluição da tela
		
				switch(opcao) // Escolhas do usuário
				{
					case 1: // Opção 1
						cadastro();
						break;
				
					case 2: // Opção 2
						deletar();
						break;
				
					case 3: // Opção 3
						consulta();
						break;
			
					case 4: // Opção 4
						printf("Obrigado por utilizar o sistema de Registro de Nomes da EBAC!");
						return 0;
						break;
				
					default: // Opção não existente
						printf("Oops! Esta opção não existe. Retorne ao Menu e escolha uma opção valida para prosseguir!\n");
						system("pause");
						break;
				} // Fim das escolhas
	
			}
		}
	
		else
			printf("Senha incorreta! Tente novamente.");
	
}


