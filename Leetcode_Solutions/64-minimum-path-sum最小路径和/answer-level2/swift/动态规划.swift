某一格当前的路径最小和是到达“前一格”的路径最小和加上该小格上的数字，判断哪一个是”前一格“的方法就是比较左边的和与上边的和哪一个更小，所以： 
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
```
class Solution {
    func minPathSum(_ grid: [[Int]]) -> Int {
        let m = grid.count - 1
        let n = grid[m].count - 1
        var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        for i in 0...m {
            for j in 0...n {
                if i == 0 && j > 0 {
                    dp[i][j] = dp[i][j - 1] + grid[i][j]
                }else if i > 0 && j == 0 {
                    dp[i][j] = dp[i-1][j] + grid[i][j]
                }else if i == 0 && j == 0 {
                    dp[i][j] = grid[i][j]
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
                }
            }
        }
        return dp[m][n]
    }
}
```