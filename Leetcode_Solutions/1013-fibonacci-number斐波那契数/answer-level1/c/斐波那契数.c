**递归**
```
int fib(int n)
{
    if(n < 2)
        return n;
    return fib(n-1) + fib(n-2);
}
```
**迭代**
```
int fib(int n)
{
    if(n < 2)
        return n;
    if(n == 2)
        return 1;
    int cur, pre = 1, prepre = 1, i;
    for(i = 3; i <= n; i++){
        cur = pre + prepre;
        prepre = pre;
        pre = cur;
    }
    return cur;
}
```
**动态规划**
```
int fib(int n)
{
    if(n < 2)
        return n;
    int *dp = (int*)malloc(sizeof(int) * (n+1));
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```
