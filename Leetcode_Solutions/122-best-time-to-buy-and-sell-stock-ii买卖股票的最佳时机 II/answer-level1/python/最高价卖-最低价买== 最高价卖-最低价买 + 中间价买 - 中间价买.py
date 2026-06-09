### 解题思路
> 核心思想：最高价卖-最低价买== 最高价卖-最低价买 + 中间价买 - 中间价买

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        '''
        核心思想：最高价卖-最低价买== 最高价卖-最低价买 + 中间价买 - 中间价买
        执行用时 :36 ms, 在所有 Python3 提交中击败了97.14%的用户
        内存消耗 :14.5 MB, 在所有 Python3 提交中击败了8.75%的用户
        :param prices:
        :return:
        '''
        if len(prices) < 2:
            return 0
        ans = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                ans += prices[i] - prices[i - 1]

        return ans

    def maxProfit1(self, prices: List[int]) -> int:
        '''
        笨办法，低谷买， 高峰下落时卖；注意最后一个位置连续上升没有拐点要卖的判定；
        执行用时 :44 ms, 在所有 Python3 提交中击败了88.88%的用户
        内存消耗 :14.3 MB, 在所有 Python3 提交中击败了8.85%的用户
        :param prices:
        :return:
        '''
        if len(prices) < 2:
            return 0
        ans = 0
        start = prices[0]
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                if start > prices[i - 1]:
                    start = prices[i - 1]
            if prices[i] < prices[i - 1]:
                # sale
                if prices[i - 1] > start:
                    ans += prices[i - 1] - start
                    start = prices[i]
                else:
                    start = prices[i]
        if prices[-1] > start:
            ans += prices[-1] - start
        return ans


```

补充一个DP的方法：
```python3
    def maxProfit(self, prices: List[int]) -> int:
        '''
        dp方法，二维数据记录整体收益， 注意状态转换方法是两种模式相互切换；详细参考如下题解
        // 0：持有现金
        // 1：持有股票
        // 状态转移：0 → 1 → 0 → 1 → 0 → 1 → 0
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        作者：liweiwei1419
        链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/
        :param prices:
        :return:
        '''
        if len(prices) < 2:
            return 0
        dp_cash = [0] * len(prices)
        dp_stock = [0] * len(prices)
        dp_stock[0] = -prices[0]  # 钱花掉，买股票
        for i in range(1, len(prices)):
            dp_stock[i] = max(dp_stock[i - 1], dp_cash[i - 1] - prices[i])
            dp_cash[i] = max(dp_cash[i - 1], dp_stock[i - 1] + prices[i])

        return dp_cash[-1]
```