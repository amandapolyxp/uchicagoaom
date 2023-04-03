#include "model_lists.h"

bool calculate(struct base *pl, int *pmax, int *pmin, int *pmean);

int main() {
    int i;

    struct base list;
    init(&list);

    int mat[] = {929, 202, 984, 4, 33, 21, 2};
    
    for (i = 0; i < sizeof(mat)/ sizeof(int); i++) {

        if (!push(&list, mat[i])){
            printf("Error located: %d\n", list.head_list);
            break;
        }
    }

    int min, max, mean;
    if(!calculate(&list, &max, &min, &mean))
        printf("Impossible calculation\n");
    else
        printf("Min: %d Max: %d mean: %d", min, max, mean);

    return 0;
}

bool calculate(struct base *pl, int *pmax, int *pmin, int *pmean){

    int mat[20];
    int i, j, min, max, mean;

    for(i = 0; i < 20; i++){
        if(!(pop(pl, &mat[i])))
            break;
    }
    if(i >= 20) {
        if(pop(pl, &j))
            return false;
    }
    max = min = mat[0];
    mean = 0;
    for (j = 0; j < i ; j++) {
        if (min > mat[j])
            min = mat[j];
        if (max < mat[j])
            max = mat[j];
        mean = mean + mat[j];
    }
    mean = mean / i;
    *pmax = max;
    *pmin = min;
    *pmean = mean;

    for(j = 0; j < i; j++){
        push(pl, mat[i]);
    }

    return true;
}

void init(struct base *pf) {
    pf->tam = TAMLIST;

    pf->head_list = TAMLIST - 1;
    for (int i = 0; i < TAMLIST; i++)
        pf->no[i].occup = false;
}

bool push(struct base *pf, int number) {
    int i;
 
    for (i = pf->tam - 1; i >= 0 && pf->no[i].occup; i--);
    if (i < 0) {
     
        return false;
    }
    
    pf->no[i].num = number;

    
    if (!(pf->no[pf->head_list].occup)) {
        
        pf->head_list = i;
        pf->no[i].mens_next = -1;
    } else {
       
            
            pf->no[i].mens_next = pf->head_list;
            pf->head_list = i;

    }
    pf->no[i].occup = true;
    return true;
}

bool pop(struct base *pf, int *pnumber) {
    int i, j;
    if (!pf->no[pf->head_list].occup) {
     
        return false;
    }

    
    j = -1;
    for (i = pf->head_list; pf->no[i].mens_next != -1; i = pf->no[i].mens_next)
        j = i;

    if (j != -1)
        
        pf->no[j].mens_next = -1;

    pf->no[i].occup = false;
    *pnumber = pf->no[i].num;

    return true;
}
