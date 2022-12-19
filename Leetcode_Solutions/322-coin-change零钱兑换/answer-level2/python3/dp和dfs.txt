### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # dp = [float('inf')]*(amount+1)
        # dp[0] = 0
        # for coin in coins:
        #     for i in range(coin, amount+1):
        #         dp[i] = min(dp[i-coin]+1, dp[i])
        # return dp[-1] if dp[-1] != float('inf') else -1

        coins.sort(reverse =True)
        ret = float("inf")

        # def change(amount, i, count):
        #     nonlocal ret
        #     if amount==0:
        #         ret = min(count, ret)
        #         return 
        #     for j in range(i, len(coins)):
        #         if (ret - count)*coins[j] < amount:
        #             break
        #         if coins[j]>amount:
        #             continue
        #         change(amount-coins[j], j, count+1)
        
        # change(amount, 0, 0)
        # return ret if ret!=float("inf") else -1

        def change(amount, i, count):
            nonlocal ret
            if amount==0:
                ret = min(count, ret)
                return 
            if i==len(coins):
                return
            for t in range(amount//coins[i], -1, -1):
                    if t > ret-count:
                        return
                    change(amount-t*coins[i], i+1, count+t)

        change(amount, 0, 0)
        return ret if ret!=float("inf") else -1

```