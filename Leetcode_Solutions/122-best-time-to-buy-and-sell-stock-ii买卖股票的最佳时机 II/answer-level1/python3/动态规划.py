## 思路:

这道题要注意一点, 同一天可以先卖出,再买入(等于这天没有操作),比如 `[1, 2, 3]`,我们可以第一天买入,第二天卖出得 `2 - 1`, 第二天再买入,第三天卖出得`3 - 2`,总共`2`,相当于第二天不用操作也行.受上一题思路,如果存在数组为`[a1, a2, a3] ` ,那么 `a3 - a1 = (a2 - a1) + (a3 - a2)`,所以有

```python [1]
def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0: return 0
        res = 0
        for i in range(1, n):
            res += max(0, prices[i] - prices[i-1])
        return res
```



```java [1]
public class BestTimetoBuyandSellStockII {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int res = 0;
        for (int i = 1; i < prices.length; i++) res += Math.max(0, prices[i] - prices[i - 1]);
        return res;
    }
}
```



还有一种思路就是动态规划:

```python [2]
def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        buy = -prices[0]
        sell = 0
        for p in prices[1:]:
            buy = max(buy, sell - p)
            sell = max(sell, p + buy)
        return sell
```



```java [2]
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int buy = -prices[0];
        int sell = 0;
        for (int i = 1; i < prices.length; i++) {
            buy = Math.max(buy, sell - prices[i]);
            sell = Math.max(sell, prices[i] +  buy);
        }
        return sell; 
    }
}
```









