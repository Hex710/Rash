#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hash.h"

#define M 11

int freeTable(struct hNo **table)
{
    if (!table)
        return -1;

    for (int i = M; i >= 0; i--)
    {
        if (table[i] != NULL)
            free(table[i]);
    }

    free(table);

    return 0;
}

struct hNo **createTable()
{
    struct hNo **table;
    if (!(table = malloc(M * sizeof(struct hNo))))
        return NULL;

    for (int i = 0; i < M; i++)
    {
        if (!(table[i] = malloc(sizeof(struct hNo))))
        {

            freeTable(table);

            return NULL;
        }

        table[i]->chave = i;

        table[i]->status = 0;
    }

    return table;
}

int hashDiv(int k)
{
    return (k % M);
}

int hashMul(int k)
{
    double indice = floor(M * (k * 0.9 - floor(k * 0.9)));

    return (int)indice;
}

int hashInclude(struct hNo **t1, struct hNo **t2, int k)
{
    if ((!t1) || (!t2))
        return -1;

    int indice = hashDiv(k);

    if (t1[indice]->status != 0)
    {

        t2[hashMul(t1[indice]->valor)]->status = 1;

        t2[hashMul(t1[indice]->valor)]->valor = t1[indice]->valor;
    }

    t1[indice]->status = 1;

    t1[indice]->valor = k;

    return 0;
}

int hashSearch(struct hNo **t1, struct hNo **t2, int k)
{
    if ((!t1) || (!t2))
        return -1;

    int indice = hashDiv(k);

    if ((t1[indice]->valor == k) && (t1[indice]->status == 1))
        return indice;
    else
    {
        indice = hashMul(k);

        if ((t2[indice]->valor == k) && (t2[indice]->status == 1))
            return indice;
        else
            return -1;
    }
}

int hashExclude(struct hNo **t1, struct hNo **t2, int k)
{
    if ((!t1) || (!t2))
        return -1;

    int indice = hashSearch(t1, t2, k);

    if (indice == -1)
        return -2;

    if ((t2[indice]->valor == k) && (t2[indice]->status == 1))
    {
        t2[indice]->status == 0;

        return 0;
    }
    else if ((t1[indice]->valor == k) && (t1[indice]->status == 1))
    {
        t1[indice]->status == 0;

        return 0;
    }
}

int hashPrint(struct hNo **t1, struct hNo **t2)
{
    if ((!t1) || (!t2))
        return -1;

    for (int i = 0; i < M; i++)
    {
        if (t1[i]->status == 1)
            fprintf(stderr, "%u, T1, %u\n", t1[i]->valor, t1[i]->chave);

        if (t2[i]->status == 1)
            fprintf(stderr, "%u, T2, %u\n", t2[i]->valor, t2[i]->chave);
    }

    return 0;
}