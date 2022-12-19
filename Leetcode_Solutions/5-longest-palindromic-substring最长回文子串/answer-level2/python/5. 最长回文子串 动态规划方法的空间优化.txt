### 解题思路
1. 状态空间优化：矩阵 -> 矩阵上三角拼成的数组

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 特例
        n = len(s)
        if n < 2: return s

        # dp = [[False for _ in range(n)] for _ in range(n)]
        # for i in range(n):
        #    dp[i][i] = True
        # dp = [False for _ in range(n * (n - 1) / 2)]
        dp = [False] * (n * (n - 1) / 2)
        
        max_len = 1
        start = 0
        cusum = 0
        for j in range(1, n):
            cusum += j - 1
            for i in range(0, j):
                # idx = i + j * (j - 1) / 2
                idx = i + cusum
                if s[i] == s[j]:
                    if j - i < 3:
                        # dp[i][j] = True
                        dp[idx] = True
                    else:
                        # dp[i][j] = dp[i + 1][j - 1]
                        # dp[idx] = dp[i+1 + (j-1)*(j-2)/2]
                        dp[idx] = dp[idx - (j - 2)]
                # dp[i][j] = (s[i] == s[j]) and (j - i < 3 or dp[i + 1][j - 1])
                # dp[idx] = (s[i] == s[j]) and (j - i < 3 or dp[idx - j + 2])

                if dp[idx]:
                    cur_len = j - i + 1
                    if cur_len > max_len:
                        max_len = cur_len
                        start = i
                # else:
                #   # dp[i][j] = Fals
                #   dp[idx] = False
                
        return s[start:start + max_len]


```