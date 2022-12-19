```
int climbStairs(int n){
    int dp[n+1];
    dp[0] = 1;//没上台阶
    dp[1] = 1;//上第一个台阶
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    return dp[n];
}
```
