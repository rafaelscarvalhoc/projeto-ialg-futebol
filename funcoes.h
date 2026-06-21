#include <string>

#ifndef FUNCOES_H
#define FUNCOES_H

using namespace std;

struct Time {
    int identificador;
    string nome;
    string divisao;
    string cidade;
    int fundacao;
    int titulos;
};
void inserirTime();
void removerTime();
void buscarTime();
void buscarTimeLinear();    
void buscarTimebinaria();
void listarTimes();
void exibirIntervalo();
void ordenarRegistros();
void alterarRegistro();
void salvarAlteracoes();
void introducao();
void menu();
void liberarMemoria();
void saida();
void carregarArquivo();

#endif