### 解题思路
dp[i] = dp[i-1] + dp[i-2]

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """

        dp = [0] *  n
        if n == 1:
            return 1
        elif n == 2:
            return 2
        for i in range(n):
            if i == 0:
                dp[i] = 1
            elif i == 1:
                dp[i] = 2
            else:
                dp[i] = dp[i-1] + dp[i-2]

        return dp[n-1]


```