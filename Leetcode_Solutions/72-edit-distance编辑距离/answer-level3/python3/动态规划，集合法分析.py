### 解题思路

动态规划

按照最后一个字母所有可能的情况的操作对集合进行分类，取最小所以集合之间是可以有相互重叠的


n 为第一个串的长度，m为第二个串的长度
时间复杂度O(n * m), 空间复杂度可以优化到O(m).

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len_1 = len(word1)
        len_2 = len(word2)
        dp = [[0] * (len_2 + 1) for _ in range(len_1 + 1)]
        for i in range(len_2 + 1):
            dp[0][i] = i
        for i in range(len_1 + 1):
            dp[i][0] = i
        for i in range(1, len_1 + 1):
            for j in range(1, len_2 + 1):
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1)
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1])
                else:
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1)
        return dp[len_1][len_2]
```