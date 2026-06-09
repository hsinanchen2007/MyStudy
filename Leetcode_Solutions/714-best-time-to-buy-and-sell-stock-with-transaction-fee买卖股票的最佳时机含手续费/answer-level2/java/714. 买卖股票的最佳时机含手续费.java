### 解法一 用二维数组来解决，一维代表第几天，二维代表是否持有股票
```
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if(prices.length<=1) return 0;
        int length=prices.length;
        //一维下标表示第几天，二维下标0表示未持有股票，1标识持有股票
        int dp[][]=new int[length][2];
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<length;i++){
            //今天未持有股票
            //1、昨天就没有股票，今天也不买
            //2、昨天有股票，今天卖出，需要扣除手续费
            dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
            //今天持有股票
            //1、昨天就有股票，今天不卖
            //2、昨天没有股票，今天买入
            dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[length-1][0];
    }
}
```
### 解法二 对解法一进一步优化，发现当天的利润只跟前一天有关系，所以只需要用两个int值来记录前一天的持有股票和未持有股票的最大利润.
```
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if(prices.length<=1) return 0;
        int length=prices.length;
        int preDayHold=-prices[0];//前一天持有股票的最大利润，这边是第一天的
        int preDaySell=0;//前一天未持有股票的最大利润,这边是第一天的
        for(int i=1;i<length;i++){
            int preSell=preDaySell;//记录一下，不然下面会被今天给覆盖掉
            //今天未持有股票
            //1、昨天就没有股票，今天也不买
            //2、昨天有股票，今天卖出，需要扣除手续费
            preDaySell=Math.max(preDaySell,preDayHold+prices[i]-fee);
            //今天持有股票
            //1、昨天就有股票，今天不卖
            //2、昨天没有股票，今天买入
            preDayHold=Math.max(preDayHold,preSell-prices[i]);
        }
        return preDaySell;
    }
}
```
其实上面的for循环里面的临时变量是可以取消的，但是第一反应还是会通过临时变量记录，以防产生影响，看到了官方提交才发现是可以不用临时变量的。
1. cash = Math.max(cash, hold + prices[i] - fee); 
2. hold = Math.max(hold, cash - prices[i]); 我们就只看公式，不看其他的
3. cash 有两种可能性要么等于cash，要么等于hold + prices[i] - fee；
4. hold 有两种可能性要么等于hold,要么等于cash - prices[i]；
5. cash如果等于cash，那么本身值就没有发生变化，所以对下面的计算也就没有影响.
6. cash如果等于hold + prices[i] - fee，我们将cash带入hold公式里面。
7. hold = Math.max(hold, hold + prices[i] - fee - prices[i]);==>hold = Math.max(hold, hold - fee);
8. 可以看到买入当天+ prices[i]跟卖出当天- prices[i]正好抵消了，只剩下hold-fee了，而hold-fee是肯定小于hold的，也就是说hold没有变化.
9. 而一天最多只能有一个状态的最大利润会发生变化(买入hold会变，卖出cash会变，不买不卖cash跟hold都不变)
10. 综上结论：如果cash值不变，那么对hold的计算就不会有影响，而如果cash值变了，通过上面带入公式可知，hold最大值会取自身。
