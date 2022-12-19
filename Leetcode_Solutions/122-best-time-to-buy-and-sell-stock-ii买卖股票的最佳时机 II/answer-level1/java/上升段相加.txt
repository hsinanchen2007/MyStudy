### 解题思路

观察曲线图，把所有上升段所获得的profit相加即为最优解。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0 ;
        int i = 0;
        for(int j = 1; j < prices.length; j++){
            if(prices[j] < prices[i]){
                i++;
                //prices[i] = prices[j];
            }
            else{
                int profit = prices[j] - prices[i];
                maxprofit = maxprofit + profit;
                i++;
            }
        }
        return maxprofit;
    }
}
```