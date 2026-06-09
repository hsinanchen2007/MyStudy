### 解题思路
利用动态规划的思想来做这题，首先确定状态表示为f[i][j]，状态计算分为3中不用的情况
insert：f[i][j] = f[i][j-1] + 1
delete: f[i][j] = f[i-1][j] + 1
replace 分为两种：最后一位相同：f[i][j] = f[i-1][j-1]
不同f[i][j] = f[i-1][j-1] + 1
求这四种情况的最小值，首先还要init状态

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        dp = [[0] * (m+1) for i in range(n+1)]
        # 初始化状态值
        for i in range(n+1):
            dp[i][0] = i
        for j in range(m+1):
            dp[0][j] = j
        for i in range(1, n+1):
            for j in range(1, m+1):
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1])
                else:
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1)
        return dp[n][m]
```