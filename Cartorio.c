#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int reg(){

    char arq[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Você escolheu o registro de nomes\n\n");
    
    printf("Digite o CPF\n\n"); ///////
    scanf("%s", cpf);
    
    strcpy(arq, cpf);

    FILE *file;
    file = fopen(arq, "w");
    fprintf(file,cpf);
    fclose(file);

    file = fopen(arq, "a");
    fprintf(file,",");
    fclose(file);


    printf("Digite o Nome\n\n"); ///////
    scanf("%s", nome);

    file = fopen(arq, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arq, "a");
    fprintf(file,",");
    fclose(file);


    printf("Digite o Sobrenome\n\n"); ///////
    scanf("%s", sobrenome);

    file = fopen(arq, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arq, "a");
    fprintf(file,",");
    fclose(file);


    printf("Digite o Cargo\n\n"); ///////
    scanf("%s", cargo);

    file = fopen(arq, "a");
    fprintf(file,cargo);
    fclose(file);
  
    system("pause");
    return 0;
}


int con(){

    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char cont[200];

    printf("Você escolheu consultar nomes\n\n");

    printf("Digite o CPF a ser consultado\n\n"); ///////
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");
    
    
    if(file == NULL){
        printf("Não localizado\n");
    }

    while (fgets(cont, 200, file) != NULL)
    {
        printf("\n Informações: \n");
        printf("%s", cont);
        printf("\n\n");
    }
    
    fclose(file);
    system("pause");
    return 0;
}


int del(){

    char cpf[40];

    printf("Você escolheu deletar nomes\n\n");

    printf("Digite o CPF a ser deletado\n\n"); ///////
    scanf("%s",cpf);


    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);
    
    if(file == NULL){
        printf("Não localizado\n");
        system("pause");

    }

    remove(cpf);

    if(file != NULL){
        printf("Deletado!\n");
        system("pause");

    }
    system("pause");
    return 0;
}

int sair(){
    exit(0);
}



int main() {

    int op=0;
    int x=1;
    char senha[]="a";
    int compara;

    printf("### Cartório da EBAC!###\n\n");
    printf("### Login de Administrador!###\n\nDigite a sua senha: ");
    scanf("%s", senha);

    compara = strcmp(senha, "admin");

    if(compara == 0){

        for (x=1;x==1;){
            system("cls");

            setlocale(LC_ALL, "Portuguese");

            printf("### Cartório da EBAC!###\n\n");
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n\n");
            printf("\t2 - Consultar nomes\n\n");
            printf("\t3 - Deletar nomes\n\n");
            printf("\t4 - Sair\n\n");
            printf("Opção: \n\n");

            scanf("%d", &op);

            system("cls");

            switch (op)
                    {
            case 1:
                reg();
                break;
            
            case 2:
                con();
                break;

            case 3:
                del();
                break;

            case 4:
                sair();
                break;


            default:
                printf("Opção não disponível\n\n");
                    system("pause");
                    break;
            }
            
        }
    }
    else
        printf("Senha incorreta\n\n");
}