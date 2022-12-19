### 解题思路
此题可以在只完成一次交易的代码基础上扩展。
基本思路是：
有个游标p（0~size-1），把整个数组拆成两段，第一段（0~p）,第二段（p+1，size-1），然后分别计算两段的利润，每一段的计算逻辑复用一次交易的代码即可。
游标有n种可能，找出n种情况下的最大利润就是最后的结果。

直接暴力算的话（即在游标循环内，再循环算两段的利润），时间复杂度是n^2，因为重复计算了。
类似以下的代码：
```
    public int maxProfit(int[] prices) {
        int result = 0;
        if (prices != null) {
            for (int i = 1; i < prices.length; i++) {//游标循环
                int profitOne = maxProfitInRange(prices, 0, i);//计算前面一段
                int profitTwo = maxProfitInRange(prices, i + 1, prices.length - 1);//计算后面一段
                int profit = profitOne + profitTwo;//利润之和
                result = Math.max(result, profit);
            }
        }
        return result;
    }

    private int maxProfitInRange(int []prices, int start, int end) {
        int profit = 0;
        if (start < end) {
            int min = prices[start];
            for (int i = start + 1; i <= end; i++) {
                min = Math.min(min, prices[i]);
                profit = Math.max(profit, prices[i] - min);
            }
        }
        return profit;
    }
```

我们可以通过数组保存结果，即动态规划的思想，时间复杂度是n。
注意的是，算前面一段的利润时，游标是递增的，即按0~1，0~2 ... 0~n这样的顺序循环在算，没什么问题；
但算后面一段的利润时，如果按0~n，1~n ... n-1~n这样的顺序循环算，类似第一段那样的逻辑，似乎行不通？
那我们可以反过来循环，算第二段的利润时，按n~n-1，n~n-2 ... n~0这样的顺序逆着来算，注意的是，这时候是先卖，再买，也即股市里常说的卖空思想，虽然有点反人类思维，但其实我们只关心买和卖的最大差值就行。
代码如下：
```java
class Solution {
    public int maxProfit(int[] prices) {
        int result = 0;
        if (prices != null && prices.length > 1) {
            int []profitResult = new int[prices.length];//保存前面一段的利润结果
            int minResult =  prices[0];
            for (int i = 1; i < prices.length; i++) {//循环算前面一段
                minResult = Math.min(minResult, prices[i]);
                profitResult[i] = Math.max(profitResult[i - 1], prices[i] - minResult);
            }
            int []profitResultTwo = new int[prices.length];//保存后面一段的利润结果
            int maxResult = prices[prices.length - 1];//这里是保存最大的价格
            for (int i = prices.length - 2; i >= 0; i--) {//循环算后面一段
                maxResult = Math.max(maxResult, prices[i]);
                profitResultTwo[i] = Math.max(profitResultTwo[i + 1], maxResult - prices[i]);
            }
            for (int i = 1; i < prices.length; i++) {//游标循环，比较利润之和的最大值
                int profitOne = profitResult[i];
                int profitTwo = profitResultTwo[i];
                int profit = profitOne + profitTwo;
                result = Math.max(result, profit);
            }
        }
        return result;
    }
}
```