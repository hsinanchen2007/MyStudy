主要是如何把`dp`压成1维
初始化`dp` 为`grid`第一行的前缀和,然后运用公式去遍历`grid`的剩下几行就可以,公式为
```
i为行, j为列
如果是第0列, 只有一种走法就是从上面一行的第0列走下来
dp[0] += grid[i][0] 
如果是其他列, 可以选择从上一行同一列和当前行前一列走过来
dp[j] = max(dp[j-1], dp[j]) + grid[i][j] 
```

```python
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        dp = [0] * n
        for idx, _ in enumerate(grid[0]):
            if idx == 0:
                dp[idx] = _
            else:
                dp[idx] = _ + dp[idx - 1]
        for i in range(1, m):
            for j in range(n):
                if j == 0:
                    dp[j] += grid[i][j]
                else:
                    dp[j] = max(dp[j-1], dp[j]) + grid[i][j]
        return dp[-1]
```