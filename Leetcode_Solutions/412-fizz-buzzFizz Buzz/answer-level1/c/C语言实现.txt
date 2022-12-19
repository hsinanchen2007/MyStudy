C语言实现
```C []
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char **ret = (char**)malloc(n * sizeof(char*));   
    for (int i = 1; i <= n; ++i)
    {
        ret[i - 1] = (char*)malloc(10 * sizeof(char));
        memset(ret[i - 1], 0, 10 * sizeof(char));
        if (0 == i % 3) strcpy(ret[i - 1], "Fizz");
        if (0 == i % 5) strcpy(ret[i - 1] + strlen(ret[i - 1]), "Buzz");
        if (strlen(ret[i - 1]) == 0)
            sprintf(ret[i - 1], "%d", i);
    }
    return ret;
}
```
