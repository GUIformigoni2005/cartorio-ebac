#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> // biblioteca responsavel por cuidar das strings 


int registro() //função responsavel por cadastrar os usuarios no sistema 
{
	//inicio da criação de variaveis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
   //final da criação de variaveis/strings 
    printf("Digite o CPF a ser cadrastrado: "); //coletando informação do usuario
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
	    printf("não foi possivel abrir o arquivo, não localizado! . \n");
	}
    
    while(fgets(conteudo, 200 ,file) != NULL)
    {
	   printf("\nEssas são as informações do usuário: ");
	   printf("%s" , conteudo);
	   printf("\n\n");
	
	}
    
    system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL) 
    {
    	printf("O usuário não foi encontrado no sitema!. \n");
	    system("pause");
	}   
}


int main()
   {  
   int opcao=0; //definindo as variáveis 
   int laco=1;
  
   for(laco=1;laco=1;)
   {

     system("cls");
   
     setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
    
     printf(" Cartório da EBAC \n\n"); //inico do menu 
     printf("Escolha a opção desejada no menu:\n\n");
     printf("\t1 - Registra nomes\n");
     printf("\t2- consultar nomes\n");
     printf("\t3- deletar nomes\n\n"); 
     printf("\t4 - Sair do sistema\n\n");
	 printf("opção:"); //fim do menu
 
     scanf("%d", &opcao); //armazenando escolha do usuário 

     system("cls"); //responsavel por limpar a tela 
 
     switch(opcao) //inicio da seleção do menu
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
	    
	    case 4:
		printf("Obrigado por utilizar o sistema!\n"); 
	    return 0;
	    break;
	     
	     
	    default:
	    printf("Essa opção não está disponivel!\n");
	    system("pause");
		break;
    	
        } //fim da seleção 
 
 
    }
	      
}


