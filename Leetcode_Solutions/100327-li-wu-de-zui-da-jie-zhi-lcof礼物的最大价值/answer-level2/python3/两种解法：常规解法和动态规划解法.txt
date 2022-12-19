# 常规解法代码
```
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        if not m or not n: return 0
        for i in range(m):
            for j in range(n):
                grid[i][j] += max(i>0 and grid[i - 1][j], j>0 and grid[i][j - 1])
        return grid[-1][-1]
```
**复杂度分析**

1. 时间复杂度：O(M * N)
2. 空间复杂度：O(1)
# 动态规划代码
```
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        if not m or not n: return 0
        dp=[[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                dp[i][j]=grid[i-1][j-1]+max(dp[i-1][j],dp[i][j-1])
        return dp[-1][-1]
```
**复杂度分析**

1. 时间复杂度：O(M * N)
2. 空间复杂度：O(M * N)

