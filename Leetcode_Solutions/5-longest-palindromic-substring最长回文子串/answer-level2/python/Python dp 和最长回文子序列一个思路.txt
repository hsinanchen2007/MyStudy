### 解题思路
根据最长回文子序列那题的动态规划思路改的，直接把循环里面的逻辑简化一下就行。主要两个base case很关键。其他就套模板。

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        #base case
        dp = [[0 for x in range(n)] for y in range(n)]
        for i in range(n):
            dp[i][i] = 1
        for i in range(n-1):
            dp[i][i+1] = 1 if s[i] == s[i+1] else 0

        gap, maxx, maxy = -1,0,0
        for x in range(n-2, -1, -1):
            for y in range(x+1, n):
                if s[x] == s[y] and dp[x+1][y-1] == 1:
                    dp[x][y] = 1
                if dp[x][y] == 1 and y - x > gap:
                    gap = y-x
                    maxx = x
                    maxy = y
                    #print(maxx,maxy)
        return s[maxx : maxy+1]

```