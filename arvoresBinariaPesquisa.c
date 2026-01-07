#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TipoChave;

typedef struct arvores
{
    TipoChave chave;
    struct arvores *esq, *dir;
} NO;


// Prototipacoes
typedef NO *PONT;
PONT inicializaArvore(TipoChave chave);
PONT inserir(TipoChave chave, PONT raiz);
PONT busca(TipoChave chave, PONT raiz);
bool vazia(PONT raiz);
void imprime(PONT raiz);

int main()
{
    PONT raiz = inicializaArvore(50);
    inserir(40, raiz);
    inserir(70, raiz);

    imprime(raiz);

    return 0;
}

PONT inicializaArvore(TipoChave chave)
{
    PONT raiz = (PONT)malloc(sizeof(NO));
    if (raiz == NULL)
        return NULL;

    raiz->chave = chave;
    raiz->esq = NULL;
    raiz->dir = NULL;

    return raiz;
}


PONT inserir(TipoChave chave, PONT raiz)
{
    if (raiz == NULL)
    {
        return inicializaArvore(chave);
    }

    if (chave > raiz->chave)
    {
        raiz->dir = inserir(chave, raiz->dir);
    }
    else
    {
        raiz->esq = inserir(chave, raiz->esq);
    }
}

PONT busca(TipoChave chave, PONT raiz)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (chave == raiz->chave)
    {
        return raiz;
    }

    if (chave > raiz->chave)
    {
        return busca(chave, raiz->dir);
    }
    else
    {
        return busca(chave, raiz->esq);
    }
}

bool vazia (PONT a)
{
    return a == NULL;
}

void imprime (PONT raiz)
{
    if (!vazia(raiz))
    {
        printf("%i ", raiz->chave);
        imprime(raiz->esq);
        imprime(raiz->dir);
    }
}