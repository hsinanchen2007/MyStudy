### 解题思路
不断复用当前dp...

### 代码

```python
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        L = len(t)
        dp = [0 for i in range(L + 1)]
        dp[0] = 1

        for c in s:
            for i in range(L - 1, -1, -1):
                if c == t[i]:
                    dp[i + 1] = dp[i+1] + dp[i]
        return dp[-1]

```