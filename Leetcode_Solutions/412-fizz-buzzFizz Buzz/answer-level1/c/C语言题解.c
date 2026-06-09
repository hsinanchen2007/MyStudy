
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char** res = (char**)malloc(sizeof(char*)*n);
    int i;
    int m = n;
    for(i=0;i<m;i++)
    {
        n = i+1;
        if(n%3==0 && n%5!=0)
        {
            char* s = (char*)malloc(sizeof(char)*5);
            strcpy(s,"Fizz");
            res[i] = s;
        }
        else if(n%3!=0 && n%5==0)
        {
            char* s = (char*)malloc(sizeof(char)*5);
            strcpy(s,"Buzz");
            res[i] = s;
        }
        else if(n%3==0 && n%5==0)
        {
            char* s = (char*)malloc(sizeof(char)*9);
            strcpy(s,"FizzBuzz");
            res[i] = s;
        }
        else
        {
            char* s = (char*)malloc(sizeof(char)*11);
            sprintf(s,"%d",n);
            res[i] = s;
        }
    }
    *returnSize = n;
    return res;
}
```