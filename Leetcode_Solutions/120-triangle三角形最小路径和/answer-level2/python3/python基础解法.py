### 解题思路
使用动态规划的思想来完成这道题，主要的状态计算方程是dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]，初始状态dp[0][0] = triangle[0][0]

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        if n == 0:
            return 0
        # 建dp空间
        dp = [[0] * n for i in range(n)]
        dp[0][0] = triangle[0][0]

        for i in range(1, n):
            for j in range(i + 1):
                if j == 0:
                    dp[i][j] = dp[i - 1][j] + triangle[i][j]
                elif j == i:
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j]
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]
        return min(dp[-1])

        # row = len(triangle)
        # dp = [0] * row
        # for i in range(len(triangle[-1])):
        #     dp[i] = triangle[-1][i]
        # for i in range(row - 2, -1, -1):
        #     for j in range(i + 1):
        #         dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]
        # return dp[0]
```