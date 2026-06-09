### 解题思路

coins/amount+1
  0,1,2,3,4,5,6...
1 1
2 1
5 1

### 代码

```python3
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:

        if amount == 0:
            return 1
        if not coins:
            return 0
        dp = [[1]+[0]* (amount) for _ in coins]
        for c in range(len(coins)):
            for j in range(amount+1):
                if j < coins[c]:
                    dp[c][j] = dp[c - 1][j]
                else:
                    dp[c][j] = dp[c][j-coins[c]]+dp[c-1][j]
        return dp[-1][-1]
```