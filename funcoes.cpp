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

    while (getline(arquivo, linha)) {
        if (linha.empty()) continue; // como a propria linha fala se ela ta vazia continua
        
        if (tamanhoAtual >= capacidade) { // se o tamanho for maior ou igual a capacidade
            capacidade += 10; //adiciona 10 na capacidade
            Time *novoVetor = new Time[capacidade]; //cria o vetor time com a nova capacidade
            for (int i = 0; i < tamanhoAtual; i++) { // preenche o novo vertor
                novoVetor[i] = times[i]; 
            }
            delete[] times; //deleta o vertor antigo 
            times = novoVetor; //iguala o antigo ao novo e segue o programa
        }
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

    // Verifica se o ID e invalido
    if (novoTime.identificador == -1) {
    cout << "ID invalido! O valor -1 e reservado para remocao logica." << endl;
    return;
    }

    // Verifica se o ID e repetido
    for (int i = 0; i < tamanhoAtual; i++) {

    if (times[i].identificador == novoTime.identificador) {
        cout << "Ja existe um time com esse ID!" << endl;
        return;
        }
    }
    
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

// 2. Remover dados existentes 
void removerTime() {
    int idBusca;
    cout << "Digite o ID do time que deseja remover: ";
    cin >> idBusca;

    for (int i = 0; i < tamanhoAtual; i++) {
        if (times[i].identificador == idBusca) {
            // Marca com chave negativa 
            times[i].identificador = -1; 
            cout << "Time removido logicamente com sucesso!" << endl;
            return;
        }
    }
    cout << "Time com ID " << idBusca << " nao encontrado." << endl;
}

// menu pra selecionar o metodo de busca
void buscarTime() {
    cout<<"Obs: caso você escolha a busca binaria sera feito uma ordenação baseada em ids para garantir o funcionamento da busca binaria";
while (true) {
    int escolha;

    cout <<endl<<"1- Busca linear";
    cout <<endl<<"2- Busca binaria";
    cout <<endl<<"0- Voltar"<<endl;

    cin >> escolha;

    if (escolha == 1) {
        buscarTimeLinear();
        return;
    }

    if (escolha == 2) {
        buscarTimebinaria();
        return;
    }

    if (escolha == 0) {
        return;
    }

    cout <<endl<< "Opcao invalida!"<<endl<<"Por favor tente novamente!"<<endl;
    }
}

void buscarTimeLinear() {
    int idBusca;
    cout << "Digite o ID do time para busca linear: ";
    cin >> idBusca;

    bool encontrado = false;

    // Loop simples: olha do início  até o último que e o tamanho atual
    for (int i = 0; i < tamanhoAtual; i++) {
        // Ignora removidos logicamente
        if (times[i].identificador == -1) continue; 

        // Se achar o ID, imprime e para
        if (times[i].identificador == idBusca) {
            cout << "\nTime Encontrado na posicao " << i << ":" << endl;
            cout << "ID: " << times[i].identificador 
                 << " | Nome: " << times[i].nome 
                 << " | Divisao: " << times[i].divisao 
                 << " | Cidade: " << times[i].cidade 
                 << " | Fundacao: " << times[i].fundacao 
                 << " | Titulos: " << times[i].titulos << endl;
            encontrado = true;
            break; // Sai do loop assim que encontrar
        }
    }

    if (!encontrado) {
        cout << "Time nao encontrado na busca linear." << endl;
    }
}



// 3. Buscar time (Busca Binária no vetor ordenado por ID)
void buscarTimebinaria() {
    int idBusca;
    cout << "Digite o ID do time para busca binaria: ";
    
    cin >> idBusca;
    
    // Selection sort para garantir ordenação antes da busca binária
    for (int i = 0; i < tamanhoAtual - 1; i++) {

        //minIdx == menor id encontrado
        int minIdx = i;
        // estrutura de repetição
        for (int j = i + 1; j < tamanhoAtual; j++) {
            //se time na posição j for menor que times na menor posição achada o minimo vira j, . identificador e so pra puxar qual parte da struct a gente ta olhando
            if (times[j].identificador < times[minIdx].identificador) {
                minIdx = j;
            }
        }
        // criamos uma variavel temporaria para não perder dados e igualamos ao menor indice 
        Time temp = times[minIdx];
    
        times[minIdx] = times[i];
        times[i] = temp;
    }

    // busca binária
    int inicio = 0, fim = tamanhoAtual - 1;
    bool encontrado = false;

    //formula padrao da busca binaria
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;       
         if (times[meio].identificador == idBusca) {
            cout << "\nTime Encontrado!" << endl;
    cout << "ID: " << times[meio].identificador 
         << " | Nome: " << times[meio].nome 
         << " | Divisao: " << times[meio].divisao 
         << " | Cidade: " << times[meio].cidade 
         << " | Fundacao: " << times[meio].fundacao 
         << " | Titulos: " << times[meio].titulos << endl;
            encontrado = true;
            break;
        }
        if (times[meio].identificador < idBusca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (!encontrado) {
        cout << "Time nao encontrado." << endl;
    }
}

// 4. Listar todos os times
void listarTimes() {
    // segurança pra caso não tenha times cadastrados
    if (tamanhoAtual == 0) {
        cout << "Nenhum time cadastrado." << endl;
        return;
    }
    //se não

    cout << "\n--- Lista Completa de Times ---" << endl;
    for (int i = 0; i < tamanhoAtual; i++) {
        // Ignora itens removidos logicamente
        if (times[i].identificador == -1) continue; 
        cout << "ID: " << times[i].identificador 
             << " | Nome: " << times[i].nome 
             << " | Divisao: " << times[i].divisao 
             << " | Cidade: " << times[i].cidade 
             << " | Fundacao: " << times[i].fundacao 
             << " | Titulos: " << times[i].titulos << endl;
    }
    cout << "-------------------------------" << endl;
}


// 5. Exibir intervalo de registros
void exibirIntervalo() {
    int inicio, fim;
    cout << "Digite o indice inicial (ex: 1): ";
    cin >> inicio;
    cout << "Digite o indice final (ex: 10): ";
    cin >> fim;

    // como o indice começa em 0 e não e natural o ser humano considerar o 0 tiramos 1 do indice de inicio e fim pra contarmos com a posição 0
    inicio--; 
    fim--;
// segurança pra travar caso a entrada seja invalida (inicio-0) (o fim ser maior que o tamanho atual ) ou (inicio maior que o fim)
    if (inicio < 0 || fim >= tamanhoAtual || inicio > fim) {
        cout << "Intervalo invalido." << endl;
        return;
    }

    cout << "\n--- Intervalo [" << (inicio + 1) << " a " << (fim + 1) << "] ---" << endl;
    for (int i = inicio; i <= fim; i++) {
        if (times[i].identificador == -1) continue;
        cout << times[i].identificador << " | " 
             << times[i].nome << " | " 
             << times[i].divisao << " | " 
             << times[i].cidade << " | " 
             << times[i].fundacao << " | " 
             << times[i].titulos << endl;
    }
}

// 6. Ordenar registros na memória (Selection Sort)
void ordenarRegistros() {
    // menu pra escolher a forma de ordenar
    int escolhaCampo;
    cout << "Ordenar por qual campo?" << endl;
    cout << "1 - Identificador (ID)" << endl;
    cout << "2 - Nome (Ordem Alfabetica)" << endl;
    cout << "3 - Divisao" << endl;
    cout << "4 - Cidade" << endl;
    cout << "5 - Ano de Fundacao" << endl;
    cout << "6 - Quantidade de Titulos" << endl;
    cout << "Escolha: ";
    cin >> escolhaCampo;

    for (int i = 0; i < tamanhoAtual - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < tamanhoAtual; j++) {
            
            // Uma cadeia de 'if / else if' para testar qual foi a escolha do usuario
            if (escolhaCampo == 1) {
                if (times[j].identificador < times[minIdx].identificador) minIdx = j;
            } 
            else if (escolhaCampo == 2) {
                if (times[j].nome < times[minIdx].nome) minIdx = j;
            } 
            else if (escolhaCampo == 3) {
                if (times[j].divisao < times[minIdx].divisao) minIdx = j;
            } 
            else if (escolhaCampo == 4) {
                if (times[j].cidade < times[minIdx].cidade) minIdx = j;
            } 
            else if (escolhaCampo == 5) {
                if (times[j].fundacao < times[minIdx].fundacao) minIdx = j;
            } 
            else if (escolhaCampo == 6) {
                if (times[j].titulos < times[minIdx].titulos) minIdx = j;
            }
        }
        
        // A troca continua a mesma
        Time temp = times[minIdx];
        times[minIdx] = times[i];
        times[i] = temp;
    }
    cout << "Registros ordenados com sucesso na memoria!" << endl;
}

void alterarRegistro() {
    int idBusca;
    cout << "\n--- Alterar Registro ---" << endl;
    cout << "Digite o ID do time que deseja alterar: ";
    cin >> idBusca;

    bool encontrado = false;
    // ta sendo procurada com uma busca sequencial
    // foi pensado em usar busca binaria nesta função (alterar registro) contudo seria nescessario ordenar e poderia aver erros caso o id do clube fosse alterado
    for (int i = 0; i < tamanhoAtual; i++) {
        // Ignora removidos logicamente
        if (times[i].identificador == -1) continue;

        if (times[i].identificador == idBusca) {
            encontrado = true;
            cout << "Time encontrado: " << times[i].nome << endl;
            
            cout << "Qual campo deseja alterar?" << endl;
            cout << "1- Nome\n2- Divisao\n3- Cidade\n4- Fundacao\n5- Titulos\nEscolha: ";
            int opcao;
            cin >> opcao;

            // Limpa a entrada do teclado para não dar erro na leitura de strings
            cin.ignore(); 

            switch(opcao) {
                case 1: 
                    cout << "Novo Nome: "; getline(cin, times[i].nome); break;
                case 2: 
                    cout << "Nova Divisao: "; getline(cin, times[i].divisao); break;
                case 3: 
                    cout << "Nova Cidade: "; getline(cin, times[i].cidade); break;
                case 4: 
                    cout << "Novo Ano de Fundacao: "; cin >> times[i].fundacao; break;
                case 5: 
                    cout << "Nova Quantidade de Titulos: "; cin >> times[i].titulos; break;
                default: 
                    cout << "Opcao invalida!" << endl; return;
            }
            cout << "Registro atualizado com sucesso!" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Time com ID " << idBusca << " nao encontrado." << endl;
    }
}

// 7. Salvar alterações no arquivo e exclusão física dos removidos logicamente
void salvarAlteracoes() {
    ofstream arquivo(NOME_ARQUIVO);
    for (int i = 0; i < tamanhoAtual; i++) {
        // Grava apenas os elementos que nao foram marcados como deletados
        if (times[i].identificador != -1) {
            arquivo << times[i].identificador << ";"
                    << times[i].nome << ";"
                    << times[i].divisao << ";"
                    << times[i].cidade << ";"
                    << times[i].fundacao << ";"
                    << times[i].titulos << "\n";
        }
    }
    arquivo.close();
    cout << "Alteracoes salvas no arquivo " << NOME_ARQUIVO << " com sucesso!" << endl;
}
void liberarMemoria() {
    delete[] times;
    times = nullptr;
}