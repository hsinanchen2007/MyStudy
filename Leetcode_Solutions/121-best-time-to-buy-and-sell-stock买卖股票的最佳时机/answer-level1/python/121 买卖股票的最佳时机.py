### 解题思路
dp问题

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        n = len(prices)
        if n == 0:
            return 0

        dp = [0] * n
        minprices = prices[0]
        for i in range(1, n):
            if prices[i] < minprices:
                minprices = prices[i]
            dp[i] = max(dp[i-1], prices[i]-minprices)

        return dp[n-1]

```


### 解题思路
一次for循环
dp[i] = max(dp[i-1], p[i]-min(p))

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        n = len(prices)
        if n == 0:
            return 0
        minprices = prices[0]
        maxmoney = 0
        for i in range(n):
            if prices[i] < minprices:
                minprices = prices[i]
            maxmoney = max(maxmoney, prices[i]-minprices)
        return maxmoney
```

### 解题思路
两次for循环


### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        n = len(prices)
        maxprice = 0

        for i in range(n):
            for j in range(i, n):
                if prices[i] < prices[j]:
                    curprice = prices[j] - prices[i]
                    if curprice > maxprice:
                        maxprice = curprice
        return maxprice
```