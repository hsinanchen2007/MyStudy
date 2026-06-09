### 解题思路
动态规划
1 N < 2，直接给出结果
2 利用动态规划
状态 i（序数）
状态转移方程 F[i] = F[i-1] + F[i-2], i >= 2
边界F[0] = 0, F[1] = 1
考虑到只需要用前两个值，可用两个变量记录之，从而降低空间复杂度

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        # if N < 2:
        #     return N
        # length = N + 1
        # dp = [0] * (length)
        # dp[1] = 1
        # for i in range(2, length):
        #     dp[i] = dp[i-1] + dp[i-2]
        # return dp[-1]
        if N < 2:
            return N
        a = 0
        b = 1
        for i in range(2, N+1):
            a, b = b, a + b
        return b
```
# 复杂度分析
时间复杂度：O(N)
空间复杂度：O(1)