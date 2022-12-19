1. 中心扩散法：
```python
class Solution(object):
    res = ''
    maxlen = 0
    def longestPalindrome(self, s):
        if len(s) <= 1:
            return s
        for i in range(len(s)):
            self.diffusion(s, i, i)
            self.diffusion(s, i, i+1)
        return self.res
    def diffusion(self, strs, left, right):
        while left >= 0 and right < len(strs) and strs[left] == strs[right]:
            if right-left+1 > self.maxlen:
                self.maxlen = right-left+1
                self.res = strs[left:right+1]
            left -= 1
            right += 1 
```
2.动态规划法：
```python
class Solution(object):
    def longestPalindrome(self, s):
        if len(s) <= 1: return s
        res = s[0]
        maxlen = 0
        if s[0] == s[1]:
            res = s[0:2]
        dp = [[False for _ in range(len(s))] for _ in range(len(s))]
        for j in range(2, len(s)):
            dp[j][j] = True
            for i in range(j):
                dp[i][j] = s[i] == s[j] and (j-i<=2 or dp[i+1][j-1])
                if dp[i][j] and maxlen < j - i + 1:
                    maxlen = j-i+1
                    res = s[i:j+1]
        return res
```
具体思路可以参考 B 站视频：https://www.bilibili.com/video/av46183143?from=search&seid=17804670437594009423