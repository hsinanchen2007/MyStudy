### 解题思路
1. 首先通过分析题目，买股票之前必须先卖掉股票。所以每两次买卖之间不存在联系。基于贪心的思想，当遇到当前最大的收益时，就卖掉股票。
2. 具体思想是，当第i天的股票价格大于等于第i+1天时，就遇到了当前最大的出售价格，此时最终收益profit需加上当前收益prices[i] - minPrice。同时minPrice要更新为prices[i+1].
3. 因为比较的是当前天和后一天，所以最后一天要单独拿出来，即最终收益profit加上收益prices[prices.length-1] - minPrice。无论最后一天是否是出售日，不影响结果。
4. 上面的方法是自己想的，有的拗。更直接的思想是官方题解的最后一种。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length == 0) return 0;
        int profit = 0, minPrice = prices[0];
        for(int i = 0; i < prices.length-1; i++){
            if(prices[i] >= prices[i+1]){
                profit += prices[i] - minPrice;
                minPrice = prices[i+1];
            }
        }
        profit += prices[prices.length-1] - minPrice;
        return profit;
    }
}
```