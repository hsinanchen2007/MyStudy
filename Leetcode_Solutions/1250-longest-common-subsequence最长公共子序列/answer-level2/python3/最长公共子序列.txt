### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len_text1 = len(text1)
        len_text2 = len(text2)
        dp = [[0 for i in range(len_text2+1)] for j in range(len_text1+1)]

        for i in range(1,len_text1+1):
            for j in range(1,len_text2+1):
                if text1[i-1] ==text2[j-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])

        return dp[len_text1][len_text2]
```