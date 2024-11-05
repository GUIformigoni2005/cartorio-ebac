#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> // biblioteca responsavel por cuidar das strings 


int registro() //fun��o responsavel por cadastrar os usuarios no sistema 
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
   //final da cria��o de variaveis/strings 
    printf("Digite o CPF a ser cadrastrado: "); //coletando informa��o do usuario
    scanf("%s" , cpf ); //%s refere-se a strings 

    strcpy(arquivo , cpf );  //responsavel por copiar o arquivo das strings 

    FILE *file; //cria arquivo 
    file = fopen(arquivo , "w"); //cria arquivo e o "w" significa escrever 
    fprintf(file,cpf); //salvo o vcalor da variavel 
    fclose(file); //fecho o arquivo 

    file = fopen (arquivo , "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o nome a ser cadrastrado: ");
    scanf("%s",nome);

    file = fopen(arquivo , "a");
    fprintf(file,nome);
    fclose(file);


     file = fopen (arquivo , "a");
    fprintf(file,",");
    fclose(file);


     printf("digite o sobrenome a ser cadastrado: ");
     scanf("%s" ,sobrenome);

     file = fopen(arquivo, "a");
     fprintf(file,sobrenome);
     fclose(file);


    file = fopen (arquivo , "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
     
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    system("pause"); 

}


int consulta()
{   
     setlocale(LC_ALL, "Portuguese"); //definindo linguagem 

    char cpf[40];  
    char conteudo[200];
    
    printf("digite o CPF a ser consultado: ");
    scanf("%s" , cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
	    printf("n�o foi possivel abrir o arquivo, n�o localizado! . \n");
	}
    
    while(fgets(conteudo, 200 ,file) != NULL)
    {
	   printf("\nEssas s�o as informa��es do usu�rio: ");
	   printf("%s" , conteudo);
	   printf("\n\n");
	
	}
    
    system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do us�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL) 
    {
    	printf("O usu�rio n�o foi encontrado no sitema!. \n");
	    system("pause");
	}   
}


int main()
   {  
   int opcao=0; //definindo as vari�veis 
   int laco=1;
  
   for(laco=1;laco=1;)
   {

     system("cls");
   
     setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
    
     printf(" Cart�rio da EBAC \n\n"); //inico do menu 
     printf("Escolha a op��o desejada no menu:\n\n");
     printf("\t1 - Registra nomes\n");
     printf("\t2- consultar nomes\n");
     printf("\t3- deletar nomes\n\n"); 
     printf("op��o:"); //fim do menu
 
     scanf("%d", &opcao); //armazenando escolha do usu�rio 

     system("cls"); //responsavel por limpar a tela 
 
     switch(opcao) //inicio da sele��o do menu
        { 
    	 case 1:	
        registro();
     	break;
     	
       case 2:	
     	consulta();
     	break;
     	
     	case 3:
     	 deletar();
	    break;
	     
	    default:
	    printf("Essa op��o n�o est� disponivel!\n");
	    system("pause");
		break;
    	
        } //fim da sele��o 
 
 
    }
	      
}

