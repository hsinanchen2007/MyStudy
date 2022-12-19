### 解题思路
一看到题目就觉得应该是动态规划，困难题肯定不是一维，那么最自然的就是定义word1中的前i个子串和word2中的前j个子串为dp[i][j]
对于增删改三种操作，要意识到顺序是无所谓的。
在有一个是空串的时候，边界上的距离就是另一个非空串的长度

然后注意下标和dp中下标的对应含义，很快就能写出代码来

### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(n+1):
            dp[0][i] = i
        for i in range(m+1):
            dp[i][0] = i
        
        for i in range(1,m+1):
            for j in range(1,n+1):
                if word1[i-1] != word2[j-1]:
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
                else:
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]-1)
        
        # print(dp)
        return dp[m][n]
```