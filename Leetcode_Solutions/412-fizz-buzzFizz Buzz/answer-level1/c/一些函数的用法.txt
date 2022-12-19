### 解题思路
逻辑很简单，但是要知道strcpy(),sprintf()这两个函数的用法

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char **res;
    char *s;
    int i;
    res=(char **)malloc(sizeof(char *)*n);
    for(i=1;i<=n;i++){
        if(i%3==0&&i%5==0){
            s=(char *)malloc(sizeof(char)*9);
            strcpy(s,"FizzBuzz");
            res[i-1]=s;
        }
        else if(i%3==0){
            s=(char *)malloc(sizeof(char)*5);
            strcpy(s,"Fizz");
            res[i-1]=s;
        }
        else if(i%5==0){
            s=(char *)malloc(sizeof(char)*5);
            strcpy(s,"Buzz");
            res[i-1]=s;
        }
        else{
            s=(char *)malloc(sizeof(char)*11);
            sprintf(s,"%d",i);
            res[i-1]=s;

        }
    }
    *returnSize=n;
    return res;


}
```