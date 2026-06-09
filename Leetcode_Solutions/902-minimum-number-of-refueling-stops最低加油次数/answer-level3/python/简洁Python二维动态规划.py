### 代码

```python3
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        n = len(stations)
        # dp[i][j]表示经过第i个加油站加油j次能够到达的最远距离
        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        if startFuel >= target:
            return 0
        for i in range(n + 1):
            dp[i][0] = startFuel
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                # 前i-1站加j次，本站不加油
                if dp[i - 1][j] >= stations[i - 1][0]:
                    dp[i][j] = dp[i - 1][j]
                # 前i-1站加j-1次，本站加油
                if dp[i - 1][j - 1] >= stations[i - 1][0]:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1])
        for i in range(n + 1):
            if dp[n][i] >= target:
                return i
        return -1
```