### 解题思路
使用动态规划，dp[i]表示整数i 分解后的最大乘积。 dp[i]应该等于某个整数j的分解乘积dp[j]和（i-j）乘积。
但是由于dp[j]是经过分解后的，失去了一种情况。那就是j*(i-j)这种情况。
所以需要取max(j*(i-j), dp[j]*（i-j）)


### 代码

```python
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0 for i in range(n+1)]
        dp[0] = 0
        dp[1] = 1
        dp[2] = 1
        for i in range(3,n+1):
            for j in range(1, i):
                temp = max(dp[j] * (i - j), j * (i-j))
                if temp > dp[i]:
                    dp[i] = temp
        return dp[n]








        # if n == 3:
        #     return 2
        # if n == 2:
        #     return 1
        # a = n // 3
        # b = n - a*3
    
        # if b == 0:
        #     return 3**a
        # if b == 1:
        #     return 3**(a-1)*4
        # if b == 2:
        #     return 3**a*2
```