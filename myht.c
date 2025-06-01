#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

int main()
{
    struct hNo **t1, **t2;
    int value, instruction = getc(stdin);
    t1 = createTable();
    t2 = createTable();
    if ((!t1) || (!t2))
        return -1;

    while (instruction != EOF)
    {
        fscanf(stdin, "%u", &value);

        if (instruction == 105)
        {
            hashInclude(t1, t2, value);
        }
        else if (instruction == 114)
        {
            if (hashExclude(t1, t2, value) < 0)
                fprintf(stdout, "O valor %u nao esta na tabela", value);
        }
        instruction = getc(stdin);
    }
    hashPrint(t1, t2);
    freeTable(t1);
    freeTable(t2);
}