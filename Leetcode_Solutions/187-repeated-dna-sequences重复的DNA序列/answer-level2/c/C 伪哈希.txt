```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (1024)
char repeat_arr[1048576] = {0};

void insertString(char** outstring, char* s, int* count)
{
    int i;
    int calc = 0;
    char* insertBuf;
    for (i = 0; i < 10; i++)
    {
        if (s[i] == 'A')
        {
            calc = calc * 4;
        }
        else if (s[i] == 'C')
        {
            calc = calc * 4 + 1;
        }
        else if (s[i] == 'G')
        {
            calc = calc * 4 + 2;
        }
        else
        {
            calc = calc * 4 + 3;
        }
        
    }
    
    repeat_arr[calc]++;
    if ( repeat_arr[calc] >=3)
    {
        repeat_arr[calc] = 3;
    }
    
    if (repeat_arr[calc] == 2)
    {
        repeat_arr[calc] = 2;
        insertBuf = malloc(sizeof(char)*11);
        strcpy(insertBuf, s);
        insertBuf[10] = '\0';
        outstring[*count] = insertBuf;
        *count = *count + 1;
    }
    
    return;
}

void copyArray(char* dest, char* src, int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }

    return;
}

char ** findRepeatedDnaSequences(char * s, int* returnSize){
    char ** outstring = NULL;
    int count = 0;
    int len = strlen(s);
    char comp[11];
    
    if (len < 11)
    {
        *returnSize = 0;
        return NULL;
    }
    
    outstring = (char**)malloc(sizeof(char*)*MAX_SIZE);
    memset(repeat_arr, 0, sizeof(repeat_arr));
    
    comp[10] = '\0';
    for (int i = 0; i < len - 9; i++)
    {
        copyArray(comp, s+i, 10);
        insertString(outstring, comp, &count);
    }
    
    *returnSize = count;
    return outstring;
}



```
