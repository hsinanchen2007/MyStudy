### 解题思路
动态规划的优化方法,空间复杂度O(m+n)

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        if m == n == 1:
            return grid[0][0]
        dp = [grid[0][0]]
        for i in range(1, n):
            dp.append(dp[i-1] + grid[0][i])
        left = [grid[0][0]]
        for j in range(1,m):
            left.append(left[j-1] + grid[j][0])
        for i in range(1, m):
            dp[0] = left[i]
            for j in range(1, n):
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j]
        return dp[-1]

```