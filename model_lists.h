#include <stdio.h>
#include <stdbool.h>

struct no_fila {
    int num;
    bool occup;
    int mens_next;
};

#define TAMLIST 10

struct base {
    struct no_fila no[TAMLIST];
    int tam;
    int head_list;
};

bool push(struct base *pf, int number);

bool pop(struct base *pf, int *pnumber);

void init(struct base *pf);




