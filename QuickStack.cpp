#include <iostream>
using namespace std;

typedef int tipo;
class list
{
    public:
        tipo dado;
        list* next;
};
class stack
{
    private:
        list* prato;
    public:
        tipo top();
        bool is_empty();
        void push(tipo dado);
        void pop();
};
tipo stack::top(){return prato->dado;}
bool stack::is_empty(){return prato == NULL;}
void stack::push(tipo dado)
{
    list* novo = new list;
    novo->next = prato;
    novo->dado = dado;
    prato = novo;
}
void stack::pop()
{
    if(is_empty())
    {
        cout << "Pilha vazia!" << endl;
    }
    else
    {
        list* head = prato;
        prato = prato->next;
        delete head;
    }
}




// TESTANDO STACK SIMPLES
string int_to_bin(int n)
{
    stack reverse;
    string binario;

    while(n != 0)
    {
        reverse.push(n%2);
        n = (int)(n/2);
    }

    while(!reverse.is_empty())
    {
        binario.append(to_string(reverse.top()));
        reverse.pop();
    }

    return binario;
}
int main()
{
    int input;
    string output;

    cout << "Digite um inteiro:" << endl;
    scanf("%i", &input);

    output = int_to_bin(input);
    cout << "\nO valor em binario eh:\n" << output << endl << endl;
    return 0;
}