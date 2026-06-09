### 解题思路
#### 版本一
$minPrices_{i}$: 表示前`i`天的股票最低价
所以，当天的股票最大利润为 $prices[i] - minPrices[i-1]$ （当天卖出，前`i-1`天最低点买入）
* 时间复杂度： $O(N)$
* 空间复杂度： $O(N)$

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        // minPrices[i]：表示前i天最低的股票价格
        int[] minPrices = new int[prices.length];
        Arrays.fill(minPrices, Integer.MAX_VALUE);
        minPrices[0] = prices[0];

        int profit = 0;
        for (int i = 1; i < prices.length; ++i) {
            int curProfit = prices[i] - minPrices[i-1];
            if (curProfit > 0 && curProfit > profit) {
                profit = curProfit;
            }
            minPrices[i] = Math.min(minPrices[i-1], prices[i]);
        }
        return profit;
    }
}
```

#### 版本二：优化内存
因为只使用了 $minPrices[i-1]$，所以直接改为用 minPrice 记录前`i-1`天的股票最低价
* 时间复杂度： $O(N)$
* 空间复杂度： $O(1)$

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        // 表示前i-1天的股票最低价
        int minPrice = prices[0];

        int profit = 0;
        for (int i = 1; i < prices.length; ++i) {
            int curProfit = prices[i] - minPrice;
            if (curProfit > 0 && curProfit > profit) {
                profit = curProfit;
            }
            minPrice = Math.min(minPrice, prices[i]);
        }
        return profit;
    }
}
```