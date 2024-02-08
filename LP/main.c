/* 
 * @file main.c
 * @author Helder Branco
 * @brief exemplo
 */

#include <stdio.h>

#include "func.h"
#include "input.h"


#define FUNCIONARIOS_DB_FILE  "funcionarios.bin"
#define Ficheiro "Jornada.txt"

int main() {
    /**Opçao que desejo fazer (0 a 8)*/
    int opcao;
    Funcionarios funcionario;

    carregarFuncionarios(&funcionario, FUNCIONARIOS_DB_FILE);

    do {
        printf("\nFuncionario------------------------------------------------------");
        printf("\n1 - Inserir");
        printf("\n2 - Procurar");
        printf("\n3 - Editar");
        printf("\n4 - Remover");
        printf("\n5 - Listar");
        printf("\n6 - Guardar");
        printf("\n7 - Adicionar Jornadas");
        printf("\n8 - Imprimir Jornadas ");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");
        printf("\nFuncionários: %d/%d", funcionario.contador, funcionario.tamanho);

        opcao = obterInt(0, 8, "\nOpção: ");

        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirFuncionarios(&funcionario);
                break;
            case 2:
                procurarFuncionarios(funcionario);
                break;

            case 3:
                editarFuncionario(&funcionario);
                break;
            case 4:
                removerFuncionarios(&funcionario);
                break;
            case 5:
                listarFuncionarios(funcionario);
                break;
            case 6:
                guardarFuncionarios(&funcionario, FUNCIONARIOS_DB_FILE);
                break;

            case 7:
                diasTrabalhados(&funcionario);
                break;

            case 8:
                imprimirInformacoes(funcionario);
                break;

            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);

    libertarFuncionarios(&funcionario);

    return 0;
}

