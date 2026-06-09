### 解题思路
状态转移方程：g[i][j] += min{ g[i-1][j], g[i][j-1] }
### 代码

```golang
//动态规划解法，时间复杂度O(n^2),空间复杂度O(1)
func minPathSum(grid [][]int) int {
    
    m := len(grid)
    if m == 0 {
        return 0
    }
    n := len(grid[0])
    if n == 0 {
        return 0
    }

    for i:=1; i<m; i++ {
        grid[i][0] += grid[i-1][0]
    }
    for j:=1; j<n; j++ {
        grid[0][j] += grid[0][j-1]
    }

    for i:=1; i<m; i++ {
        for j:=1; j<n; j++ {
            if grid[i][j-1] > grid[i-1][j] {
                grid[i][j] += grid[i-1][j]
            } else {
                grid[i][j] += grid[i][j-1]
            }
        }
    }
    return grid[m-1][n-1]
}
```