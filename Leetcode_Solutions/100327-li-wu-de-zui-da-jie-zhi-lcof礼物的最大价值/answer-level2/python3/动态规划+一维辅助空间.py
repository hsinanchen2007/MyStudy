### 解题思路

经典二维dp问题，写出二维dp后自然发现更新的dp值只与两个相邻值有关，所以优化成一维dp解答
其中在dp最左侧添加【0】元素，用以简化边界条件

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        dp = [0]*(m+1)
        for i in range(1,m+1):
            dp[i] = dp[i]+dp[i-1]

        for i in range(n):
            for j in range(1,m+1):
                dp[j] = max(dp[j-1],dp[j])+grid[i][j-1]
        return dp[-1]

```