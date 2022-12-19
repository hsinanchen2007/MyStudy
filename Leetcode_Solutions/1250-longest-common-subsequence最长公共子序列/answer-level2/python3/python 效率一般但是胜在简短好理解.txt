### 解题思路
dp

### 代码

```python
class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        if not text1 or not text2:
            return 0
        #base case
        n = len(text1)
        m = len(text2)
        dp = [[0 for x in range(n+1)] for y in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if text1[j-1] == text2[i-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        return dp[m][n]
        

```