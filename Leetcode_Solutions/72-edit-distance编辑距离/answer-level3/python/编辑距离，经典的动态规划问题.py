### 解题思路
编辑距离，经典的动态规划问题
设计dp数组，dp[i][j] 表示从 word1[:i] 转换成 word2[:j] 需要几步
若 word1[i-1] == word2[j-1]，则从dp[i-1][j-1]到dp[i][j]不需要编辑
否则 dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])，分别代表 修改，增加，删除一步，从中取最小值
### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1)+1, len(word2)+1
        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            dp[i][0] = i
        for j in range(n):
            dp[0][j] = j
        for i in range(1, m):
            for j in range(1, n):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])
        return dp[m-1][n-1]
```