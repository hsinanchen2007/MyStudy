### 解题思路

动态规划
状态数组dp[i]表示总金额为i时的最少兑换钱数。
类似于爬楼梯思想，每次可上的楼梯数即为硬币的面值，所以状态转移方程为：
dp[i] = min(dp[i-coins[0]], dp[i-coins[1]], ..., dp[i-coins[n-1]]) + 1
即：使用面值coins[0], coins[1], ..., coins[n-1] 的最少兑换数 + 1

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if len(coins) < 1 or amount < 0:
            return -1
        dp = [amount+1] * (amount+1)
        dp[0] = 0
        for i in range(1, amount+1):
            for j in range(len(coins)):
                if coins[j] <= i:
                    dp[i] = min(dp[i], dp[i-coins[j]]+1)
        return dp[amount] if dp[amount] <= amount else -1
```