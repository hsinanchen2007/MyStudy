### 解题思路
functools用法+递归

### 代码

```python3
import functools
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # :作者：Lullaby
        # if coins == []:
        #     return -1
        # dp = [-1] * (amount + 1)
        # dp[0] = 0
        # for i in range(1, amount + 1):
        #     temp = [] # 可选方案
        #     for coin in coins:
        #         if i - coin >= 0 and dp[i - coin] != -1:
        #             temp.append(dp[i - coin] + 1)
        #     if temp != []:
        #         dp[i] = min(temp)

        # return dp[-1]

        # 作者：leetCode
        #@functools.lru_cache(amount)
        # def dp(rem):
        #     if rem < 0: return -1
        #     if rem == 0: return 0
        #     mini = int(1e9)
        #     for coin in self.coins:
        #         res = dp(rem - coin)
        #         if res >= 0 and res < mini:
        #             mini = res + 1
        #     return mini if mini < int(1e9) else -1
        # self.coins = coins
        # if amount < 1: return 0
        # return dp(amount)
        @functools.lru_cache(amount)
        def helper(rest):
            if rest < 0: return -1
            if rest == 0: return 0
            mini = int(1e9)
            for coin in self.coins:
                res = helper(rest - coin)
                if res >= 0 and res < mini:
                    mini = res + 1
            return mini if mini < int(1e9) else -1
        
        self.coins = coins
        if amount < 1: return 0
        return helper(amount)
        

```