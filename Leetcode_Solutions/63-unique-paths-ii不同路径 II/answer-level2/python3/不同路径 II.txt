### 解题思路
我的思路：当list[i][j]为障碍物时，dp[i][j]则为0，其余就是累加。很典型的简单动态规划。
空间复杂度可以继续优化为o(1)

复杂度分析：                                                             
	• 时间复杂度：o(mn)
	• 空间复杂度：o(mn)

### 代码

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid[0])
        m = len(obstacleGrid)
        dp = [[None for _ in range(n)] for _ in range(m)]
        if obstacleGrid[0][0] == 0:
            dp[0][0] = 1
        else:
            dp[0][0] = 0
        for i in range(0,m):
            for j in range(0,n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                elif i == 0 and j != 0:
                    dp[0][j] = dp[0][j-1]
                elif j == 0 and i!= 0:
                    dp[i][0] = dp[i-1][0]
                elif i != 0 and j != 0:
                    dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[m-1][n-1]
```