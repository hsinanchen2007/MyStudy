### 解题思路
思路与之前“零钱兑换”一致，不过需要先自己构建平方数队列，所以空间效率上会差一些，时间是O(nlogn)

### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:
        nums = []
        k = 1
        while k**2 <= n:
            nums.append(k **2)
            k += 1
        dp = [n] * (n + 1)
        dp[0], dp[1] = 0, 1
        for num in nums:
            for i in range(num, n+1):
                dp[i] = min(dp[i], dp[i-num]+1)
        return dp[-1]

```