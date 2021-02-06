#include <iostream>
#include <locale.h>
//#include "arvore.cpp"

using namespace std;

class No
{
public:
    int chave;
    No *dir;
    No *esq;

    No(int chave)
    {
        this->chave = chave;
        dir = NULL;
        esq = NULL;
    }
};


class Arvore
{
public:
    No *raiz;

    Arvore()
    {
        raiz = NULL;
    }

    void inserir(int valor_chave)
    {
        if(raiz == NULL) /*verificando se a raiz existe*/
        {
            raiz = new No(valor_chave);
        }
        else
        {
            inserirAux(valor_chave, raiz);
        }
    }

    void inserirAux(int valor_chave, No *no)
    {
        if(valor_chave <= no->chave) /*se o valor for menor ou igual que o nó atual, vai pra esquerda*/
        {
            if(no->esq == NULL) /*verificando se o nó esq existe*/
            {
                No *novo_no = new No(valor_chave); /*==> PRECISA POIS ELE NÃO ORDENA OS NOVOS VALORES, SÓ O PRIMEIRO*/
                no->esq = novo_no;
                //no = new No(valor_chave);  ///Em Observação
            }
            else
            {
                inserirAux(valor_chave, no->esq); /*se o nó já existe, então um valor já está nele. Fazer busca de novo*/
            }
        }
        else if(valor_chave > no->chave) /*se o valor for maior que o nó atual, vai pra direita */
        {
            if(no->dir == NULL) /*verificando se o nó esq existe*/
            {
                No *novo_no = new No(valor_chave);
                no->dir = novo_no;
                //no = new No(valor_chave);  ///Em Observação
            }
            else
            {
                inserirAux(valor_chave, no->dir); /*se o nó já existe, então um valor já está nele. Fazer busca de novo*/
            }
        }
    }

    void emOrdem(No *no_raiz)
    {
        if(no_raiz != NULL)
        {
            emOrdem(no_raiz->esq);
            cout << no_raiz->chave << "\t";
            emOrdem(no_raiz->dir);
        }
    }
};


int main()
{
    setlocale(LC_ALL,"");

    Arvore abb;

    /*abb.inserir(8);
    abb.inserir(3);
    abb.inserir(1);
    abb.inserir(2);*/

    /*abb.inserir(8);
    abb.inserir(3);
    abb.inserir(10);
    abb.inserir(14);
    abb.inserir(13);
    abb.inserir(1);
    abb.inserir(6);
    abb.inserir(4);
    abb.inserir(7);*/

    int tamanho_vet2 = 10;
    int vet2[tamanho_vet2] = {9, 4, 7, 2, 3, 5, 10, 11, 31, 9};

    for(int i = 0; i < tamanho_vet2; i++)
    {
        abb.inserir(vet2[i]);
    }

    cout << "Percorrendo em ordem..." << endl;
    abb.emOrdem(abb.raiz);

    return 0;
}
