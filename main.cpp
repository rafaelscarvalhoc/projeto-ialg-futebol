#include <iostream>
#include "funcoes.h" // para incluir o arquivo que contem o guia das funções :)

using namespace std;
// introdução so pra ficar mais bonitinho
void introducao() {
    cout << "=======================================================================================================================================" << endl << endl;

    cout << "Ola usuario(a)! Este programa foi desenvolvido para gerenciar um sistema de cadastro de times de futebol. "<<endl
         << "permitindo a inclusao, exclusao, busca e organizacao de dados." << endl;

    cout << "Os campos cadastrados sao: \"ID\", \"NOME\", \"DIVISAO\", \"CIDADE\", "
         << "\"ANO DE FUNDACAO\" e \"QUANTIDADE DE TITULOS\"." << endl << endl;

    cout << "=======================================================================================================================================" << endl << endl;
}
void menu(){
    int escolha;

    do{
    cout<< "Por favor escolha uma opção abaixo."<<endl;
    cout<< "1- Inserir novo time. "<<endl;
    cout<< "2- Remover dados existentes. "<<endl;
    cout<< "3- Buscar time"<<endl;
    cout<< "4- Lista completa"<<endl;
    cout<< "5- Exibir intervalo de registros"<<endl;
    cout<< "6- Ordenar registros"<<endl;
    cout<< "7- Alterar registro"<<endl;
    cout<< "8- Salvar alterações"<<endl;
    cout<< "0- Sair"<<endl;
    cin>> escolha;

    switch (escolha){
        case 1:
        
        inserirTime();
        // função 1
        
        break;
        
        case 2:
        
        //função 2
        removerTime();
        
        break;
        
        case 3: 
        
        //função 3
        buscarTime();
        
        break;
        
        case 4:
        
        // função 4
        listarTimes();
        
        break;
        
        case 5:
        
        //função 5
        exibirIntervalo();
        
        break;
        
        case 6:
        
        //função 6
        ordenarRegistros();
        
        break;
        
        case 7:
        
        //função 7
        alterarRegistro();
        
        break;
        
        case 8:
        
        //função 8
        salvarAlteracoes();
        
        break;
        
        case 0: {

        char confirmacao;
        // aviso so pra garantir de o usuario não esquecer de salvar
        cout << "Deseja salvar as alteracoes antes de sair? (s/n): ";
        cin >> confirmacao;

        if (confirmacao == 's' || confirmacao == 'S') {
        salvarAlteracoes();
        } else {
        cout << "Saindo sem salvar..." << endl;
        }
        return;
}
       default:

        cout << "Opcao invalida!" << endl;
        cin.clear();            // Limpa o erro do cin
        cin.ignore(1000, '\n');  // Descarta o que foi digitado de errado
        break;

} 
}while(escolha !=0);

}
// frase so para o programa não encerrar seco
void saida(){
    cout<<endl<<"Obrigado por usar nosso programa!";

}


int main(){

    carregarArquivo();
    introducao();
    menu();
    liberarMemoria();
    saida();  

    return 0;
}