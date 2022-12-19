### 解法一 
我们通过记录每天的持有股票或者不持有股票可能的最大利润，来不断地往后遍历。
因为存在冷冻期，所以当天卖了之后所获得的最大利润也等于明天的最大利润，因为冷冻期所以不能买卖。到第三天才能买入。
所以有如下推断：
今天没有股票的利润，有两种可能，一是昨天就没有持有股票今天不买利润不变，二是昨天有股票今天卖出。取两者最大值。
dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
今天持有股票的利润，有两种可能，一是昨天就有股票今天不卖利润不变，二是昨天没有股票今天买了，但是因为有冷冻期的存在，如果想今天能买，那么昨天未持有股票的最大利润应该是等于前天未持有股票的最大利润(因为前天卖了，第二天冷冻期只能保持利润)
dp[i][1]=Math.max(dp[i-1][1],dp[i-2][0]-prices[i]);
```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length<=1) return 0;
        int length=prices.length;
        int dp[][]=new int[length][2];//第一维下标表示第几天，第二维下标表示持有或者不持有股票。值为最大利润
        dp[0][0]=0;//第一天未持有股票
        dp[0][1]=-prices[0];//第一天买了股票
        dp[1][0]=Math.max(dp[0][0],dp[0][1]+prices[1]);//第二天未有股票，昨天就没有，昨天有今天卖
        dp[1][1]=Math.max(dp[0][1],dp[0][0]-prices[1]);//第二天有股票，昨天就有，昨天没有今天买。
        for(int i=2;i<prices.length;i++){
            //今天没有持有股票，有两种可能，
            //昨天就没有，今天卖了
            dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            //今天有股票,有两种可能
            //昨天就股票，昨天没有股票今天买。但是因为有冷冻期1天，所以利润应该跟前天未有股票的价格一样。因为前一天如果卖了股票，昨天则不能操作.
            dp[i][1]=Math.max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }
        return dp[length-1][0];
    }
}
代码优化，我们发现当天的最大利润只需要昨天的持有以及未持有股票的最大利润，因为冷冻期还需要前天未持有股票的最大利润。所以我们只需要用三个int存储这三个利润即可。
不需要存储每天的最大利润。
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length<=1) return 0;
        int length=prices.length;
        int beforeYesterdayMaxNot=0;//第一天未持有股票的最大利润，或者说是前天未持有股票的最大利润
        //昨天未持有股票的最大利润，一是前天就没有，二是前天有股票今天卖了。这边计算的是第二天的利润
        int yesterdayMaxNot=Math.max(0,-prices[0]+prices[1]);
        //昨天有股票的最大利润，一是前天就有，二是前天没有今天买入。这边计算的是第二天的利润
        int yesterdayMaxHave=Math.max(-prices[0],beforeYesterdayMaxNot-prices[1]);
        for(int i=2;i<prices.length;i++){
            int preMaxNot=yesterdayMaxNot;
            //今天没有持有股票，有两种可能，
            //昨天就没有，今天卖了
            yesterdayMaxNot=Math.max(yesterdayMaxNot,yesterdayMaxHave+prices[i]);
            //今天有股票,有两种可能
            //昨天就股票，昨天没有股票今天买。但是因为有冷冻期1天，所以利润应该跟前天未有股票的价格一样。因为前一天如果卖了股票，昨天则不能操作.
            yesterdayMaxHave=Math.max(yesterdayMaxHave,beforeYesterdayMaxNot-prices[i]);
            beforeYesterdayMaxNot=preMaxNot;
        }
        return yesterdayMaxNot;
    }
}
```
### 解法二
上面是通过记录，持有股票以及未持有股票的最大利润来计算的，同时我们为了应对冷冻期，通过操作前的未持有股票的价格来计算。
看起来似乎不太好理解，那么我们可以将冷冻期的最大利润也给记录下来。当前冷冻期的最大利润其实就等于昨天未持有股票的最大利润.
```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length<=1) return 0;
        int length=prices.length;
        int buy[]=new int[length];//存储第i天持有的最大利润
        int sell[]=new int[length];//存储第i天未持有股票的最大利润
        int cool[]=new int[length];//存储第i天冷冻状态的最大利润
        buy[0]=-prices[0];//第一天持有股票
        //这边第一天未持有股票以及冷冻期，其实最大利润都为0，所以不需要初始化
        for(int i=1;i<prices.length;i++){
            //如果今天要持有股票，有两方式
            //1、今天刚买入，需要昨天冷冻状态的最大利润
            //2、今天只是持有，不操作
            buy[i]=Math.max(cool[i-1]-prices[i],buy[i-1]);
            //今天不持有股票，有两种方式
            //1、今天刚卖出
            //2、昨天就未持有股票，今天不操作。
            sell[i]=Math.max(buy[i-1]+prices[i],sell[i-1]);
            //今天是冷冻期,那么今天冷冻期的利润，只能是昨天未持有股票的最大利润.因为今天冷冻，肯定是昨天卖出了
            cool[i]=sell[i-1];
        }
        return sell[length-1];
    }
}
```

