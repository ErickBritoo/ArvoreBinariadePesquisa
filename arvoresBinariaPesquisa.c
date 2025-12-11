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

typedef NO *PONT;
PONT inicializaArvore(TipoChave chave);
PONT inserir(TipoChave chave, PONT raiz);
PONT busca(TipoChave chave);

int main()
{
    PONT raiz = inicializaArvore(50);
    inserir(40, raiz);
    inserir(70, raiz);

    printf("%i\n", raiz->chave);

    printf("%i\n", raiz->esq->chave);
    printf("%i\n", raiz->dir->chave);

    return 0;
}

PONT inicializaArvore(TipoChave chave)
{
    PONT raiz = (PONT)malloc(sizeof(NO));
    raiz->chave = chave;
    raiz->esq = NULL;
    raiz->dir = NULL;

    free(raiz->dir);
    free(raiz->esq);
    free(raiz);
    raiz = NULL;

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
    if (chave < raiz->chave)
    {
        raiz->esq = inserir(chave, raiz->esq);
    }
}
