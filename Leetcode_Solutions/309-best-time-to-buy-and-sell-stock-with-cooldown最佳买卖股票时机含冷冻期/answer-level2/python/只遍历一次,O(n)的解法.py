最初的想法是动态规划
但由于超时，提出优化方法：**只遍历一次，维护两个变量**。
**时间复杂度O(n)**

maxbuy  表示- 买入或不买入当前股票后手里拥有的最多钱数
maxsell 表示- 卖出或不卖出当前股票后手里拥有的最多钱数
显然，我们要的最后的结果一定是maxsell的最大值。

下面来看看如何初始和转移：

**初始值：**
初始的maxbuy设置为买第0时刻的股票，maxsell因为第0时刻不可能有卖出操作所以设置为0，

**转移：**

直观的转移方程为：
maxbuy = max(maxbuy, maxsell - prices[i])
maxsell = max(maxsell, maxbuy + prices[i]))

很好理解，对于maxbuy：若当前时刻买入股票后maxsell - prices[i]超过maxbuy，则买入，maxbuy更新变大；
                    否则当前时刻不买入，maxbuy维持原值；
        对于maxsell：若当前时刻卖出股票后maxbuy + prices[i]超过maxsell，。。。其余同理。

但这里我们需要注意的是，在决定是否买入（即是否更新maxbuy）时，由于有一天的冷冻期，所以我们使用的maxsell是前天的maxsell；
而决定是否卖出，没有冷冻期，这时使用的maxbuy是昨天的maxbuy即可，此时maxsell[1]是与maxbuy同样的含义，记录当前值，maxsell[0]=maxsell[1]意为一直保存前天的值。
**所以这里要求我们维护两个maxsell（前天和昨天）和一个maxbuy（昨天）**，于是上式调整为：
**
maxbuy = max(maxbuy, maxsell[0] - prices[i])
maxsell = (maxsell[1], max(maxsell[1], maxbuy + prices[i]))**

代码为：
```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        
        # 二、优化
        maxbuy, maxsell = -1 * prices[0], (0, 0)
        for i in range(1, len(prices)):
            maxbuy, maxsell = max(maxbuy, maxsell[0] - prices[i]), (maxsell[1], max(maxsell[1], maxbuy + prices[i]))
        return maxsell[1] 
        
        # 一、动态规划 超时
        # dp = [[float('-inf')] * 2 for _ in range(len(prices))] 
        # dp[0] = [-1 * prices[0], 0] 
        # for i in range(1, len(prices)):
        #     for j in range(i):
        #         if i > j + 1 or j == 0:
        #             dp[i][0] = max(dp[i][0], dp[j][1] - prices[i]) # 买入某股票 拥有的最大的价钱
        #         dp[i][1] = max(dp[i][1], dp[j][0] + prices[i]) # 卖出某股票 拥有的最大的价钱
        # result = 0
        # for d in dp:
        #     result = max(result, max(d))
        # return result
```
