### 解题思路
这里使用动态规划很好理解，子问题是组成n - m的完全平方数最少有几个，其中m也是一个完全平方数，下面的动态规划其实也可以理解为一个加了备忘录的深搜，但应该是比递归快的。代码中的x是用来确定比当前数小的完全平方数的，nums记录每个数和它对应的完全平方数，可以避免重复计算。
注：在Python3中不需要int强制转换。

### 代码

```python
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        from math import floor
        x = int(floor(n ** 0.5))
        nums = [i * i for i in range(x + 1)]
        dp = [0 for _ in range(n + 1)]
        for i in range(1, n + 1):
            x = int(floor(i ** 0.5))
            dp[i] = min([dp[i - nums[j]] for j in range(1, x + 1) if i - nums[j] >= 0]) + 1
        return dp[-1]
```