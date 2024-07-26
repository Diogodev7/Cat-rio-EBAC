#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro()//Respons�vel por copiar os valores das string
{
	//Inicio crian��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da crian��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");// Coletando informa��o do usu�rio
	scanf("%s,", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores das string
	
	FILE *file;// cria o arquivo 
	file = fopen(arquivo,"w");// cria o arquivo e cria o "w" significa escrever
	fprintf(file,cpf);// salva o valor da vari�vel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a");// cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//Coletando informa��o do usuario
	scanf("%s,", nome);
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file, nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//Coletando informa�ao do usuario
	scanf("%s,", sobrenome);
	
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o aquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o aquivo
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando informa�ao do usuario
	scanf("%s,", cargo);
	
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file);//fecha o aquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio crian��o de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//Final da crian��o de variaveis/strings
	
	printf("Digite o cpf a ser consultado: ");// Coletando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a strings
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");// cria o arquivo e cria o "r" significa ler
	
	if(file == NULL)//quando a condi��o for NULA
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");//Coletando informa��o do usuario
	}
	
	while(fgets(conteudo,200,file) != NULL)//Fun��o enquanto ate 200
	{
		printf("\nEssas sao as informa��es do usu�rio: ");//Informa tudo que o sistema conseguiu encontrar
		printf("%s", conteudo);//%s refere-se a strings
		printf("\n\n");//Pular linha
	}
	 
	 system("pause");
	 
	 
}

int deletar()
{
	//Inicio crian��o de variaveis/strings
	char cpf[40];
	//Final da crian��o de variaveis/strings

	printf("Digite o cpf a ser deletado: ");// Coletando informa��o do usu�rio
	scanf("%s",cpf);//%s refere-se a strings
	
	remove(cpf);
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");// cria o arquivo e cria o "r" significa ler
	
	if(file == NULL)//quando a condi��o for NULA
	{
		printf("O usu�rio n�o se encontra no sistema!\n");//Informa que o sistema nao conseguiu encontrar
		system("pause");
	}
	
	
}


int main() 
    {
    int opcao=0; //Definindo vari�veis
    int laco=1;
    
    for (laco=1;laco=1;)
	{
	
	    system("cls");//Responsavel por limpar a tela
	  
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n");
	    printf("Op��o: ");//Final do menu
	
    
        scanf("%d", &opcao);//Armazenando a escolha do usu�rio
    
        system("cls");//Responsavel por limpar a tela
        
        switch(opcao)//inicio da sele��o do menu
        {
		   case 1: 
		   registro();//chamaada de fun��es
           break;
           
           case 2:
		   consulta();//consulta de fun��es
		   break;
		   
		   case 3:
		   deletar();
		   break;
		   
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
		   	
		   
		   
		   default:	
		   printf("Esta op��o n�o est� disponivel!\n");
    	   system("pause");
		   break;
		}//fim da sele��o do menu
    	    
    }    
}    
