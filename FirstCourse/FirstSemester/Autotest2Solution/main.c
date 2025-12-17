#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int m;
    int n;
    int size;
    int* arr;
    double sred_ar;

}SmartArray;


int main(void){
    SmartArray sm;
    int tmp = 0;
    FILE * f = fopen("input.txt", "r");
    FILE * out = fopen("output.txt", "w");

    if (!f){
        return -1;
    }
    if (!out){
        return -1;
    }

    sm.size = 0;
    sm.sred_ar = 0;

    while(fscanf(f, "%d", &tmp) == 1){
        sm.size++;
    }

    if(sm.size < 3){
        return -1;
    }

    rewind(f);

    sm.size = sm.size - 3;

    fscanf(f,"%d", &sm.m);

    fscanf(f,"%d", &sm.n);
    if (sm.n == 0){
        return -1;
    }

    fscanf(f,"%d", &tmp);
    if (tmp > sm.size){
        return -1;
    }

    sm.arr = (int*)malloc((size_t)sm.size * sizeof(int));

    for (int i = 0; i < sm.size; i++){
        fscanf(f,"%d", &sm.arr[i]);

        sm.sred_ar += (double)sm.arr[i]/sm.size;
    }

    fclose(f);

    for (int i = 1; i < sm.size-1; i++){
        if (((double)sm.arr[i] <= sm.sred_ar * sm.m / sm.n) && ((double)sm.arr[i] >= sm.sred_ar * sm.m / sm.n)){
            tmp = (sm.arr[i-1]+sm.arr[i+1]) / 2;
            sm.arr[i] = tmp;
        }
    }

    for (int  i = 0; i < sm.size; i++){
        fprintf(out, "%d ", sm.arr[i]);
    }

    fclose(out);

    return 0;
}

