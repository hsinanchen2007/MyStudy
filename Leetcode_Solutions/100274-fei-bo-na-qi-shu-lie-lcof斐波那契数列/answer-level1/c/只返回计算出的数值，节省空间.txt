### 解题思路


### 代码

```c
int fib(int n){
    if(n == 0 ) return 0;
    long long int i,j,k,h;
    i = 1;
    j = 0;
    h = 1;
    for (k = 0;k< n-1;k++){
        h = (j+i) % (1000000007);
        j = i;
        i = h;
    }
    //h = h%1e9+7;
    return h;

}
```