### 解题思路
分析这个问题，会发现本质上和 礼物的最大价值 那题是一样的
定义一个数组dp，设到(i,j)的所有路径数为dp\[i]\[j]，因为到(i,j)的路径要么从dp\[i-1]\[j]下来，要么从dp[i]\[j-1]向右，那么计算dp\[i]\[j]的值，就变成：`dp[i][j] = dp[i-1][j] + dp[i][j-1]`

### 代码

```golang
func uniquePaths(m int, n int) int {
    dp := make([][]int, n)
    for i := 0;i < n;i++ {
        dp[i] = make([]int, m)
    }
    for i := 0;i < n;i++ {dp[i][0] = 1}
    for i := 0;i < m;i++ {dp[0][i] = 1}

    for i := 1;i < n;i++ {
        for j := 1;j < m;j++ {
            dp[i][j] = dp[i][j-1] + dp[i-1][j]
        }
    }
    return dp[n-1][m-1]
}
```