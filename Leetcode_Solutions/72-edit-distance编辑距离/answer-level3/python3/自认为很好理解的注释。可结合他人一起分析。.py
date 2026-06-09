### 解题思路
自认为很好理解的注释。可结合他人一起分析。

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:

        dp = [[0 for _ in range(len(word2) + 1)] for _ in range(len(word1) + 1)]
        for i in range(len(word2) + 1):
            dp[0][i] = i
        for i in range(len(word1) + 1):
            dp[i][0] = i

        for i in range(1, len(word1) + 1):
            for j in range(1, len(word2) + 1):
                # i与j位相同：hor->ror等价等价ho->ro  翻译：dp[i][j]=dp[i-1][j-1]
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    # 增操作：添加j字符。 hor->ro等价horo->ro等价hor->r  翻译：dp[i][j]=dp[i][j-1]
                    plus = dp[i][j - 1] + 1
                    # 减操作：删除i字符。 hor->ro等价ho->ro  翻译：dp[i][j]=dp[i-1][j]
                    minus = dp[i - 1][j] + 1
                    # 替换操作：i字符替换为j字符。 hor->ro等价hoo->ro等价ho->r  翻译：dp[i][j]=dp[i-1][j-1]
                    exchange = dp[i - 1][j - 1] + 1
                    dp[i][j] = min(plus, minus, exchange)
        return dp[len(word1)][len(word2)]
```