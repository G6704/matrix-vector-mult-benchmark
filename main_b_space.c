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
        printf("Input N:");
        scanf("%d",&N);
        printf("CTRL+C to interrupt the process \n");
        srand(time(0));

        while (1){
        int* M = (int *) malloc(N*N*sizeof(int));
        int* v = (int *) malloc(N*sizeof(int));
        int* b = (int *) malloc(N*sizeof(int));

        free(M);
        free(v);
        free(b);
        }
        return 0;
    }