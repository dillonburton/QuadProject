#include "solve.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include "seatest.h"

void start_input();
double* start_calc(double, double, double, int);

void all_tests(void);
void tests_fixture_error_check();
void test_error_check();

//double a, b, c;

void test_fixture_error_check(){
        test_fixture_start();      
        run_test(test_error_check);   
        test_fixture_end();       
}

void all_tests( void ){
	test_fixture_error_check();   
}

void test_error_check(){
    // known formula: x^2 + 3x - 4 = 0
    // known answer: x == -4 and x == 1

    // the formula we are applying sqrt to is
    // b^2 - 4ac = 3^2-4*1*-4 = 25
    // so set sqrt input to 25 and expected returned output to 5
    setSqrt(25,5);
    
    double* ans = start_calc(1,3,-4,1);
    assert_double_equal(-4, ans[0], 0);
    assert_double_equal(1, ans[1], 0);

    // checkSqrt() takes our input of 25
    // and plugs it in to the actual sqrt formula from math.h
    // then checks that our expected output is within tolerance
    assert_true(checkSqrt());
	
}

void start_input(){
    //get user input
    printf("a*x*x + b*x + c = 0\n");
    double a=input('a');
    double b=input('b');
    double c=input('c');
    printf("\n");
    start_calc(a, b, c, 0);
}

double* start_calc(double a, double b, double c, int debug){
	//solve equation
    double* answers=(double*)calloc(2,sizeof(double));
    int count=solve(a,b,c,answers,debug);
    if (!debug) {
	    if(count<0) printf("Infinitely many solutions\n");
	    else {
		printf("%d solutions:\n",count);
		int i;
		for(i=0;i<count;i++) printf("  x=%.4f\n",answers[i]);
	    }
    }
    return answers;
}

int main(int argc, char **argv){

	if(argv[1]){
		run_tests(all_tests);
	}else{
		start_input();
	}

    return 0;
}

