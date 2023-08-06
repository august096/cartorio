#include <stdio.h> // Biblioteca de comunicação com o usuario 
#include <stdlib.h> // Biblioteca de alocacao de espaço de memoria
#include <locale.h> // Biblioteca de alocacao de texto por região
#include <string.h> // Biblioteca responsavel por cuidar das string

int registro()// Função responsalvel por cadastrar os usuarios no sistema
{
    // Inicio da criação das variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de  vairiaveis 

    printf("Digite o CPF a ser cadastrado:"); // Responsavel por coletar informaçes dos usario
    scanf("%s",cpf);// "%s" referece a string

    strcpy(arquivo, cpf); // Responsavel por copiar os valores das string

    FILE *file; // Cria o arquivo
    file= fopen(arquivo,"w"); // Cria o arquivo
    fprintf(file,cpf); // Salva o valor da variavel
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("DIgite o nome a ser cadastrado:");
    scanf("%s",nome);

    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s",sobrenome);

    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo:");
    scanf("%s", cargo);

    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    system("read");

}

int consulta()
{
    setlocale(LC_ALL, "portugues"); //definir linguagem

    // inicio da criação das variaveis/string
    char cpf[40];
    char conteudo[200];
    // final da criação de  vairiaveis

    printf("Digite o cpf a ser consultado:");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Não foi possivel abrir arquivo, não localizado!\n ");
    }

    while (fgets(conteudo, 200, file)!= NULL);
    {
        printf("\nEssas são informaçoes do usuario:");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("read");
}

int deletar()
{
    // inicio da criação das variaveis/string
    char cpf[40];
    // final da criação de  vairiaveis

    printf("DIgite o cpf do usuario a ser deletado:");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("O usuario nao se encontra no sistema!.\n");
        system("read");
    }
}



int main()
{
    int opcao=0; //Definindo a linguagem
    int laco=1;

    for(laco= 1; laco= 1;)
    {

        system("clear");// Responsavel por limpar a tela para o ususario

        

        setlocale(LC_ALL, "Portuguese"); // inicio do menu

        printf(" ### Cartorio da EBAC ### \n\n");// "\n" e usado para pular linha 
        printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1 - Registras nomes\n");// "\t" e usado para dar um espaço do paragrafo
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar nomes\n\n"); 
        printf("\t4 - Sair do sistema\n\n");
        printf("Opcao:");// final do menu

        scanf("%d", &opcao); // Armazenado a escolha do usuario 

        system("clear");// Responsavel por limpar a tela para o ususario

        switch (opcao) // Inicio da celeção do menu
        {
          case 1: 
          registro(); // Chamada de funçoes.
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
          printf("opcao incorreta \n");
          system("read");
          break;
        }// Final da celeção do menu
        
        
        
    }
    
}
