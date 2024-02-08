#ifndef FUNC_H
#define FUNC_H

#define TAM_INICIAL 1
#define NOME_MAX 51
#define MAX_PROJETO 5

/**Estrutura da data*/
typedef struct{
    /**Dia da jornada*/
    int dia;
    /**Mes da jornada*/
    int mes;
    /**Ano da jornada*/
    int ano;
}Data;
/**Estrutura do Trabalho/jornada*/
typedef struct {
    /**Data da jornada*/
    Data diaTrabalho;
    /**Tipo de jornada,0 = nao trabalhou 1 = meia jornada 2 = jornada competa*/
    int jornada;
    /*Dias trabalhados no fim de semana em um determinado mes*/
    int fim_semana;
   /**Contador do tipo de jornada(meia jornada)*/
    int m_jornada;
    /**Contador do tipo de jornada(falta)*/
    int falta;
    /**Contador do tipo de jornada(jornada completa)*/
    int c_jornada;
    /**Tipo de Projeto*/
    int projeto;
} Trabalho;
/**Estrutura do funcionario*/
typedef struct {
    /**Código do funcionario*/
    int codigo; 
    /**Nome do funcionario*/
    char nome[NOME_MAX];
    /**Quantidade e dias trabalhados pelo funcionario*/
    int Q_diasTrabalhados;
    /**Estado do funcionario (1-ativo,0-removido*/
    int estado;
    /**Projetos*/
    int projeto[MAX_PROJETO];
    
    Trabalho diasTrabalhados[30];
    
} Func;
/**Estrutura de Funcionarios*/
typedef struct {
    /**Numero de funcionarios*/
    int contador;
    /**Numero maximo de funcionarios na empresa*/
    int tamanho;
    /**Apontador funcionario para a estrutura do funcionario(Func)*/
    Func *funcionario;
} Funcionarios;

void carregarFuncionarios(Funcionarios *funcionario, char *ficheiro);
void inserirFuncionarios(Funcionarios *funcionario);
void procurarFuncionarios(Funcionarios funcionario);
void removerFuncionarios(Funcionarios *funcionario);
void listarFuncionarios(Funcionarios funcionario);
void libertarFuncionarios(Funcionarios *funcionario);
void guardarFuncionarios(Funcionarios *funcionario, char *ficheiro);
void diasTrabalhados(Funcionarios *funcionario);
void editarFuncionario(Funcionarios *funcionario);
void imprimirInformacoes(Funcionarios Funcionarios);
#endif /* FUNC_H */


