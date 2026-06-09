### 解题思路
使用双指针：
slow_pointer : 总是指向最近发生峰值的谷底。
fast_pointer : 总是指向最先的值。
价格上升期： fast_pointer (prices[i]) 大于等于 prices[i-1]
    holding = true; //当前或前一点已经买入股票
到达峰值： fast_pointer (prices[i]) 小于 prices[i-1] 
    holding：
        利益结算
    !holding:
        价格一直下跌中，不买入
    slow_pointer 赋值当前最新低点

### 代码

```java
class Solution {
    public static  int maxProfit(int[] prices) {
        if(prices.length<=0){
            return 0;
        }
        int slow_pointer = prices[0];
        int fast_pointer = prices[0];
        int profit = 0;
        boolean holding = false;
        for(int i=1;i<prices.length;i++){
            fast_pointer = prices[i];
            if(fast_pointer >= prices[i-1]){ // increasing stage
                holding = true;
                continue;
            }else{ // we shall sell it at i-1
                if(holding){
                    profit += (prices[i-1] -slow_pointer);
                    holding = false;
                }
                slow_pointer = fast_pointer;
            }
        }
        profit += (fast_pointer -slow_pointer);
        return profit;
    }
}
```