### 解题思路
状态定义dp[i][j]：走到(i,j)位置的路径数
状态初始化：因为只能向右或者向下，所以0行j列和i行0列的值初始化为1
状态转移方程dp[i][j] = dp[i-1][j] + dp[i][j-1] :手画个图很好想

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for i in range(m) ]
        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1
        for x in range(1,m):
            for y in range(1,n):
                dp[x][y] = dp[x-1][y] + dp[x][y-1]
        return dp[-1][-1]
        
```