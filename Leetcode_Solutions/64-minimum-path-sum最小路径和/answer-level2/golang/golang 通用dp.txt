```go
/**
* 1. dp数组 定义为到达当前位置是的最短路径值
* 2. dp数组的初始化 第0行与第0列先进行初始化 
        a)dp[0][i] = dp[0][i] + dp[0][i-1]
        b)dp[i][0] = dp[i][0] + dp[i-1][0]
* 2. 递推公式 dp[i][j] = dp[i][j] + min(dp[i-1][j],dp[i][j-1]) 
          即当前最小路径是其做从左过来与从上过来两条路径的最短的取值
* 3. 最终结果取 dp[m-1][n-1]
* 4. 空间优化 复用grid数组即可
*/
func minPathSum(grid [][]int) int {
   m, n:= len(grid), len(grid[0])
    for i:=1;i<n;i++{
        grid[0][i] = grid[0][i] + grid[0][i-1]
    }
    for i:=1;i<m;i++{
        grid[i][0] = grid[i][0] + grid[i-1][0]
    }
   for i:=1;i<m;i++{
       for j:=1;j<n;j++{
           grid[i][j] += min(+grid[i-1][j],grid[i][j-1])
       }
   }
   return grid[m-1][n-1]
}
func min(a,b int)int{
    if a > b{
        return b
    }
    return a
}
```
