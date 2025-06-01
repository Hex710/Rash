#ifndef HASH_H
#define HASH_H

struct hNo
{
    int chave;  // representa o indice do no dentro da tabela hash
    int valor;  // representa o valor guardado dentro do noh
    int status; // 0 significa que eh invalido, e 1 que eh valido
};

/* libera o espaco alocado para a tabela  */
int freeTable(struct hNo **table);

/* aloca o espaco para uma tabela e para cada um dos seus nos, retorna NULL se alguma das alocacoes der errado */
struct hNo **createTable();

/* funcao hash por divisao */
int hashDiv(int k);

/* funcao hash por multiplicacao */
int hashMul(int k);

/* inclui um valor dentro das tabelas hash */
int hashInclude(struct hNo **t1, struct hNo **t2, int k);

/* procura um valor dentro das tabelas hash */
int hashSearch(struct hNo **t1, struct hNo **t2, int k);

/* exclui um valor de dentro das tabelas hash */
int hashExclude(struct hNo **t1, struct hNo **t2, int k);

/* imprime todos os valores de dentro das tabelas hash, do no 0 ate m - 1, imprimindo o no da t1 e entao o da t2 */
int hashPrint(struct hNo **t1, struct hNo **t2);

#endif