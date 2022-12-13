#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils/utils.h"

#define LOWER 1
#define UPPER 5

FILE *timelist;

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
    printf("Input N:");
    scanf("%d",&N);
    const int A = N;
    timelist = fopen("timelist.dat","w");
    clock_t t;
    srand(time(0));
    
    for(N; N <= A*100; N = N+A){

    int* M = (int *) malloc(N*N*sizeof(int));
    int* v = (int *) malloc(N*sizeof(int));
    int* b = (int *) malloc(N*sizeof(int));

    if(M == NULL | v == NULL){
        printf("Malloc is failed \n");
        exit(0);
    } else {
        t = clock();
        matVecMult(M,v,b,N);
        t = clock() - t;
    }
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(timelist,"(%d,%f),", N, time_taken);
    
    free(M);
    free(v);
    free(b);
    }
   
    return 0;
}