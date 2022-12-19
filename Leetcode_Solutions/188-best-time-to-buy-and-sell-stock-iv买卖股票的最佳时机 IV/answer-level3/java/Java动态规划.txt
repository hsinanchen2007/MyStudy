### 解题思路
首先需要判断k的大小，如果k >= n/2 的话，这样其实就不存在交易次数的限制，可以按照正常的买卖股票来处理
我们定义两个数组，buy 和sell 分别存放第i次交易中买入和卖出后的收益

### 代码

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        if(prices == null || prices.length == 0) return 0;
        int n = prices.length;

        if(k >= n/2){
            int profit = 0;
            for(int i = 1; i < n; i++){
                if(prices[i] > prices[i-1]){
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }

        int[] buy = new int[k+1];
        int[] sell = new int[k+1];
        Arrays.fill(buy, Integer.MIN_VALUE);
        for(int cur : prices){
            for(int i = 1; i <= k; i++){
                if(buy[i] < sell[i-1] - cur){
                    buy[i] = sell[i-1] -cur;
                }
                if(sell[i] < buy[i] + cur){
                    sell[i] = buy[i] + cur;
                }
            }
        }
        return sell[k];
    }
}
```