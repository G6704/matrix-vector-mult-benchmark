#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils/utils.h"

#define LOWER 1
#define UPPER 5

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = generateRandomInt(LOWER,UPPER);
    }
}

int main(void){
    int N;
    srand(time(0));

    printf("Input N:");
    scanf("%d",&N);
    
    int* M = (int *) malloc(N*N*sizeof(int));
    int* v = (int *) malloc(N*sizeof(int));
    int* b = (int *) malloc(N*sizeof(int));

    if(M == NULL | v == NULL){
        printf("Malloc is failed \n");
        exit(0);
    } else {
        initMat(M, N);
        printf("M=");
        printMat(M, N);
        initVec(v, N);
        printf("v=");
        printVec(v, N);
        matVecMult(M,v,b,N);
        printf("b=");
        printVec(b, N);
    }

    free(M);
    free(v);
    free(b);

    return 0;
}