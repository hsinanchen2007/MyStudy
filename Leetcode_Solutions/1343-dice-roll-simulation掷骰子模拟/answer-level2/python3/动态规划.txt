简单的动态规划问题，可惜竞赛期间没来得及想到。
记dp[i][j][k]为抛k+1次骰子且数字i+1最后连续出现j+1次时不同点数序列的数量。建立递推关系即可。

```python
rollMaxLimit = 15
MOD = 1_000_000_007

class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        dp = [[0 for j in range(rollMaxLimit)] for i in range(6)]
        for i in range(6):
            dp[i][0] = 1
        S = [1] * 6
        sum_S = 6
        for k in range(1, n):
            for i in range(6):
                for j in range(rollMax[i] - 1, 0, -1):
                    dp[i][j] = dp[i][j - 1]
            for i in range(6):
                dp[i][0] = sum_S - S[i]
            S = [sum(dp[i][j] for j in range(rollMax[i])) for i in range(6)]
            sum_S = sum(S)
        return sum_S % MOD
```
