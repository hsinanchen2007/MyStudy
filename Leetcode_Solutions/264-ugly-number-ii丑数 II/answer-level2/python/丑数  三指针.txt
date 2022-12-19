### 解题思路
参考官方题解

### 代码

```python
class Ugly:
    def __init__(self):
        self.nums = dp = [0 for i in range(1691)] #题干说n不超过1690
        dp[0] = 1
        i2 = i3 = i5 = 0
        for i in range(1,1691):
            dp[i] = min(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5)
            if dp[i] == dp[i2] * 2: 
                i2 += 1
            if dp[i] == dp[i3] * 3:
                i3 += 1
            if dp[i] == dp[i5] * 5:
                i5 += 1
            
class Solution:
    u = Ugly()
    def nthUglyNumber(self, n):
        return self.u.nums[n-1]

```