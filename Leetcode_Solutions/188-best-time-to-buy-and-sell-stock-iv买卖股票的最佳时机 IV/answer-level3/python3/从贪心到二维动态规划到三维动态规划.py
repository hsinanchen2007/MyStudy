### Start with
    今天把股票的题都做完了。写个题解记录一下。
### Example
- 买卖股票最佳时机1
在这个题中虽然也可以用动态规划来解，但感觉不是很复杂的题，我们就不要简单问题复杂化了（因为题目中提到最多只能完成一笔交易，即买入和卖出只能进行一次）简单的贪心策略可以解决，在最便宜的时候买入，最贵的时候卖出。代码如下：
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        min_price = prices[0]
        max_profit = 0
        n = len(prices)
        for i in range(1,n):
            min_price = min(prices[i], min_price)
            max_profit = max(max_profit, prices[i] - min_price)
    
        return max_profit
```
- 买卖股票的最佳时机2
这个题中可以进行多次交易，建议还是贪心，用一个变量`profit`记录利润，只要利润不为负，在当前卖出的话始终是可以盈利的。代码如下：
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        max_profit = 0
        n = len(prices)
        for i in range(1, n):
            profit = prices[i] - prices[i - 1]
            if profit > 0:
                max_profit += profit
        return max_profit
```
- 买卖股票的最佳时机3
此题中说到最多可以进行2笔交易，所以这个题我用动态规划来解了。（因为本人是个菜鸡，逆序遍历，背包变形都不太懂，所以这里简单放一下自己的理解吧。）
1. 首先定义一个状态方程，用一个三维的dp，`dp[i][j][0]` 今天是第i天，进行j次交易了，手上没有股票，d`p[i][j][1]` 今天是第i天，进行j次交易，手上有股票。
2. dp是求无论手上有没有股票，最后的最大利润。所以最后如果股票全都卖出去了，肯定能获得最大利润啦。即`dp[-1][j][0]`
3. 状态转移：
    `dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])` 
    `dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])`

**dp[i][j][0]表示当前手上没有股票，这样的状态可以由两个状态转移得来：前一天没有股票，即dp[i-1][j][0]和前一天手上有股票，但卖出去了，即dp[i-1][j][1] + prices[i]这里需要+ prices[i]因为卖出股票会有收益，要时刻记住我们dp的内涵是最大收益鸭。同理，dp[i][j][1] 可以由：dp[i-1][j][1]和前一天没有股票但前一天买入了，即dp[i-1][j-1][0] - prices[i]转移。**
**代码如下：**
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 2笔
        # 定义卖出股票,交易次数 j + 1
        #dp[i][j][0] 今天是第i天 进行 j次 交易 手上没有股票
        #dp[i][j][1] 今天是第i天 进行 j次 交易 手上有股票
        if not prices: return 0
        n = len(prices)
        dp = [[[0] * 2 for _ in range(3)] for _ in range(n)]
        for k in range(3): #base case i=0
            dp[0][k][0] = 0
            dp[0][k][1] = -prices[0]
        for i in range(1, n):
            for j in range(3):
                if not j:
                    dp[i][j][0] = dp[i-1][j][0]  # 0 base case j=0
                else:
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]) 
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i])   
        return max(dp[-1][0][0], dp[-1][1][0], dp[-1][2][0])
```
**这里还需要注意，最后的输出是每一笔交易，抛售全部股票之后的最大值。也就是说需要比较：👇**
```
return max(dp[-1][0][0], dp[-1][1][0], dp[-1][2][0])
```
```
Q：还有个小问题：为什么j-1状态只受dp[i][j][1]影响？或者j-1状态只受dp[i][j][0]影响？
A：其实不是这样的，要看我们怎么定义交易的笔数了。如果定义卖出股票：交易+1，那么程序可以写成方法一👇，如果定义买入股票交易+1，程序可以写成方法二👇，但要一一对应：
```
```
方法一：
for i in range(1, n):
    for j in range(3):
        if not j:
            dp[i][j][0] = dp[i-1][j][0]  # 0 base case j=0
        else:
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]) 
         dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i])  
```
```
方法二：
for i in range(1, n):
    for j in range(3):
        if not j:
            dp[i][j][0] = dp[i-1][j][0]  # 0 base case j=0
        else:
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]) 
         dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
```
- 买卖股票的最佳时机4
前面已经定义过状态方程了，这里不再赘述。但因为这题中交易次数是k，需要注意k > len(prices)//2的时候，就和前面题2一致（贪心）。代码如下：
 ```
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        # 定义卖出股票,交易次数 j + 1
        #dp[i][j][0] 今天是第i天 进行 j次 交易 手上没有股票
        #dp[i][j][1] 今天是第i天 进行 j次 交易 手上有股票
        if k == 0 or len(prices) < 2:
            return 0
        n = len(prices)
        res = []
        if k > n // 2: 
            max_profit = 0
            for i in range(1,n):
                profit = prices[i] - prices[i - 1]
                if profit > 0:
                    max_profit += profit
            return max_profit
        
        dp = [[[0] * 2 for _ in range(k + 1)]for _ in range(n)]
        for i in range(k + 1):
            dp[0][i][0] = 0
            dp[0][i][1] = -prices[0]
        for i in range(1, n):
            for j in range( k + 1):
                if not j:
                    dp[i][j][0] = dp[i-1][j][0]
                else:
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]) # 在j-1天卖出
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i])  #在第j天买

        for m in range(k + 1):
            res.append(dp[-1][m][0])
        return max(res)
```
- 买卖股票含手续费或需要考虑冷冻期时：
1. 考虑冷冻期，代码如下：
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # dp[i][1] 现在是第i天 持有股票的最大利润
        # dp[i][0] 现在是第i天 不持有股票的最大利润  
        if not prices: return 0
        n = len(prices)
        if n < 2: return 0
        dp = [[0] * 2 for _ in range(n)]
        dp[0][0] = dp[1][0] = 0
        dp[0][1] = -prices[0]
        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]) # 从卖出（0）到买入 需要1天冷冻期 
        return dp[-1][0]
```

2. 考虑手续费，代码如下：
```
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        # 在卖出之后需要从利润里减去手续费 注意是在卖出的时候 买入的不计算
        if not prices: return 0
        n = len(prices)
        if n < 2: return 0
        dp = [[0] * 2 for _ in range(n)]
        dp[0][0] = 0
        dp[0][1] = -prices[0]
        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]- fee) # 卖出-手续费
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])  # 买入
        return dp[-1][0]
```
