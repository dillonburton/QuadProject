#include "solve.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    //get user input
    printf("a*x*x + b*x + c = 0\n");
    double a=input('a');
    double b=input('b');
    double c=input('c');
    printf("\n");

    //solve equation
    double* answers=(double*)calloc(2,sizeof(double));
    int count=solve(a,b,c,answers);
    if(count<0) printf("Infinitely many solutions\n");
    else{
        printf("%d solutions:\n",count);
        int i;
        for(i=0;i<count;i++) printf("  x=%.4f\n",answers[i]);
    }

    return 0;
}
