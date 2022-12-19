### 解题思路
法1：从第i天开始，找到距离他第一个最近且最大的值，举个例子， [7,1,5,3,6,4]中，【1，5】，【3，6】；[1,2,3,4,5]中【1，5】。使用单调栈，获得一个数据第一个距离它最近最大（小）的数据，之后做差就可以解决本题。

法2：一次遍历所有数组，具体解释参考官方解题/

法3：动态规划。
每一天的状态分为持有股票和持有股票这两种，我们要寻求的最终结果是：通过一系列的买卖操作（某天持有或不持有）来找到最后一天不持有情况下的最大利润和。
**1.第i天持有：（1）第i-1天持有，第i天什么都不做；（2）第i-1天不持有，第i天购买（请注意，购买则会导致利润减少当天购买价格的数额）
2.第i天不持有：（1）第i-1天不持有，第i天什么都不做；（2）第i-1天持有，第i天卖出（请注意，卖出则会导致利润增加当天购买价格的数额）**
根据上述状态写出动态规划方程（状态转移方程）：

```python []
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]) # 第i天不持有股票
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]) # 第i天持有股票
```

ps：因为所有是利润，故将dp数组表示为利润，dp[0][0], dp[0][1] = 0, -prices[0]，这里我解释一下，分别表示的是利润为0，利润为负（买入操作导致利润减少）。

动态规划理论请看：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/pythonsi-chong-jie-fa-dai-fen-xi-by-hialiens/


### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        '''
        # 48 ms	14.7 MB
        法1：单调栈
        
        stack = []
        profit = 0

        # guard
        prices.append(-1)
        for price in prices:
            while stack and price < stack[-1]:
                profit += stack[-1] - stack[0]
                stack = []
            stack.append(price)

        return profit
        '''

        '''
        # 40 ms	14.6 MB
        法2：一次遍历
        
        prices.append(-1)
        profit = 0

        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]
        
        return profit
        '''

        '''
        法3：动态规划
        '''
        if not prices:
            return 0
        
        lenth = len(prices)

        # initialize the dp[][], dp[1][*] means the profit in the i day 
        dp = [[0]*2 for _ in range(lenth)]

        # dp[i][0] means having nothing, dp[i][1] means having some stocks
        # dp[0][1] = -prices[0] means that the profit is a negtive number 
        dp[0][0], dp[0][1] = 0, -prices[0]

        for i in range(1, lenth):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        
        return dp[lenth-1][0]



```