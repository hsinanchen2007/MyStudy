### 解题思路
此处撰写解题思路

### 代码

```c
int cuttingRope(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            dp[i]=dp[i]>(dp[j]*(i-j))?dp[i]:(dp[j]*(i-j));
            dp[i]=dp[i]>(j*(i-j))?dp[i]:(j*(i-j));
        }
    }
    return dp[n];
}
```