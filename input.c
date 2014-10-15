#include <stdio.h>
#include <stdlib.h>



//ask the user for a line of input
double input(char prompt){
    printf("%c=",prompt);
    char* line=NULL;
    size_t size;
    getline(&line,&size,stdin);
    return atof(line);
}