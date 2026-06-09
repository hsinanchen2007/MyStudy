
**测试用例：**

* 功能测试：\[7,  1, 5, 3, 6, 4\]
* 边界测试：\[3, 2 ,1\]
* 负面测试：\[\]

## 方法一：动态规划

参考121题股票问题动态规划模板，将j省略，没有买卖次数的限制。

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0: return 0
        dp = [[0 for k in range(2)] for i in range(n+1)]
        dp[0][1] = -float('inf')
        for i in range(1, n+1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i-1])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i-1])
        return dp[-1][0]
```

**复杂度分析：**

* 时间复杂度：O(n)
* 空间复杂度：O(n)

## 方法二：贪心

只要后一天比前一天的金额大，当前金额比前一天的金额大，就卖一次买一次。

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                ans += prices[i] - prices[i-1]
        return ans
```

**复杂度分析：**

* 时间复杂度：O(n)
* 空间复杂度：O(1)