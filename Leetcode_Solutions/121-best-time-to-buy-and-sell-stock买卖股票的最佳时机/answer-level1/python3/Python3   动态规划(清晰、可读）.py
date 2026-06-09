![](https://pic.leetcode-cn.com/561f6326a135bc83e78e46722619e9b295511964c65157872220c5b6e19048ad-file_1583744986929)

```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        inf = int(1e9)
        minprice = inf
        maxprofit = 0
        for price in prices:
            maxprofit = max(maxprofit, price - minprice)
            minprice = min(minprice, price)
        return maxprofit
```

# 方法1：
![截屏2020-03-09下午4.06.16.png](https://pic.leetcode-cn.com/512bced03fe95f160534b0b9bfcadd8e419c75a66bf6e6dc1976085d77b6459c-%E6%88%AA%E5%B1%8F2020-03-09%E4%B8%8B%E5%8D%884.06.16.png)
 O(n) O(1)
```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        min_price = prices[0]
        max_profit = 0
        for price in prices:
            if price < min_price:
                min_price = price
            if price - min_price > max_profit:
                max_profit = price - min_price
        return max_profit
```
## 方法2：dp 
![截屏2020-03-09下午4.06.16.png](https://pic.leetcode-cn.com/364938d5a245fee98c44c2ad2a652777edd60ed88368f84efb3a8699e7524b68-%E6%88%AA%E5%B1%8F2020-03-09%E4%B8%8B%E5%8D%884.06.16.png)

 O(n) O(n)
```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        min_price = prices[0]
        dp = [0] * (n := len(prices))
        for i in range(n):
            # 第i天最大利润 = max（第i-1天最大利润，第i天可能的最大利润
            dp[i] = max(dp[i-1], prices[i] - min_price )
            min_price = min(min_price, prices[i])
        return dp[-1]

```
## 方法3：dp 优化

![截屏2020-03-09下午3.45.11.png](https://pic.leetcode-cn.com/4aea47c26954c73a69b0624c5d477477a7147f276d4e032aa5c0990fa5305c1e-%E6%88%AA%E5%B1%8F2020-03-09%E4%B8%8B%E5%8D%883.45.11.png)
 O(n) O(1)

### 代码

```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        min_price = prices[0]
        max_profit = 0
        for i in range(len(prices)):
            max_profit = max(prices[i]-min_price, max_profit)
            min_price = min(min_price, prices[i])
        return max_profit
```