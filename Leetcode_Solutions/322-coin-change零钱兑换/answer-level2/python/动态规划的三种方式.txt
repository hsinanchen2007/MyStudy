### 解题思路
此处撰写解题思路
关键的动态转义方程为 dp[i] = min(min(dp[i], 1+dp[i-coin])), 其中coin属于coins
### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # 不带备忘录的动态规划方法，超时
        # def df(amount):
        #     if amount == 0: return 0
        #     if amount < 0: return -1
        #     res = float('inf')
        #     for coin in coins:
        #         temp = df(amount - coin)
        #         if temp == -1: continue
        #         res = min(res, 1 + temp)
        #     return res if res != float('inf') else -1
        

        # 带备忘录的动态规划方法， 时间和空间都是只击败了5%
        # amount_num_map = {}
        # def df_memo(amount):
        #     if amount in amount_num_map:  return amount_num_map[amount]
        #     if amount == 0: return 0
        #     if amount < 0: return -1
        #     res = float('inf')
        #     for coin in coins:
        #         temp = df_memo(amount - coin)
        #         if temp == -1: continue
        #         res = min(res, 1 + temp)
        #     amount_num_map[amount] = res if res != float('inf') else -1
        #     return amount_num_map[amount]
        # return df_memo(amount)

        # 迭代方法 时间击败11%
        # memo = {}
        # memo[0] = 0
        # for a in range(1, amount + 1):
        #     res = float('inf')
        #     for coin in coins:
        #         temp = a - coin
        #         if temp < 0: continue
        #         if temp == 0: res = 1
        #         if memo[temp] == -1:
        #             continue
        #         res = min(res, 1 + memo[temp])
        #     memo[a] = res if res != float('inf') else -1

        # return memo[amount]

        # 改进迭代方法 时间击败67% 空间击败42% 
        memo = [float('inf')] * (amount + 1)
        memo[0] = 0
        for a in range(1, amount + 1):
            for coin in coins:
                if a - coin < 0: continue  # 子问题无解，跳过
                memo[a] = min(memo[a], 1 + memo[a - coin])

        return memo[amount] if memo[amount] != float('inf') else -1
```