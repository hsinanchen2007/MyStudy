**解法一**

二维动态规划，关键在于定义出详细的每个状态，然后转换就很容易了，参考了[liweiwei大佬的题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/dong-tai-gui-hua-by-liweiwei1419-7/)

```java
public int maxProfit(int[] prices){
    if (prices==null || prices.length<=0) {
        return 0;
    }
    //状态定义：
    //j=0 什么都不做
    //j=1 第一次买入
    //j=2 第一次卖出
    //j=3 第二次买入
    //j=4 第二次卖出
    int[][] dp=new int[prices.length][5];
    //这样会溢出
    //Arrays.fill(dp[0],Integer.MIN_VALUE);
    //这样可以过,但是感觉还是判断一下好
    //Arrays.fill(dp[0],-0x3f3f3f3f);
    int INF=Integer.MIN_VALUE,n=prices.length;
    Arrays.fill(dp[0],INF); //不可达状态
    dp[0][0]=0;
    dp[0][1]=-prices[0];
    for(int i=1;i<n;i++){
        dp[i][0]=0;
        dp[i][1]=Math.max(-prices[i],dp[i-1][1]);
        dp[i][2]=Math.max(dp[i-1][1]+prices[i],dp[i-1][2]);
        //第i天处于第二次买入状态最大值 = max(前一天处于第一次卖出状态 今天又新买入 , 前一天处于第二次买入状态)
        dp[i][3]=Math.max(dp[i-1][2]!=INF?dp[i-1][2]-prices[i]:INF,dp[i-1][3]);
        dp[i][4]=Math.max(dp[i-1][3]!=INF?dp[i-1][3]+prices[i]:INF,dp[i-1][4]);
    }
    return Math.max(Math.max(dp[n-1][0],dp[n-1][2]),dp[n-1][4]);
}
```
> 因为题目的数据不是特别大，没有超过`10^9` 可以直接初始化为 `-0x3f3f3f3f` 这样就不用判断前面的状态是否可达了，见下方一维解法

**解法二**

优化成一维的

```java
public int maxProfit(int[] prices){
    if (prices==null || prices.length<=0) {
        return 0;
    }
    int[] dp=new int[5];
    int n=prices.length;
    Arrays.fill(dp,-0x3f3f3f3f);
    dp[0]=0;
    dp[1]=-prices[0];
    for(int i=1;i<n;i++){
        //逆序递推避免覆盖(这题其实正着写也是对的,相邻的状态不会同时更新,但是为了规范最好还是逆序写)
        dp[4]=Math.max(dp[3]+prices[i],dp[4]);
        dp[3]=Math.max(dp[2]-prices[i],dp[3]);
        dp[2]=Math.max(dp[1]+prices[i],dp[2]);
        dp[1]=Math.max(-prices[i],dp[1]);
        dp[0]=0;
    }
    return Math.max(Math.max(dp[0],dp[2]),dp[4]);
}
```
**通解**
其实上面的代码规律已经非常明显了，假设可以`k`次交易，那么就有`2*k+1`种状态，观察上面的代码，都是在`j`为奇数的时候买入，偶数的时候卖出，所以我们只需要判断`j`的奇偶就可以把状态的转换改成循环，循环中统计偶数时候的最大收益，进而就得到了一个通解
> 其实这个奇数偶数的判断可以通过多加一维的状态0，1来代表卖出与否来简化，我这里就不写了
```
    public int maxProfit(int k, int[] prices) {
        if (prices==null || prices.length<=0 || k<=0) {
            return 0;
        }
        if(k>prices.length/2){
            return maxProfit(prices);
        }
        int[] dp=new int[2*k+1];
        int n=prices.length;
        int res=0;
        Arrays.fill(dp,-0x3f3f3f3f);
        dp[0]=0;
        dp[1]=-prices[0];
        for(int i=1;i<n;i++){
            //k次交易,2*k+1种状态
            dp[0]=0;
            for(int j=2*k;j>0;j--){
                if((j&1)==1){
                    dp[j]=Math.max(dp[j-1]-prices[i],dp[j]);
                }else{
                    dp[j]=Math.max(dp[j-1]+prices[i],dp[j]);
                    res=Math.max(dp[j],res);
                }
            }
        }
        return res;
    }

    public int maxProfit(int[] prices) {
        if (prices==null || prices.length<=0) {
            return 0;
        }
        int ans=0;
        for (int i=1;i<prices.length;i++) {
            if (prices[i]>prices[i-1]) {
                ans+=prices[i]-prices[i-1];
            }
        }
        return ans;
    }
```
