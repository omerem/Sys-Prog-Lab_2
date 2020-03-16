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




struct fun_desc {
  char *name;
  char (*fun)(char);
};


int main(int argc, char **argv)
{
    char * carray = malloc(sizeof(char) * 5);
    char input[4];
    int option;
    int numberOfOptions = -1;
    int validOption = 1;
    
    struct fun_desc menu[] =
    {
        { "Censor", &censor },
        { "Encrypt", &encrypt },
        { "Decrypt", &decrypt },
        { "Print hex",   &xprt },
        { "Print string", &cprt },
        { "Get string", &my_get } ,
        { "Quit", &quit },
        { NULL, NULL }
    };
    int j = 0;
    while (menu[j].name != NULL)
    {
        j++;
        numberOfOptions = j;
    }
    
    
    
//          fprintf(stderr,"2222");
    
    
     while (0 != 1)
     {
         
        fprintf(stderr, "Please choose a function:\n");
         
         
        for (int i=0; i<numberOfOptions; i++)
        {
            fprintf(stderr, "%d) %s\n", (i), menu[i].name);
        }
        fprintf(stderr, "Option: ");
        
//         fprintf(stderr, "\ninput = %s\n", input);
//         fprintf(stderr, "\ncarray = %s\n", carray);
        fflush(stdin);
        fseek(stdin,0,SEEK_END);
        fgets(input, 4, stdin);
        sscanf(input, "%d", &option);
//         fprintf(stderr, "\ninput = %s\n", input);
//         fprintf(stderr, "\ncarray = %s\n", carray);
        
        
//         fprintf(stderr, "The option is %d\n", option);
        
        
        if((option >= 0) && (option < numberOfOptions))
        {
            fprintf(stderr, "Within bounds\n");
            validOption = 1;
        }
        else
        {
            fprintf(stderr, "Not within bounds\n");
            validOption = 0;
            exit(0);
        }
         
         carray = map(carray, 5, menu[option].fun);
         
         
        if (validOption == 1)
        {
            fprintf(stderr, "Done.\n\n");
        }
        
     }
    
    free(carray);
    return 0;
}

/*

cd Desktop/splab/lab2/task3
*/







