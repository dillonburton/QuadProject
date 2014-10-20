#include "solve.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include "seatest.h"

void start_input();
double* start_calc(double, double, double);
void start_tests();
void tests_fixture_error_check();
void test_error_check();

double a, b, c;

void all_tests( void ){
	test_fixture_error_check();   
}

void test_fixture_error_check( void ){
        test_fixture_start();      
        run_test(test_error_check);   
        test_fixture_end();       
}

void test_error_check(){
    double* ans = start_calc(1,-3,-4);
    assert_double_equal(ans[0], -1, 0);
    assert_double_equal(ans[1], 4, 0);
}

int main(int argc, char **argv){

	if(argv[1]){
		start_tests();
	}else{
		start_input();
	}

    return 0;
}

void start_tests(){
	run_tests(all_tests);
}

void start_input(){
    //get user input
    printf("a*x*x + b*x + c = 0\n");
    a=input('a');
    b=input('b');
    c=input('c');
    printf("\n");
    start_calc(a, b, c);
}

double* start_calc(double a, double b, double c){
	//solve equation
    double* answers=(double*)calloc(2,sizeof(double));
    int count=solve(a,b,c,answers);
    if(count<0) printf("Infinitely many solutions\n");
    else{
        printf("%d solutions:\n",count);
        int i;
        for(i=0;i<count;i++) printf("  x=%.4f\n",answers[i]);
    }
    return answers;
}


