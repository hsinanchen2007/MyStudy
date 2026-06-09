## 算法思路

如果简单的使用循环来计算所有的可能性，那么算法的时间复杂度是 $O(n^2)$。一旦数据量增大会非常耗时，类似的算法问题的算法复杂度应当被优化到 $O(n)$ 。那么就需要使用动态规划（Dynamic Programming），避免每一次的计算都是从头开始，能够借助已有的计算结果来进行更新。

题目的假设比较简单，一天只能进行一次买或卖，且只有买了才能卖。那么我们只需要计算每一天可以得到的最低的买入价以及可操作的最高卖出价，计算它们的差值就可以得到每天可知的最高收入，然后取最大值即可。

以 Example 1 为例，输入是每一天的股票价格`[7,1,5,3,6,4]`，那么第一天只能以 7 买入，第二天可以以 1 买入，第三天的价格5高于第二天价格 1，所以还是在第二天以 1 的价格买入，以此类推，每一天的最优买入价是`[7,1,1,1,1,1]`；买入价需要从第一天向后推算，那么卖出价需要从最后一天向前推算：在第六天只能以 4 卖出，在第五天可以以 6 卖出，第四天的价格为 3，但是可以等到第五天再卖，所以第四天的可操作的最高卖出价6，以此类推得到每一天可操作的最高卖出价是 `[7,6,6,6,6,4]`。那么，每一天可知的最大收益用最高卖出价减去最低买入价即可：`[0,5,5,5,5,4]`，对每一天的最大收益取最大值，可以得到只进行一次买卖的整体最大收益。

![截屏2019-12-2509.56.04.png](https://pic.leetcode-cn.com/045a91fa153b635bc4b2dee0e7412d4460205656994af29952b167e4c0f03b0d-%E6%88%AA%E5%B1%8F2019-12-2509.56.04.png)

## Python 3 实现

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        
        if n==0:
            return 0

        # 初始化 buying_prices、selling_prices
        buying_prices = prices.copy()
        selling_prices = prices.copy()
        
        # 计算每一天的最优买入价
        buying_price = prices[0]
        for i in range(n):
            if buying_price > prices[i]:
                buying_price = prices[i]
            buying_prices[i] = buying_price
            
        # 计算每一天可操作的最高卖出价
        selling_price = prices[n-1]
        for i in range(n-1,-1,-1):
            if selling_price < prices[i]:
                selling_price = prices[i]
            selling_prices[i] = selling_price
            
        max_profit = max([y - x for x, y in zip(buying_prices,selling_prices)])
        
        return max(max_profit, 0)
```

## 算法优化

在上面的算法中，时间复杂度是 $O(n)$ ，空间复杂度是 $O(n)$ ，但是使用了两个长度为 $n$ 的循环，并且使用了两个长度为$n$  的数组来记录买入价和卖出价。其实没有必要记录下每一天的买入和卖出价格，只需要一个变量 `buying_price` 来记录买入价，一旦遇到更低的买入价更新此变量即可；同时也不需要记录每天的卖出价，只需要一个变量 `max_profit` 来记录可获得的最大收益，当收益更高时更新 `max_profit` 即可。
优化后的算法时间复杂度依然是 $O(n)$  ，但是效率得到了显著提高，因为只需要一个循环就可以完成；由于不再需要数组记录买入价和卖出价，因此空间复杂度是 $O(1)$  。


## 优化后的 Python3 代码实现

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        max_profits = 0
        buying_price = prices[0]
        for i in range(len(prices)):
            if prices[i]<buying_price:
                buying_price = prices[i]
            else:
                profit = prices[i] - buying_price
                if profit>max_profits:
                    max_profits = profit
        return max_profits

```

![截屏2019-12-2516.35.40.png](https://pic.leetcode-cn.com/ac35c1b2867ff33ae425bd7362f3342f11ce01e709bedada53dddede2adcb626-%E6%88%AA%E5%B1%8F2019-12-2516.35.40.png)
