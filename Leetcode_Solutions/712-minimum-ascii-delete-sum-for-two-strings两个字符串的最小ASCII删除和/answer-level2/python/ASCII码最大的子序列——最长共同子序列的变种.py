题意是寻找一个共同子序列，将字符串s1和s2删除为该子序列时所删除的ASCII综合最小。
**等价于求一个字符串s1和s2的ASCII码总和最大的共同子序列。**
因为s1和s2的总和固定，当共同子序列的总和最大时，删除成为该子序列的代价必然最小。

因此问题转化为最长共同子序列，dp[i][j]为s1[:i]和s2[:j]的ASCII码最大的子序列，则：
dp[i][j] = dp[i-1][j-1] + ASCII(s1[i]), s1[i] == s2[j]
dp[i][j] = max(dp[i][j-1], dp[i-1][j]), s1[i] != s2[j]


```python []
class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        def get_total_ascii(s):
            return sum( [ord(c) for c in s] )
        
        dp = [ [ 0 for _ in range(len(s2)+1) ] for _ in range(len(s1)+1) ]
        for i in range(1, len(s1)+1):
            for j in range(1, len(s2)+1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + ord(s1[i-1])
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
        return get_total_ascii(s1) + get_total_ascii(s2) - 2*dp[-1][-1]
```

