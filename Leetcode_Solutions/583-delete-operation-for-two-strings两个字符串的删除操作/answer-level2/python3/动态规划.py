  思路：转换为最长公共子序列的问题   
        动态规划：   
        1. 原问题：长度为n、m的字符串的最长公共子序列； 子问题：长度为i,j的字符串的最长公共子序列   
        2. 状态： dp[i][j]表示word1[:i]和word2[:j]的最长公共子序列的长度   
        3. 初始化：dp[i][0],dp[0][j]都为0.  
        4. 状态转移方程：dp[i][j] = dp[i-1][j-1]+1 if word1[i-1]==word2[j-1] else max(dp[i-1][j],dp[i][j-1])  

``` python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1),len(word2)
        dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,m+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        return n+m-2*dp[n][m]
```