# Gerenciador de Times de Futebol

Este projeto foi desenvolvido para a disciplina de **Introdução aos Algoritmos** na UFLA.  
O objetivo é aplicar conceitos fundamentais de programação estruturada, como **CRUD, manipulação de arquivos, algoritmos de busca e ordenação**, em um sistema de gerenciamento de times de futebol.

Autores

Projeto desenvolvido por Rafael Souza Carvalho e João Gabriel Borges da Silva.


---

## Objetivo

O sistema permite o gerenciamento completo de times de futebol, com armazenamento persistente em arquivo `.csv`, além da implementação de algoritmos clássicos de ordenação e busca.

---

## Funcionalidades

- CRUD de Times
  - Cadastro de novos times
  - Listagem de times
  - Alteração de dados
  - Remoção de registros

- Persistência de Dados
  - Leitura e escrita em arquivo `times.csv`

- Algoritmos de Busca
  - Busca sequencial
  - Busca binária (requer dados ordenados)

- Ordenação
  - Selection Sort para organização dos registros

---

## Algoritmos Utilizados

- Busca Sequencial → O(n)  
- Busca Binária → O(log n) (após ordenação)  
- Selection Sort → O(n²)

---

## Estrutura do Projeto
/main.cpp
/funcoes.cpp
/funcoes.h
/times.csv

---

## Como Compilar e Executar

Você precisa de um compilador C++ (g++).

### 1. Clone ou baixe o projeto

```bash
git clone <link-do-repositorio>

 Acesse a pasta do projeto
cd projeto-ialg-futebol
 Compile o código
g++ main.cpp funcoes.cpp -o sistema.exe
 Execute
./sistema.exe

