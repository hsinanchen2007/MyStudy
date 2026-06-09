### 解题思路
这道题可以说是一般我们见过的零钱兑换的变体，最基础的就是问有多少种组合方法，这道题其实也差不多，dp[i]记录的是总数为i的硬币至少需要多少个硬币来兑换，那么转移方程就是dp[i] = min([dp[i - coin] for coin in coins]) + 1。
但是有需要注意的就是要注意有无法兑换成功的情况不能考虑在内，比如硬币给了[3, 4]，如果要凑出2，是不可能的，后续如果有要基于2进行凑硬币的方案一律都是不考虑的。

### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if coins == []:
            return -1
        dp = [-1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            temp = [] # 可选方案
            for coin in coins:
                if i - coin >= 0 and dp[i - coin] != -1:
                    temp.append(dp[i - coin] + 1)
            if temp != []:
                dp[i] = min(temp)

        return dp[-1]
```