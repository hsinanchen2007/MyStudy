### 闫氏DP分析法
![image.png](https://pic.leetcode-cn.com/f82d1197c5881799936d2fda435aba377e85a89069c65ca3ad0b943163c663bb-image.png)


### 代码
```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1,l2 = len(text1),len(text2)
        dp = [[0]*(l2+1) for _ in range(l1+1)] #row l1, col l2
        for i in range(1,l1+1):
            for j in range(1, l2+1):
                if text1[i-1] == text2[j-1]:dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1)
                else:dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[l1][l2]
```