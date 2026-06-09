每天收盘后有两种状态：手持现金，手持股票
这两种状态都是从昨天的状态转换而来的；
手持现金：1、昨天也是手持现金，今天继续观望 2、昨天手持股票然后今天卖了
手持股票：1、昨天手持现金，今天买入 2、昨天手持股票，今天继续持有
两种情况取最大值就是最佳的策略；
```java
class Solution {

    public int maxProfit(int[] prices, int fee) {
        if(prices.length<2){
            return 0;
        }
        int cash=0;
        int stock=-prices[0];
        for(int i=1;i<prices.length;i++){
            int newcash=Math.max(cash,prices[i]-fee+stock);
            int newstock=Math.max(cash-prices[i],stock);
            cash=newcash;
            stock=newstock;
        }
        return cash;
    }
}
```
