

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"
#include "input.h"
#define Ficheiro "Jornada.txt"

/**
 * Função procurarFunc
 * @param funcionarios 
 * @param nome Nome do funcionario
 * @return -1 - O funcionario não existe, i-funcionario existe
 */
int procurarFunc2(Funcionarios funcionarios, char nome[]) {
    int i;
    for (i = 0; i < funcionarios.contador; i++) {
        if (strcmp(funcionarios.funcionario[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

/**
 * Funçao diasTrabalhados 
 * @param funcionario Apontador pra a etrutura Func
 */
void diasTrabalhados(Funcionarios *funcionarios) {

    int k, i, j;
    int project;

    char nome[NOME_MAX];
    lerString(nome, NOME_MAX, "\nNome: ");

    k = procurarFunc2(*funcionarios, nome);
      int u = (*funcionarios).funcionario[k].Q_diasTrabalhados++;
    /** Se o k|= -1, o funcionario existe */
    if (k != -1) {

        
        /** Pede a data da jornada ao utilizador*/
        printf("Insera a data dd/mm/aaaa\n");
        (*funcionarios).funcionario[k].diasTrabalhados[u].diaTrabalho.dia = obterInt(0, 31, "Dia:");
        (*funcionarios).funcionario[k].diasTrabalhados[u].diaTrabalho.mes = obterInt(0, 12, "Mes:");
        (*funcionarios).funcionario[k].diasTrabalhados[u].diaTrabalho.ano = obterInt(0, 3000, "Ano:");
        
        /** Pede o projeto em que está a trabalhar (...)*/   
       while (j != -1) {
                       project = obterInt(0, 5, "Projeto:");
            for (i = 0; i < 5; i++) {
                
                if (project == (*funcionarios).funcionario[k].projeto[i]) {
                    (*funcionarios).funcionario[k].diasTrabalhados[u].projeto = project;
                    j = -1;
                    
                   
                } else{ 
                printf("O funcionário não está associado a esse projeto.\n");
                project = obterInt(0, 5, "Projeto:");
                }
            } 
        }         
        /** Pede o tipo de jornada (0-falta,1-meia jornada,2.jornada completa)*/
        printf("Qual foi  sua jornada? 0= nao trabalhou 1= meia jornada 2= jornada completa\n");
        (*funcionarios).funcionario[k].diasTrabalhados[u].jornada = obterInt(0, 2, "Jornada: ");
        /**Soma as faltas,meias jornadas e jornadas completas*/
        if ((*funcionarios).funcionario[k].diasTrabalhados[u].jornada == 0) {
            (*funcionarios).funcionario[k].diasTrabalhados[u].falta++;
        }
        if ((*funcionarios).funcionario[k].diasTrabalhados[u].jornada == 1) {
            (*funcionarios).funcionario[k].diasTrabalhados[u].m_jornada++;
        }
        if ((*funcionarios).funcionario[k].diasTrabalhados[u].jornada == 2) {
            (*funcionarios).funcionario[k].diasTrabalhados[u].c_jornada++;
        }
        /** pede os dias trabalhados do uncionario no fim de semana de um mes*/
        printf("Quantos dias de fim de semana trabalhou neste mês?\n");
        (*funcionarios).funcionario[k].diasTrabalhados[u].fim_semana = obterInt(0, 8, "Fins de semana: ");




    }
}


/**
 * Funçao imprimirInformacoes
 * @param Funcionarios
 * Imrpimir toda a informaçao referente às jornadas dos funcionarios num ficheiro .txt
 */

void imprimirInformacoes(Funcionarios Funcionarios) {
    int mes;
    int ano;
    mes = obterInt(0, 12, "Mes:");
    ano = obterInt(0, 3000, "Ano:");


    FILE *fp = fopen(Ficheiro, "w");

    for (int i = 0; i < Funcionarios.contador; i++) {

        fprintf(fp,
                "Codigo: %d \n"
                "Nome: %s \n",

                Funcionarios.funcionario[i].codigo,
                Funcionarios.funcionario[i].nome);

        
        fprintf(fp,"%d",Funcionarios.funcionario[i].Q_diasTrabalhados);

        for (int u= 0; u < Funcionarios.funcionario[i].Q_diasTrabalhados; u++) {
           if (mes == Funcionarios.funcionario[i].diasTrabalhados[u].diaTrabalho.mes &&
                    ano == Funcionarios.funcionario[i].diasTrabalhados[u].diaTrabalho.ano) {
               
                fprintf(fp,
                        "Dias: %d  Mes: %d  Ano: %d Projeto: %d Jornada: %d \n",
                        Funcionarios.funcionario[i].diasTrabalhados[u].diaTrabalho.dia,
                        Funcionarios.funcionario[i].diasTrabalhados[u].diaTrabalho.mes,
                        Funcionarios.funcionario[i].diasTrabalhados[u].diaTrabalho.ano,
                        Funcionarios.funcionario[i].diasTrabalhados[u].projeto,
                        Funcionarios.funcionario[i].diasTrabalhados[u].jornada);


            }
        }
        fprintf(fp, "\n\n");
}


    fclose(fp);
}
