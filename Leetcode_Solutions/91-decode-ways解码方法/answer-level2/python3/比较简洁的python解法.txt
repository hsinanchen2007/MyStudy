```
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        for i in range(len(s)):
            tmp = 0
            if s[i] != '0':
                tmp += dp[i]
            if i-1>=0 and s[i-1] != '0' and int(s[i-1:i+1]) <= 26:
                tmp += dp[i-1]
            dp[i+1] = tmp
        return dp[-1]
```
核心思想就是分类讨论解码的最后一步是两个元素还是一个元素