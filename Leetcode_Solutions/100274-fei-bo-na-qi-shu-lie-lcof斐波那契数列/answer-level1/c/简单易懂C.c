### 解题思路
控制循环次数：n= 2 3 循环一次，因此限制条件  <n/2

### 代码

```c
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    long a=0,b=1;
    for(int i=0;i<n/2;i++){
        a=(a+b)%1000000007;
        b=(a+b)%1000000007;
    }
    return n%2==0?a:b;
}
```