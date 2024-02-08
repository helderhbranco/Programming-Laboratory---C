#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "input.h"

/**
 * Funçao imprimirFunc
 * @param funcionario 
 * imprime os dados de um determinado funcionario
 */
void imprimirFunc(Func funcionario) {
    int i;
    printf("\nNome: %s \n codigo: %4d Estado: %d\n", funcionario.nome, funcionario.codigo, funcionario.estado);
    for(i=0;i<5;i++){
        printf("Projeto: %d \n",funcionario.projeto[i]);
    }
}
/**
 * Função procurarFunc
 * @param funcionarios 
 * @param nome Nome do funcionario
 * @return -1 - O funcionario não existe, i-funcionario existe
 */
int procurarFunc(Funcionarios funcionarios, char nome[]) {
    int i;
    for (i = 0; i < funcionarios.contador; i++) {
        if (strcmp(funcionarios.funcionario[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}
/**
 * Funçao editarFuncionario
 * @param funcionario Apontador para a estrutura Func
 */
void editarFuncionario(Funcionarios *funcionario) {

    char nome[NOME_MAX], nomeAlterado[NOME_MAX];
    int i,y;
/** Insere o nome do funcionario que quer eitar se este existir (i|=-1),
 * pode alterar os dados,nome e codigo*/
    lerString(nome, NOME_MAX, "\nNome : ");
    i = procurarFunc(*funcionario, nome);
    if (i != -1) {

        lerString(nomeAlterado, NOME_MAX, "\nNome : ");
        strcpy((*funcionario).funcionario[i].nome, nomeAlterado);

        (*funcionario).funcionario[i].codigo = obterInt(0, 9999, "codigo: ");
          
        for(y=0;y<5;y++){
          funcionario->funcionario[funcionario->contador].projeto[y]= obterInt(0,5,"Projeto:");
        }

        

    }
}
/**
 * Funçao carregarFuncionairos
 * @param funcionarios Apontador para a estrutura Funcionarios
 * @param ficheiro  Apontador para o ficheiro onde estao guardados os funcionarios 
 * e carregamos os de novo para o programa
 */
void carregarFuncionarios(Funcionarios *funcionarios, char *ficheiro) {
    int i, sucesso = 0;

    FILE *fp = fopen(ficheiro, "rb");
    if (fp != NULL) {

        fread(&funcionarios->contador, sizeof (int), 1, fp);

        if (funcionarios->contador > 0) {
            funcionarios->tamanho = funcionarios->contador;
            funcionarios->funcionario = (Func*) malloc(funcionarios->contador * sizeof (Func));
            for (i = 0; i < funcionarios->contador; i++) {
                fread(&funcionarios->funcionario[i], sizeof (Func), 1, fp);

            }
            sucesso = 1;
        }

        fclose(fp);
    }

    if (!sucesso) {
        fp = fopen(ficheiro, "wb");
        if (fp != NULL) {

            funcionarios->funcionario = (Func*) malloc(TAM_INICIAL * sizeof (Func));
            funcionarios->contador = 0;
            funcionarios->tamanho = TAM_INICIAL;

            fclose(fp);
        }
    }

}
/**
 * Funçao guardarFuncionairos
 * @param funcionarios Apontador para a estrutura Func
 * @param ficheiro Apontador pra o Ficheiro onde vai guardar os funcionarios
 */
void guardarFuncionarios(Funcionarios *funcionarios, char *ficheiro) {
    int i;

    FILE *fp = fopen(ficheiro, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&funcionarios->contador, sizeof (int), 1, fp);

    for (i = 0; i < funcionarios->contador; i++) {
        fwrite(&funcionarios->funcionario[i], sizeof (Func), 1, fp);

    }

    fclose(fp);
}
/**
 * Funçao libertarFuncionarios
 * @param funcionarios Apontador para a estrutura Func
 * Liberta memoria
 */
void libertarFuncionarios(Funcionarios *funcionarios) {
    if (funcionarios->funcionario) {
        free(funcionarios->funcionario);
        funcionarios->funcionario = NULL;
    }

    funcionarios = NULL;
}
/**
 * Funçao inserirFunc
 * @param funcionario
 * @return -1 se nao existir  o funcionario, se nao Já existe
 */
int inserirFunc(Funcionarios *funcionario) {
    char nome[NOME_MAX];
    int i;
    lerString(nome, NOME_MAX, "\nNome : ");

    if (procurarFunc(*funcionario, nome) == -1) {

        strcpy(funcionario->funcionario[funcionario->contador].nome, nome);

        funcionario->funcionario[funcionario->contador].codigo = obterInt(0, 9999, "codigo:");
        
        for(i=0; i<5 ; i++){
         funcionario->funcionario[funcionario->contador].projeto[i]= obterInt(0,5,"Projeto:");
        }

        funcionario->funcionario[funcionario->contador].estado = 1;
        
        (*funcionario).funcionario[(*funcionario).contador].Q_diasTrabalhados = 0;

        return funcionario->contador++;
    } else printf("Já existe o funcionario");

}
/**
 * Funçao expandirFuncionarios
 * @param funcionario Apontador para a estrutura Func
 * 
 */
void expandirFuncionarios(Funcionarios *funcionario) {
    int tam = (funcionario->tamanho) == 0 ? TAM_INICIAL : funcionario->tamanho * 2;
    Func *temp = (Func*) realloc(funcionario->funcionario, sizeof (Func) * (tam));
    if (temp != NULL) {
        funcionario->tamanho = tam;
        funcionario->funcionario = temp;
    }
}
/**
 * Funçao inserirFuncionarios
 * @param funcionario Apontaodor para a estrutura Func
 */
void inserirFuncionarios(Funcionarios *funcionario) {
    if (funcionario->contador == funcionario->tamanho){
        /**Aumenta onumero maximo de funcionarios possiveis se o contador for igual ao tamanho*/
        expandirFuncionarios(funcionario);
    }
    /** Se o contador for menor que o tamanho e se a funçao inserirFunc retornar -1
     *  o funcionario jà existe, se nao é impossível inserir novo funcionário*/
    if (funcionario->contador < funcionario->tamanho) {
        if (inserirFunc(funcionario) == -1) {
            puts("O funcionário já existe");
        }
    } else {
        puts("Não é possível inserir um novo funcionário");
    }
}
/**
 * Funçao procurarFuncionarios
 * @param funcionario 
 */
void procurarFuncionarios(Funcionarios funcionario) {
    int funcio;

    char nome[NOME_MAX];
    lerString(nome, NOME_MAX, "\nNome : ");

    if ((funcio = procurarFunc(funcionario, nome)) != -1) {
        imprimirFunc(funcionario.funcionario[funcio]);
    } else {
        puts("O funcionario não existe.");
    }
}
/**
 * Funçao removerFuncionarios
 * @param funcionario Apontador para a estrutura Func
 */
void removerFuncionarios(Funcionarios *funcionario) {
    /** Posiçao do funcionario*/
    int i;
    int h;


    char nome[NOME_MAX];
    lerString(nome, NOME_MAX, "\nNome: ");

    h= procurarFunc(*funcionario, nome);
     

    if (h != -1 && funcionario->contador > 0) {
         for (i = 0; i < funcionario->contador; i++){
             /** Altera o estado do funcionario de 1 para 0 (removido)*/
        funcionario->funcionario[i].estado = 0;
         }
    } else {
        puts("O funcionario não existe.");
    }
}
/**
 * Funçao listarFuncionarios
 * @param funcionario 
 */
void listarFuncionarios(Funcionarios funcionario) {
    int i;

    if (funcionario.contador > 0) {
        for (i = 0; i < funcionario.contador; i++) {
            imprimirFunc(funcionario.funcionario[i]);
        }
    } else {
        puts("Lista vazia");
    }
}
