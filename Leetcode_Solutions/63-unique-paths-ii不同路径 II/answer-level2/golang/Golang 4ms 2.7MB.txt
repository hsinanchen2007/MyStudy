### 解题思路
动态规划，动态方程：dp[i][j] = dp[i][j-1] + dp[i-1][j] if obstacleGrid[i][j] == 0 else 0
初始化：for j := 0; j < n; j++ {
        if obstacleGrid[0][j] == 1 {
            break
        }
        dp[0][j] = 1
    }
    for i := 0; i < m; i++ {
        if obstacleGrid[i][0] == 1 {
            break
        }
        dp[i][0] = 1
    }
和之前不同的是最上边一行和最左边一列需要加入障碍物判断，若是某个地方出现了障碍物则该行或该列之后的坐标都无法到达了

### 代码

```golang
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    m, n := len(obstacleGrid), len(obstacleGrid[0])
    dp := makeArray(m, n)
    for j := 0; j < n; j++ {
        if obstacleGrid[0][j] == 1 {
            break
        }
        dp[0][j] = 1
    }
    for i := 0; i < m; i++ {
        if obstacleGrid[i][0] == 1 {
            break
        }
        dp[i][0] = 1
    }
    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            if obstacleGrid[i][j] == 1 {
                continue
            }
            dp[i][j] = dp[i][j-1] + dp[i-1][j]
        }
    }
    return dp[m-1][n-1]
}

func makeArray(m, n int) [][]int {
    dp := make([][]int, m)
    for i := 0; i < m; i ++ {
        dp[i] = make([]int, n)
    }
    return dp
}
```