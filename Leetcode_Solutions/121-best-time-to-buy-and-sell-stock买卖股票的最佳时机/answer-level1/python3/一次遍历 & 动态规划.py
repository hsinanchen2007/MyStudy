
**测试用例：**

* 功能测试：\[7,4,2,1,4\]
* 边界测试：\[4,3,2,1\]
* 负面测试：\[\]

## 方法一：一遍遍历

维护一个最小值。用当前股票价格减去这个最小值，即为卖出当前股票的最大收益。

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        min_price = float('inf')
        dp = []
        for price in prices:
            dp.append(price - min_price)
            if price < min_price:
                min_price = price
        ans = 0 if max(dp) < 0 else max(dp)
        return ans
```

**复杂度分析：**

* 时间复杂度：O(n)
* 空间复杂度：O(n)

## 方法二：动态规划

股票类问题的动态规划解题模板：

- (i, j, k)表示一个状态：i表示第i天，j表示最多能买卖j次，k=0/1分别表示当前不持有/持有股票。i的取值为0-n（0为哨兵），j的取值为题目要求，k为0/1。
- f(i, j, k)表示状态(i, j, k)下的最大收益。
- f(0, j, 0)=0，表示没开始交易前， 不持有股票的收益为0。
- f(0, j, 1)=-inf，表示没开始交易前，持有股票的收益为破产。
- f(i, 0, 0)=0，表示交易次数为0，不持有股票的收益为0。
- f(i, 0, 1)=-inf，表示交易次数为0，持有股票的收益为破产。
- 状态转移方程：
	- f(i, j, 0) = max(f(i-1, j, 0), f(i-1, j, 1)+prices\[i\])，表示第i天交易次数为j且当前不持有股票的最大收益，要么是前一天也不持有股票本期也不买，要么是前一天持有股票但当期卖了，二者的最大值。
	- f(i, j, 1) = max(f(i-1, j, 1), f(i-1, j+1, 0)-prices\[i\])，表示第i天交易次数为j且当前持有股票的最大收益，要么是前一天持有股票本期不卖，要么是前一天不持有股票但当期买了，二者的最大值。
	- 输出要求买一次，卖一次，因此最后的持有股票应该为0，返回f(-1, -1, 0)（-1表示最后一位）。

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0: return 0
        dp = [[[0 for k in range(2)] for j in range(2)] for i in range(n+1)]
        for j in range(2):
            dp[0][j][1] = -float('inf')
        for i in range(1, n+1):
            dp[i][0][1] = float('inf')
        for i in range(1, n+1):
            for j in range(1, 2):
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i-1])
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i-1])
        return dp[-1][-1][0]
```

**复杂度分析：**

* 时间复杂度：O(n \* J)
* 空间复杂度：O(n \* J)