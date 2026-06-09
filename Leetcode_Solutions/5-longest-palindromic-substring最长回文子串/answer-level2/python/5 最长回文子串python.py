### 解题思路
字符串、动态规划。
状态转移方程：dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]，dp[i][j] 表示子串 s[i, j] 是否为回文子串。
可以构建一个关系矩阵，横坐标为i，纵坐标为j。
 
![image.png](https://pic.leetcode-cn.com/08e675930d8a7bba45488daef5cba09de49be94bafbdbcd9f0507329d694dcd2-image.png)

### 代码

```python
class Solution:
    def longestPalindrome(self, s):

        if len(s) < 2:
            return s
        
        size_s = len(s)
        dp = [[False for i in range(size_s)] for j in range(size_s)]
        # print dp

        start, maxlen, curlen = 0, 1, 0
        for j in range(1,size_s):
            for i in range(0,j):
                # print i,j
                if s[i] == s[j]:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i+1][j-1]
                else:
                    dp[i][j] = False
                
                if dp[i][j]:
                    curlen = j - i + 1
                    if curlen > maxlen:
                        start = i
                        maxlen = curlen
        
        return s[start:start+maxlen]
                    
                    






```