```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # dp
        # 分三类情况（从两个空字符串word1和word2开始迭代）
        # 1、保持word1加一个字符，此时word2增加一个该字符
        # 2、保持word2加一个字符，此时word1增加一个该字符
        # 3、替换（或不变）word1和word2该位置的字符
        # 由于是从空字符开始迭代，所以过程中已经考虑了删除的情况
        m, n = len(word1), len(word2)
        dp = [[i for i in range(m+1)]] + [[i]+[0]*m for i in range(1, n+1)]
        #print(dp)
        for i in range(1, n+1):
            for j in range(1, m+1):
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1)
                tmp = 1
                if word2[i-1] == word1[j-1]: tmp = 0
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + tmp)
        return dp[-1][-1]
```
