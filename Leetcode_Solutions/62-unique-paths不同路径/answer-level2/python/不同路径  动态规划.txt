### 解题思路
空间复杂度可优化

### 代码

```python
class Solution(object):
    def uniquePaths(self, m, n):
        dp = [[1]*n for _ in range(m)]
        #到达dp[i][j]的路径数取决于到达dp[i][j-1]和dp[i-1][j]的路径数之和
        if m >= 2 and n >= 2:
            for i in range(1,m):
                for j in range(1,n):
                    dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[-1][-1]
```