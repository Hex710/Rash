#ifndef HASH_H
#define HASH_H

struct hNo
{
    int chave;  // representa o indice do no dentro da tabela hash
    int valor;  // representa o valor guardado dentro do noh
    int status; // 0 significa que eh invalido, e 1 que eh valido
};

int freeTable(struct hNo **table);

struct hNo **createTable();

int hashDiv(int k);

int hashMul(int k);

int hashInclude(struct hNo **table, struct hNo **t2, int k);

int hashSearch(struct hNo **table, struct hNo **t2, int k);

int hashExclude(struct hNo **table, struct hNo **t2, int k);

int hashPrint(struct hNo **table, struct hNo **t2);

#endif