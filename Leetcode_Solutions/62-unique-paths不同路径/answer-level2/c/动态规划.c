![Screenshot from 2020-03-24 11-48-47.png](https://pic.leetcode-cn.com/e2ace00f09ddcdc971e77bf30055192f7d7ff044892b9d42482019bff58797b6-Screenshot%20from%202020-03-24%2011-48-47.png)

i=0 || j=0 ，dp[i][j] = 1;
i>0 && j>0 , dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```c
int uniquePaths(int m, int n)
{
    int i, j, dp[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i - 1 < 0 || j - 1 < 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}
```
