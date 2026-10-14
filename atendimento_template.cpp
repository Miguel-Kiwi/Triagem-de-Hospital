
#include <iostream>
#include <string>
using namespace std;


struct No {
    string nome;
    int    urgencia;   // 1=baixa, 2=media, 3=alta (usado apenas por Paciente)
    No*    prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};


struct FilaPacientes {
    No* frente = nullptr;
    No* tras   = nullptr;

  
    void enqueue(const string& nome, int urgencia) {
        No* novo = new No(nome, urgencia);
        if (isEmpty()) {
            frente = novo;
            tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
    }


    string dequeue() {
        if (isEmpty()) return "";

        No* temp = frente;
        string nomeSalvo = temp->nome;

        frente = frente->prox;
        if (frente == nullptr) {
            tras = nullptr;
        }

        delete temp; 
        return nomeSalvo;
    }


    string frente_peek() const {
        if (isEmpty()) return "";
        return frente->nome;
    }

    bool isEmpty() const { return frente == nullptr; }

    int tamanho() const {
        int cont = 0;
        No* p = frente;
        while (p != nullptr) {
            cont++;
            p = p->prox;
        }
        return cont;
    }

    ~FilaPacientes() {
        while (!isEmpty()) dequeue();
    }
};

struct PilhaHistorico {
    No* topo = nullptr;

 
    void push(const string& nome) {
        No* novo = new No(nome);
        novo->prox = topo;
        topo = novo;
    }

   
    string pop() {
        if (isEmpty()) return "";

        No* temp = topo;
        string nomeSalvo = temp->nome;

        topo = topo->prox;
        delete temp;

        return nomeSalvo;
    }

    
    string peek() const {
        if (isEmpty()) return "";
        return topo->nome;
    }

    bool isEmpty() const { return topo == nullptr; }

    ~PilhaHistorico() {
        while (!isEmpty()) pop();
    }
};
