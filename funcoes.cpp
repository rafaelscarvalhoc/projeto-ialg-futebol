#include <iostream>
#include <fstream>
#include <sstream> // usado para facilitar a entrada da linha do arquivo csv na função carregararquivo
#include <string>
#include "funcoes.h"

using namespace std;

// Variáveis globais para gerenciar o vetor dinâmico de times
Time *times = nullptr; // o nullptr basicamente fala que o ponteiro e nulo pra evitar lixo de memoria 
int tamanhoAtual = 0;
int capacidade = 40;
const string NOME_ARQUIVO = "times.csv";

// Função para carregar os dados do arquivo CSV ao iniciar o programa
void carregarArquivo() {
    times = new Time[capacidade];
    tamanhoAtual = 0;

    ifstream arquivo(NOME_ARQUIVO);
    if (!arquivo.is_open()) {
        cout << "Arquivo " << NOME_ARQUIVO << " nao encontrado ou não foi possivel abrir o mesmo." << endl;
        return;
    }

    string linha; // variavel vzia ela que vai pegar a linha atual do codigo

    while (getline(arquivo, linha) && tamanhoAtual < capacidade) {
        if (linha.empty()) continue; // como a propria linha fala se ela ta vazia continua
        
        stringstream ss(linha);
        // o ssstream pega toda a linha e para nos ; então criamos variaveis temporarias para pegar o valor da string correspodente
        string idStr, fundacaoStr, titulosStr;

        //fatiamos a linha selecionada dividindo ela nas partes correspondentes
        getline(ss, idStr, ';');
        getline(ss, times[tamanhoAtual].nome, ';');
        getline(ss, times[tamanhoAtual].divisao, ';');
        getline(ss, times[tamanhoAtual].cidade, ';');
        getline(ss, fundacaoStr, ';');
        getline(ss, titulosStr, ';');

        // convertendo string para inteiro 
        times[tamanhoAtual].identificador = stoi(idStr);
        times[tamanhoAtual].fundacao = stoi(fundacaoStr);
        times[tamanhoAtual].titulos = stoi(titulosStr);

        // aumentamos o contador 
        tamanhoAtual++;

        // Redimensiona se prescisar
        if (tamanhoAtual >= capacidade) { // se o tamanho for maior ou igual a capacidade
            capacidade += 10; //adiciona 10 na capacidade
            Time *novoVetor = new Time[capacidade]; //cria o vetor time com a nova capacidade
            for (int i = 0; i < tamanhoAtual; i++) { // preenche o novo vertor
                novoVetor[i] = times[i]; 
            }
            delete[] times; //deleta o vertor antigo 
            times = novoVetor; //iguala o antigo ao novo e segue o programa
        }
    }
    // fechando o arquivo
    arquivo.close();
}

// 1. Inserir novo time
void inserirTime() {
    //segurança pra caso o times n tenha assumido um ponteiro 
    if (times == nullptr) {
        times = new Time[capacidade];
    }

    // Redimensionamento caso o vetor esteja cheio igual o da função carregar arquivo
    if (tamanhoAtual >= capacidade) {
        capacidade += 10;
        Time *novoVetor = new Time[capacidade];
        for (int i = 0; i < tamanhoAtual; i++) {
            novoVetor[i] = times[i];
        }
        delete[] times;
        times = novoVetor;
    }
// prenchendo a nova linha
    Time novoTime;
    cout << "Digite o ID (inteiro positivo diferente de -1): ";
    cin >> novoTime.identificador;
    cin.ignore(); // Limpa o buffer do enter
    cout << "Digite o Nome (string com espacos): ";
    getline(cin, novoTime.nome);
    cout << "Digite a Divisao: ";
    getline(cin, novoTime.divisao);
    cout << "Digite a Cidade: ";
    getline(cin, novoTime.cidade);
    cout << "Digite o Ano de Fundacao: ";
    cin >> novoTime.fundacao;
    cout << "Digite a Quantidade de Titulos: ";
    cin >> novoTime.titulos;

    // colocando o novo time no ultimo lugar do vetor
    times[tamanhoAtual] = novoTime;
    tamanhoAtual++;
    cout << "Time inserido com sucesso!" << endl;
}

