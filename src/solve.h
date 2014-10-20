//returns the number of solutions for x of the equation a*x*x + b*x + c = 0
//this will be either zero, one, or two, or negative one
//(if there are infinitely many solutions)
//if there are one or two solutions,
//they are stored at the address given by the pointer answers
//if there are two solutions, they are stored in ascending order
int solve(double,double,double,double*);