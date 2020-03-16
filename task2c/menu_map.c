#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char encrypt(char c);
char censor(char c);
char* map(char *array, int array_length, char (*f) (char));
char decrypt(char c);
char xprt(char c);
char cprt(char c);
int between(char c);
char my_get(char c);
char quit(char c);

char censor(char c) {
  if(c == '!')
    return '.';
  else
    return c;
}
 
 
int between(char c)
{
    if((0x20 <= c) && (c <= 0x7E))
    {
        return 1;
    }
    return 0;
}



char* map(char *array, int array_length, char (*f) (char))
{
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    int i=0;
    
    for(i=0; i<array_length; i++)
    {
        mapped_array[i] = (*f)(array[i]);
    }
    return mapped_array;
}

char encrypt(char c)
{
    
    if(between(c) == 1)
    {
        c+=3;
    }  
    
    return c;
}

char decrypt(char c)
{
    
    if(between(c) == 1)
    {
        c-=3;
    }  
    
    return c;
    
    
}
char xprt(char c)
{
    fprintf( stderr, "%#04X\n", c );
    return c;
}
char cprt(char c)
{
    if (between(c) == 1)
    {
        fprintf( stderr, "%c\n", c );
    }
    else
    {
        fprintf(stderr, ".\n");
    }
    return c;
    
}
char my_get(char c)
{
    char newChar = fgetc(stdin);
    return newChar;    
    
}

char quit(char c)
{
    exit(0);

}

int main(int argc, char **argv)
{
    
int base_len = 5;
char arr1[base_len];
char* arr2 = map(arr1, base_len, my_get);

char* arr3 = map(arr2, base_len, encrypt);
// printf("FLAG2:  %s\n", arr3);
char* arr4 = map(arr3, base_len, xprt);
char* arr5 = map(arr4, base_len, decrypt);
char* arr6 = map(arr5, base_len, cprt);
free(arr2);
free(arr3);
free(arr4);
free(arr5);
free(arr6);
    
    return 0;
}


/*

cd Desktop/splab/lab2/task2b
*/








