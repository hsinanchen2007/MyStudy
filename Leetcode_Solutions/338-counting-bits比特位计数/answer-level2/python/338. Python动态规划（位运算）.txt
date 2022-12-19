### 解题思路
动态规划方法在于找到当前状态和之前状态的转移方程，对于某个数i：
（1）偶数，那么i == (i >> 1) << 1，也就是说，和i >> 1的1的个数是一样的（就是左移了一位）
（2）奇数，那么i == (i >> 1) << 1 + 1，比i >> 1的1的个数多了1（左移一位，并把最后一位置为1）

### 代码

```python
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if num == 0:
            return [0]
        dp = [0] * (num + 1)
        dp[1] = 1
        for i in range(2, num + 1):
            if i % 2 == 0: # 偶数
                dp[i] = dp[i >> 1]
            else:
                dp[i] = dp[i >> 1] + 1
        return dp
```