解题思路：由题可知，三个状态，初始状态，上升状态，下降状态
每次**上升状态**或者**峰顶**计算利润并更新**最大利润**，**下降状态**更新**最小股票价格**
差不多就这样
```
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2)
            return 0;
        final int BEGIN = 0;//初始状态
        final int UP = 1;//上升状态
        final int DOWN = 2;//下降状态
        int max_profit = 0;//最大利润
        int tem_profit=0;//记录从前面最近最低点实时最高利润
        int low = Integer.MAX_VALUE;//记录前面最低的价格
        int STATE = BEGIN;
        int i = 1;
        while (i < prices.length) {
            int price = prices[i] - prices[i - 1];//今天与昨天的价格差
            switch (STATE) {
                case BEGIN:
                    if (price < 0) {
                        STATE = DOWN;
                        low = prices[i];
                    } else if (price > 0) {
                        STATE = UP;
                        low = prices[i - 1];
                        max_profit = price;
                    } else
                        STATE = BEGIN;
                    break;

                case UP:
                    if (price < 0) {
                        STATE = DOWN;
                        tem_profit = prices[i - 1]-low;
                        max_profit = max_profit > tem_profit ? max_profit : tem_profit;
                        low = low > prices[i - 1] ? prices[i - 1] : low;
                    } else {
                        STATE = UP;
                        tem_profit = prices[i]-low;
                        max_profit = max_profit > tem_profit ? max_profit : tem_profit;
                    }
                    break;

                case DOWN:
                    if (price > 0) {
                        STATE = UP;
                        low = low > prices[i - 1] ? prices[i - 1] : low;
                        tem_profit = prices[i] -low;
                        max_profit = max_profit > tem_profit ? max_profit : tem_profit;
                    } else
                        STATE = DOWN;
                    break;
            }
            i++;
        }
        return max_profit;
    }
}
```
