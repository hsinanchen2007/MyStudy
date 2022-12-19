### 解题思路
动态规划：状态遍历dp[i][j]表示从word1[:i]到word2[:j]所需的最短操作数，状态转移方程则是当word1[i-1]与word[j-1]相同时，dp[i][j]=dp[i-1][j-1];否则，取dp[i-1][j]、dp[i-1][j-1]或dp[i][j-1]状态中操作数最少的那个+1。

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len1 = len(word1)
        len2 = len(word2)
        if len1*len2==0:
            return len1+len2
        dp = [[0]*(len2+1) for _ in range(len1+1)]
        # 初始条件
        for i in range(1,len1+1):
            dp[i][0]=i
        for j in range(1,len2+1):
            dp[0][j]=j
        # 状态转移
        for i in range(1,len1+1):
            for j in range(1,len2+1):
                # 字符串当前符号相同
                if word1[i-1]==word2[j-1]:
                    dp[i][j]=dp[i-1][j-1]
                else:
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
        return dp[len1][len2]
```