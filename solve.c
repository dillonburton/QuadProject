#include <math.h>



//returns the number of solutions for x of the equation a*x*x + b*x + c = 0
//this will be either zero, one, or two, or negative one
//(if there are infinitely many solutions)
//if there are one or two solutions,
//they are stored at the address given by the pointer answers
//if there are two solutions, they are stored in ascending order
int solve(double a,double b,double c,double* answers){
    double tolerance=.00001; //margin of error for floating point equality

    if(a>-tolerance && a<tolerance){
        //linear equation (a=0)
        if(b>-tolerance && b<tolerance)
            return c>-tolerance && c<tolerance? -1:0;
        answers[0]=-c/b;
        return 1;
    }

    double disc=b*b-4*a*c,num=-b,denom=2*a;
    if(disc<0) return 0;
    if(disc<tolerance){
        answers[0]=num/denom;
        return 1;
    }

    //two solutions exist
    disc=sqrt(disc);
    answers[0]=(num-disc)/denom;
    answers[1]=(num+disc)/denom;
    return 2;
}