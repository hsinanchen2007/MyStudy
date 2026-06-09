# 思路：


# 代码：
```
 #define INT_MAX 11
 char* itos(int number);
char ** fizzBuzz(int n, int* returnSize){
    char **returnarra = malloc(sizeof(char*) * n),
        *fizzbuzz = "FizzBuzz", 
        *fizz = "Fizz",
        *buzz = "Buzz";
    int i;

    for(i = 1; i <= n; i++){
        if(i%3 == 0 && i%5 == 0){
            returnarra[i-1]  = fizzbuzz;    
        }else if(i%3 == 0){
            returnarra[i-1]  = fizz;
        }else if(i%5 == 0){
            returnarra[i-1]  = buzz;
        }else{
            returnarra[i-1]  = itos(i);
        }

    }
    *returnSize = n;
    return returnarra;
}

char* itos(int current){
    char *ans  = malloc(sizeof(char) * INT_MAX),temp;
    int count = 0;

    while(current > 0){
        ans[count++] = current%10 + '0';
        current/= 10;
    }
    ans[count]  ='\0';

    int lo = 0, hi = count - 1;
    
    while(lo < hi){
        temp = ans[lo];
        ans[lo] = ans[hi];
        ans[hi] = temp;
        hi--;
        lo++;
    }
    return ans;
}

```
