### 解题思路
参考版本：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/309-zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-q/

其实有冷冻期的股票交易可以这样理解：
每一天您的最大收益有三种状态：
**今日持仓的最大收益nowHave**（就是今天有股票的意思，前提是今天有股票）
    1. 包括昨日就持仓，今天什么也没有操作，或者
    2. 昨日没有持仓，而且昨天什么也没有操作，但是今天买了
    所以每日持仓的最大收益是nowHave = Math.max(oldHave, oldNotHaveButDoNothing - prices[i]);
**每日清仓的最大收益nowSell**（就是把自己的所有股票卖出，前提是有股票）
    每日清仓的最大收益是： 昨日持仓的最大收益+今天股票的价格
nowSell = prices[i] + oldHave;
  PS：注意：千万不要理解为今天卖出了，是不是要减去昨天的价格，不不不，这里的oldHave是昨天最大收益的意思，因为昨天持仓的时候，最大收益的计算已经减去昨日的价格了
**今日挂机时间的最大收益nowNotHaveButDoNothing**（既没有股票，也不进行买入股票）
    1. 每日挂机包括，昨日就挂机，今天继续挂机
    2. 昨天因为卖出导致的冷冻期，今天不得不挂机
 当前挂机最大收益是：Math.max(昨天挂机的最大收益,昨天卖出的最大收益）
nowNotHaveButDoNothing = Math.max(oldNotHaveButDoNothing, oldSell);


而最后的最大收益肯定是进入卖出，或者今天挂机两个中的较大值
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
           if (prices.length <= 1) {
            return 0;
        }
        //第一天持有的最大收益是-prices[0]
        int oldHave = -prices[0];
        //第一天不持有，而且什么也不做的最大收益是0
        int oldNotHaveButDoNothing = 0;
        //第一天卖出的最大收益是0
        int oldSell = 0;
        int nowSell,nowHave,nowNotHaveButDoNothing=0;
        for (int i = 0; i < prices.length; i++) {
            //今天卖出
            nowSell = prices[i] + oldHave;
            //今天没有而且今天没有进行任何操作=昨天没有而且没有进行操作,或者昨天卖了,今天没有任何操作
            nowNotHaveButDoNothing = Math.max(oldNotHaveButDoNothing, oldSell);
            //今天有=昨天就有,或者今天买入
            nowHave = Math.max(oldHave, oldNotHaveButDoNothing - prices[i]);

            oldHave = nowHave;
            oldNotHaveButDoNothing = nowNotHaveButDoNothing;
            oldSell = nowSell;
        }

        return Math.max(oldSell, oldNotHaveButDoNothing);
    }

 
    
}
```