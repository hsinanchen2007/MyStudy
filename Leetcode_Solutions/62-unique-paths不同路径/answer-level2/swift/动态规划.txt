每一个方格可以由上一个向右或者上一个向下到达
dp[i][j] = dp[i][j-1] + dp[i-1][j]
```
class Solution {
    func uniquePaths(_ m: Int, _ n: Int) -> Int {
        if m == 0 || n == 0 {
            return 1
        }else if m == 0 && n == 0 {
            return 0
        }
        var dp: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: m)
        for i in 0...m - 1 {
            for j in 0...n - 1 {
                
                if i == 0 && j > 0 {
                    dp[i][j] = dp[i][j - 1]
                }else if i > 0 && j == 0 {
                    dp[i][j] = dp[i-1][j]
                }else if i == 0 && j == 0 {
                    dp[i][j] = 1
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
                }
            }
        }
        return dp[m - 1][n - 1]
    }
}
```