刚拿到题第一思路还是暴力法。。。想着用BFS去遍历word1，通过三种操作查看变换到word2的最小编辑距离。写完发现超时了。。。
其次，字符串的问题一定要想到动态规划。思考该题的变量发现1维的dp并不够用，于是用二维dp[i][j]来表示word1[i]到word2[j]所需要的最小编辑距离。
状态转移方程思考过程如下：
1.如果word1[i-1]与word[j-1]相同，显然dp[i][j]=dp[i-1][j-1]
2.如果不同，那么dp[i][j] 可以通过 1）在dp[i-1][j-1]的基础上做replace操作达到目的 2）在dp[i-1][j]的基础上做insert操作达到目的 3）在dp[i][j-1]的基础上做delete操作达到目的。
取三者最小情况即可。
综上可得状态转移方程 dp[i][j] = min(dp[i-1][j-1]+(0 if word1[i-1] == word2[j-1] else 1), dp[i-1][j]+1, dp[i][j-1]+1)

```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m,n = len(word1),len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]    
        
        for j in range(1, n + 1): dp[0][j] = j
        for i in range(1, m + 1): dp[i][0] = i
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = min(dp[i-1][j-1]+(0 if word1[i-1] == word2[j-1] else 1), dp[i-1][j]+1, dp[i][j-1]+1)
        return dp[-1][-1]
```
