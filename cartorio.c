#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro()//Responsável por copiar os valores das string
{
	//Inicio crianção de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da crianção de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");// Coletando informação do usuário
	scanf("%s,", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das string
	
	FILE *file;// cria o arquivo 
	file = fopen(arquivo,"w");// cria o arquivo e cria o "w" significa escrever
	fprintf(file,cpf);// salva o valor da variável
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a");// cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coletando informação do usuario
	scanf("%s,", nome);
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file, nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando informaçao do usuario
	scanf("%s,", sobrenome);
	
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o aquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o aquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informaçao do usuario
	scanf("%s,", cargo);
	
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file);//fecha o aquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio crianção de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//Final da crianção de variaveis/strings
	
	printf("Digite o cpf a ser consultado: ");// Coletando informação do usuário
	scanf("%s",cpf);//%s refere-se a strings
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");// cria o arquivo e cria o "r" significa ler
	
	if(file == NULL)//quando a condição for NULA
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");//Coletando informação do usuario
	}
	
	while(fgets(conteudo,200,file) != NULL)//Função enquanto ate 200
	{
		printf("\nEssas sao as informações do usuário: ");//Informa tudo que o sistema conseguiu encontrar
		printf("%s", conteudo);//%s refere-se a strings
		printf("\n\n");//Pular linha
	}
	 
	 system("pause");
	 
	 
}

int deletar()
{
	//Inicio crianção de variaveis/strings
	char cpf[40];
	//Final da crianção de variaveis/strings

	printf("Digite o cpf a ser deletado: ");// Coletando informação do usuário
	scanf("%s",cpf);//%s refere-se a strings
	
	remove(cpf);
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");// cria o arquivo e cria o "r" significa ler
	
	if(file == NULL)//quando a condição for NULA
	{
		printf("O usuário não se encontra no sistema!\n");//Informa que o sistema nao conseguiu encontrar
		system("pause");
	}
	
	
}


int main() 
    {
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for (laco=1;laco=1;)
	{
	
	    system("cls");//Responsavel por limpar a tela
	  
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
	    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n");
	    printf("Opção: ");//Final do menu
	
    
        scanf("%d", &opcao);//Armazenando a escolha do usuário
    
        system("cls");//Responsavel por limpar a tela
        
        switch(opcao)//inicio da seleção do menu
        {
		   case 1: 
		   registro();//chamaada de funções
           break;
           
           case 2:
		   consulta();//consulta de funções
		   break;
		   
		   case 3:
		   deletar();
		   break;
		   
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
		   	
		   
		   
		   default:	
		   printf("Esta opção não está disponivel!\n");
    	   system("pause");
		   break;
		}//fim da seleção do menu
    	    
    }    
}    
