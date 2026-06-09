```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # dp
        # word1 => word2
        # horse
        # ros
        # dp[i][j] = min(dp[i - 1][j], dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
        if len(word1) == 0 or len(word2) == 0: return max(len(word1), len(word2))
        dp = [[0] * len(word2) for _ in range(len(word1))]
        for i in range(len(word1)):
            for j in range(len(word2)):
                if i == 0 and j == 0:
                    dp[i][j] = 0 if word1[i] == word2[j] else 1
                elif i == 0 or j == 0:
                    if word2[j] == word1[i]:
                        dp[i][j] = max(i + 1, j + 1) - 1
                    else:
                        dp[i][j] = dp[max(0, i - 1)][max(0, j - 1)] + 1
                elif word1[i] == word2[j]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
        return dp[-1][-1]
```