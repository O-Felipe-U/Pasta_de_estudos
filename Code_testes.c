#include <stdio.h>

#define fantasma 0
#define Max 27
#define sinal -1

typedef struct
{
    int tam;
    int tab[Max];
} ListaP;

ListaP coypLista(ListaP *ap);
void clearLista(ListaP *ap);
void extendLista(ListaP *ap1, ListaP *ap2);

int main()
{
    ListaP A = {9, {sinal, 1, 2, 3, 4, 5, 46, 7, 8, 9}};
    ListaP B;

    B = coypLista(&A);
    printf("Valores copiados: ");
    for (int i = 1; i <= B.tam; i++)
    {
        printf(" %d  ", B.tab[i]);
    }

    extendLista(&B, &A);
    printf("\nLista extendida");
    for (int i = 1; i <= B.tam; i++)
    {
        printf(" %d  ", B.tab[i]);
    }
    printf("\nTamanho dessa lista: %d", B.tam);

    clearLista(&B);
    printf("\nLista limpa: ");
    for (int i = 1; i <= B.tam; i++)
    {
        printf(" %d  ", B.tab[i]);
    }
    return 0;
}

ListaP coypLista(ListaP *ap)
{
    ListaP T;
    int k, n;
    n = ap->tam;
    T.tam = n;
    for (k = 1; k <= n; k++)
    {
        T.tab[k] = ap->tab[k];
    }
    return T;
}

void clearLista(ListaP *ap)
{
    ap->tam = 0;
}

void extendLista(ListaP *ap1, ListaP *ap2)
{
    int k, n, y, i;
    i = 1;
    n = ap1->tam;
    y = ap2->tam;
    ap1->tam = n + y;
    for (k = n + 1; k <= (n + y); k++)
    {
        ap1->tab[k] = ap2->tab[i];
        i++;
    }
}