### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 10

        def A(N, M):
            res = 1
            for _ in range(N):
                res *= M
                M -= 1
            return res

        dp = [0 for _ in range(n + 1)]
        dp[0] = 1
        dp[1] = 10
        for i in range(2, n + 1):
            if i <= 10:
                dp[i] = dp[i - 1] + A(i, 10) - A(i-1, 9)
            else:
                dp[i] = dp[10]
        return dp[n]        

```