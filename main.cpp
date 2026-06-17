#include <iostream>

using namespace std;

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
    cout<< "7- Salvar alterações"<<endl;
    cout<< "0- Sair"<<endl;
    cin>> escolha;

    switch (escolha){
        case 1:

        // função 1

        break;

        case 2:

        //função 2

        break;

        case 3: 

        //função 3

        break;

        case 4:

        // função 4

        break;

        case 5:

        //função 5

        break;

        case 6:

        //função 6

        break;

        case 7:

        //função 7

        break;

        case 0:

       return;

       default:
    cout << "Opcao invalida!" << endl;
    break;

} 
}while(escolha !=0);

}

void saida(){
    cout<<endl<<"Obrigado por usar nosso programa!";

}


int main(){
   introducao();
   menu();
   saida(); 
    return 0;
}