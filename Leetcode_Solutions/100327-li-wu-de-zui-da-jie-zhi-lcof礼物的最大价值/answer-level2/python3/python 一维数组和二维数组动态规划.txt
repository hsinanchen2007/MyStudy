利用一维数组，每次该数组 保存上一行
```
def maxValue(self, grid: List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])
    dp = [0 for i in range(n + 1)]

    for i in range(m):
        for j in range(1, n + 1):
            tmp = dp[j]
            dp[j] = max(dp[j - 1], tmp) + grid[i][j - 1]

    return dp[-1]
```

二维数组，常规的
```
def maxValue(self, grid: List[List[int]]) -> int:
    """二维数组"""
    m, n = len(grid), len(grid[0])
    dp = [[0 for i in range(n)] for j in range(m)]
    dp[0][0] = grid[0][0]

    for i in range(1, m):
        dp[i][0] = dp[i - 1][0] + grid[i][0]

    for i in range(1, n):
        dp[0][i] = dp[0][i - 1] + grid[0][i]

    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]

    return dp[m - 1][n - 1]
```
