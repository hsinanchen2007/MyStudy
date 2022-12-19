### 解题思路
根据大神的团灭方法总结出的笨办法，没有优化，虽然效率非常非常低，但是利于本人记忆
- dynamic programming
-- 买卖股票的最佳时机 k = 1
-- 买卖股票的最佳时机III k = 2
- greedy method
-- 买卖股票的最佳时机II k = infinity
-- 最佳买卖股票时机含冷冻期 k = infinity, cooldown time = 2
-- 买卖股票的最佳时机含手续费 k = infinity, fee != 0
### 代码
#### 买卖股票的最佳时机 IV
```python3
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        if k < len(prices) //2:
            return self.dynamicProgramming(k, prices)
        return self.greedy(prices)
        
    def dynamicProgramming(self,k,prices):
        dp = []
        for i in range(len(prices)):
            dp.append([])
            for t in range(k+1):
                dp[i].append([])
                for j in range(2):
                    dp[i][t].append(0)
        for t in range(1,k+1):
            #dp[0][t][0] = 0
            dp[0][t][1] = -prices[0]
        for i in range(1,len(prices)):
            for t in range(1,k+1):
                dp[i][t][0] = max(dp[i-1][t][0], dp[i-1][t][1] + prices[i])
                dp[i][t][1] = max(dp[i-1][t][1], dp[i-1][t-1][0] - prices[i])
        return dp[-1][-1][0]
    def greedy(self,prices):
        # dp = [[0]*2]*len(prices)
        dp = []
        for i in range(len(prices)):
            dp.append([])
            for j in range(2):
                dp[i].append(0)
        dp[0][1] = - prices[0]
        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        return dp[-1][0]

```
#### 最佳买卖股票时机含冷冻期
因为dp[i-2][]，所以需要考虑i=0或1时，这两种base case
当i > 2时，dp[i][1]考虑回退到i-2的时候
当i = 1时，dp[i][1]考虑回退到i-1的时候，因为之前也没有任何交易，所以无需冷却
```python3
class Solution:
    def greedy(self, prices, cool):
        #dp = [[0]*2]*len(prices)
        dp = []
        for i in range(len(prices)):
            dp.append([])
            for j in range(2):
                dp[i].append(0)

        for i in range(0,len(prices)):
            if i == 0:
                dp[i][0] = 0
                dp[i][1] = -prices[0]
                continue
            if i ==1:
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+ prices[1])
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]- prices[1])
                continue
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-cool][0] - prices[i])

        return dp[-1][0]

    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) ==0:
            return 0
        if len(prices) == 1:
            return 0
        return self.greedy(prices,2)   

```
#### 买卖股票的最佳时机含手续费
```python3
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        if len(prices) == 0:
            return 0
        return self.greedy(prices,fee)

    def greedy(self,prices,fee):
        #dp = [[0]*2]*len(prices)
        dp = []
        for i in range(len(prices)):
            dp.append([])
            for j in range(2):
                dp[i].append(0)

        dp[0][1] = - prices[0] - fee
        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
        return dp[-1][0]
```

