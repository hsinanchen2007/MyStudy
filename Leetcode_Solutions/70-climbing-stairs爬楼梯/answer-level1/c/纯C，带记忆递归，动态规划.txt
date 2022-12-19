### 解题思路
直接上代码吧  思路很简单

### 代码

```c
/*int helper(int i, int n, int* memo)
{
    if(i>n)
    {
        return 0;
    }
    if(i==n)
    {
        return 1;
    }
    if(memo[i]>0)
    {
        return memo[i];
    }
    memo[i]=helper(i+1, n, memo)+helper(i+2, n, memo);
    return memo[i];
}//带记忆的递归
int climbStairs(int n){
    int* memo=(int*)malloc(sizeof(int)*(n+1));
    memset(memo, 0x00, sizeof(int)*(n+1));
    return helper(0, n, memo);
}*/

//动态规划，dp[i]=dp[i-1]+dp[i-2];
int climbStairs(int n){
    if(n==1) return 1;
    int* dp=(int*)malloc(sizeof(int)*(n+1));
    memset(dp, 0x00, sizeof(int)*(n+1));
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
```