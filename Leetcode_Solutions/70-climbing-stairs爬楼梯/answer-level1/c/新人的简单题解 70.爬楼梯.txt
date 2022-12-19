### 解题思路
最简单的递推dp，分最后一步上1阶还是两阶讨论

### 代码

```c
int climbStairs(int n)
{
    int* dp=(int*)malloc(sizeof(int)*(n+1));
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 3;
    dp[1]=1;dp[2]=2;dp[3]=3;
    for(int i=4;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
```