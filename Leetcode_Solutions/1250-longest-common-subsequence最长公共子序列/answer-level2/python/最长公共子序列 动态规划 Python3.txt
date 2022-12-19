### 解题思路
执行用时 :440 ms, 在所有 Python3 提交中击败了84.65%的用户
内存消耗 :21.3 MB, 在所有 Python3 提交中击败了23.28%的用户

注意：
1. f(i, j)就是text1[0]~text1[i]和text2[0]~text2[j]之间的最长公共子序列长度
2. 因为dp[i][j]和dp[i-1][j-1]有关，在最前面多添加了为0的一行和为0的一列
### 代码

```python3
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0]*(len(text2)+1) for _ in range(len(text1)+1)]
        for i in range(len(text1)):
            for j in range(len(text2)):
                if text1[i] != text2[j]:
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
                else:
                    dp[i+1][j+1] = dp[i][j] + 1
        return dp[-1][-1]
```