终于搞清楚这段代码的意思了。这里总结一下。动态规划就是把每次的结果保存起来。假如amount是按照1,2,3,4,5....11的顺序递增。
amount=1时，需要一个1；
amount=2时，需要一个2或者两个1.
amount=3时，需要一个1和一个2；
amount=4时，需要两个2；
amount=5时，需要一个3和一个2；而3是需要1个2和一个1。
...
也就是5用到了1,2,3,4中的结果，然而通过比较大小求出最小的结果。其中，用到哪个硬币，就+1。比方说，amount=4时，减1，就相当于用了1和dp【3】的结果。减2，就相当于用到了2和dp[2]的结果。
感觉就是递归。只不过动态规划数组里保存的是每次递归的结果，这样拿出来直接比较就可以。和贪心的区别在于贪心用最近的结果就可以，而动态规划建立了一个结果集，需要每次比较这些结果，然后取最小。比如说贪心的时候，amount=5时可以直接用amount=4的结果。而动态规划需要比较dp[4],dp[3]和dp[0]数组的结果。
```
class Solution {
    public int coinChange(int[] coins, int amount) {
    	int[] dp = new int[amount+1];
        for(int i=1;i<=amount;i++){
            dp[i]=99999;
            for(int v:coins){
                if(i>=v){
                    dp[i]=Math.min(dp[i-v]+1,dp[i]);
                }
            }
        }
        return dp[amount]==99999?-1:dp[amount];
    }
}
```
