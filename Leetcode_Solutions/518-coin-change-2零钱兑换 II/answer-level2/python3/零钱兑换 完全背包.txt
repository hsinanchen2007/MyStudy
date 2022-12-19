### 解题思路
dp[i]代表金额为i时的方案数
base case: 当amount=0时, 方案数为1, 即为不选任何硬币

### 代码

```python3
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        l = len(coins)
        dp = [0]*(amount+1)
        dp[0] = 1
        for i in range(1, l+1):
            for j in range(coins[i-1], amount+1): # 因为完全背包所以从前往后, 使得dp[j-coins[i-1]]比dp[j]先计算, 以此多次考虑coin[i-1]
                dp[j] += dp[j-coins[i-1]]
        return dp[-1]
```