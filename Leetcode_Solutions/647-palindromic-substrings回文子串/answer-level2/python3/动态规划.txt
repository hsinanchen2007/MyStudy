跟leetcode第5题特别类似, 区别就是统计个次数

```
class Solution:
    def countSubstrings(self, s: str) -> int:
        """
           就是统计一共有多少个回文串, 那就是发现一个加1就可以了

           还是令dp[i][j]表示从i到j的序列是否为回文串，如果是就为True, 如果不是就是False

           如果s[i] == s[j]并且dp[i+1][j-1]==True, 那么 dp[i][j]就为True
        """
        size = len(s)
        if size == 0:
            return 0
        if size == 1:
            return 1
        
        dp = [[False for _ in range(size)] for _ in range(size)]
        for i in range(size):
            dp[i][i] = True
        count = size

        for len_t in range(1, size):
            for start in range(size - len_t):
                end = start + len_t
                if s[start] == s[end] and (len_t <= 2 or dp[start+1][end-1]):
                    dp[start][end] = True
                    count += 1
                else:
                    dp[start][end] = False
        
        return count
```
