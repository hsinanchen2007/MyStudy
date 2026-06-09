### 解题思路
num(amount) = num(amount-c) + 1

### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        if not coins:return -1
        dp = [0] * (amount + 1) #dp[i] 表示：当零钱总额为i时所需的最小硬币数
        ans = []
        for i in range(1,amount +1):
            for c in coins:
                if i - c >= 0 and dp[i-c] != -1:
                    ans.append(dp[i-c] + 1)     #将总数为i的所有可能情况暂存于ans
            if not ans:dp[i] = -1 #说明当金钱总额为i时，并没有找到能够组合成i的c
            else:dp[i] = min(ans)
            ans = []
        return dp[-1]
```