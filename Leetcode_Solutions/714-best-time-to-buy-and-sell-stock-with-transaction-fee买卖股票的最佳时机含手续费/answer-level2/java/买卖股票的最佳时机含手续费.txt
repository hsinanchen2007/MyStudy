**两种思路解决**

每天都有两种状态，持有了股票，未持有股票（这样可以忽略掉卖必须在买之前这个问题，因为for循环的大流程保证了卖之前必须是买）
1.在卖出股票的时候进行结算（减去手续费）
    base case：0位置如果是未持有状态则价值为0,0位置如果是持有状态则价值为-prices[0]
2.在买入的时候进行结算（加上手续费）
    base case:0位置如果是未持有状态则价值为0.0位置如果是持有状态则价值为-(prices[0]+fee）=-prices[0]-fee
```
class Solution {
    /**
    public int maxProfit(int[] prices, int fee) {
        int noHold = 0, hold = -prices[0];
        for (int i = 1; i < prices.length; i++) {
            int tmp = noHold;
            //未持有状态---1.昨天也是未持有状态，2.昨天是持有状态今天卖掉股票。
            noHold = Math.max(noHold, hold + prices[i] - fee);
            //持有状态-----1.昨天也是持有状态，2.昨天是未持有状态，今天买入股票导致变成持有状态
            hold = Math.max(hold, tmp - prices[i]);
        }
        //股票价值不可能是负数，所以最后一天未持有状态肯定是最大的
        return noHold;
    }*/
        public int maxProfit(int[] prices, int fee) {
        int noHold = 0, hold = -prices[0]-fee;
        for (int i = 1; i < prices.length; i++) {
            int tmp = noHold;
            noHold = Math.max(noHold, hold + prices[i]);
            hold = Math.max(hold, tmp - prices[i]-fee);
        }
        return noHold;
    }
}
```