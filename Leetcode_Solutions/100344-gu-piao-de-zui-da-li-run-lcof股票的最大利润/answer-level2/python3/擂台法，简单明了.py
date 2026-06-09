### 解题思路 股票的最大利润利用打擂台法。首先，有一个当前日之前的最小价格，初始为第一个价格，然后当前日从第二个价格开始，计算当日价格与当前日之前最小价格之差。注意，这里并没有判断当日价格是否达到最大值，而是判断如果这个差值大于之前的利润，则更新利润。然后，考虑当前日的价格更新当前日之前最小价格，因为在下一轮当前日也算到之前的日期中去了。
此处撰写解题思路

### 代码

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        preMin,ans = prices[0],0
        for i in range(1,len(prices)):
            ans = max(ans,prices[i]-preMin)
            preMin = min(preMin,prices[i])
        return ans

```