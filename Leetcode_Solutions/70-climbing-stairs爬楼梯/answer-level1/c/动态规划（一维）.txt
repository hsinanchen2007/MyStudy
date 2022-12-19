### 解题思路
用递归，超时，用动态规划通过。

### 代码

```c
int climbStairs(int n){
    int *dp;
    int size = sizeof(int) * (n + 1);

    dp = (int *)malloc(size);
    memset(dp, -1, size);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i ++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
```