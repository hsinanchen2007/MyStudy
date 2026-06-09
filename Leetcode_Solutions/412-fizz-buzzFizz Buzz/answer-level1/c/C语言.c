逻辑挺简单的，对C语言来说主要考察二级指针
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char** fizzBuzz(int n, int* returnSize)
{
    *returnSize = n;
    char** r    = (char**)malloc(n * sizeof(char*));
    for(int i = 1; i <= n; i++)
    {
        r[i - 1] = (char*)calloc(10, 1);
        if((i % 15) == 0)
            strcpy(r[i - 1], "FizzBuzz");
        else if((i % 3) == 0)
            strcpy(r[i - 1], "Fizz");
        else if((i % 5) == 0)
            strcpy(r[i - 1], "Buzz");
        else
            sprintf(r[i - 1], "%d", i);
    }
    return r;
}

int main(void)
{
    int    n;
    char** s;
    s = fizzBuzz(5, &n);

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }
    return 0;
}

```