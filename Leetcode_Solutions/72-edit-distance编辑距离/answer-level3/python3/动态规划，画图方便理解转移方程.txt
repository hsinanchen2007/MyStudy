dp[i][j]：将word1的前i个字母变成word2的前j个字母需要最少多少次编辑
![编辑距离.png](https://pic.leetcode-cn.com/76cc6875c18a016be6118f533cda9c03bc9ceb3b7a253dcca28866c2c19e53e4-%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.png)

dp[i][j]的情况可以由dp[i-1][j-1], dp[i][j-1], dp[i-1][j]发展来，共有A，B，C，D四种情况。

![A情况.png](https://pic.leetcode-cn.com/f3472f2ae6e61cfebf5192f5b36624fd482d80494ec83dfc48c1887c6619ef87-A%E6%83%85%E5%86%B5.png)

![B情况.png](https://pic.leetcode-cn.com/9b07f07f9f69c546fad53d1d31ac1c698e17cd1db5ae572148833c3fa9b6845e-B%E6%83%85%E5%86%B5.png)

![C情况.png](https://pic.leetcode-cn.com/30e0b5c1a4e023af65e1eaea0ceff57a536754b43963011c84e43d2eeafc662e-C%E6%83%85%E5%86%B5.png)

D情况：末尾的两个字母一样，那么就不用考虑末尾的字母了，编辑距离就等价于dp[i-1][j-1]

转移方程：
末尾字母一样：word[i] == word[j],  dp[i-1][j-1]
末尾字母不一样：A，B，C情况都可以，选取编辑距离最小的 min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1

# **代码**
```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len1 = len(word1)
        len2 = len(word2)
        
        dp = [ [ 0 for _ in range(len2+1) ] for _ in range(len1+1) ]
        
        for i in range(len2+1):
            dp[0][i] = i
        
        for i in range(len1+1):
            dp[i][0] = i
        
        for i in range(1, len1+1):
            for j in range(1, len2+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
        
        return dp[len1][len2]
```





