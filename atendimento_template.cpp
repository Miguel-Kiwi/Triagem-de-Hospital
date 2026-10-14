
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
// ════════════════════════════════════════════════════════════════
// R3 · LISTA DE MÉDICOS DISPONÍVEIS (lista encadeada)
// ════════════════════════════════════════════════════════════════
struct ListaMedicos {
    No* head = nullptr;

    // TODO 7: Implemente adicionarMedico(nome)
    void adicionarMedico(const string& nome) {
        No* novo = new No(nome);
        if (head == nullptr) {
            head = novo;
        } else {
            No* p = head;
            while (p->prox != nullptr) {
                p = p->prox;
            }
            p->prox = novo;
        }
    }

    // TODO 8: Implemente chamarMedico()
    string chamarMedico() {
        if (head == nullptr) return "";

        No* temp = head;
        string nomeSalvo = temp->nome;

        head = head->prox;
        delete temp; // libera memória do nó removido

        return nomeSalvo;
    }

    // TODO 9: Implemente percorrer()
    void percorrer(const string& prefixo = "") const {
        if (!prefixo.empty()) cout << prefixo << ": ";
        if (head == nullptr) {
            cout << "(lista vazia)\n";
            return;
        }

        No* p = head;
        while (p != nullptr) {
            cout << p->nome;
            if (p->prox != nullptr) cout << " -> ";
            p = p->prox;
        }
        cout << "\n";
    }

    bool temMedico() const { return head != nullptr; }

    ~ListaMedicos() {
        while (head) {
            No* t = head;
            head  = head->prox;
            delete t;
        }
    }
};
