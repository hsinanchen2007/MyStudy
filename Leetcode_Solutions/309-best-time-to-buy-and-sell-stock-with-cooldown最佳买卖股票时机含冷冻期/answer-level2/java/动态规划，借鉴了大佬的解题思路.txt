
// 95-100(看运气)
//     执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户内存消耗 :35.1 MB, 
//     在所有 Java 提交中击败了84.74%的用户
```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length <2) return 0;
        int n = prices.length;
        int dp_i0 = 0;
        int dp_i1 = 0;
        int pre = 0;
        for(int i = 0; i< n ; i++){
            if(i == 0){
*//传递方程：   当天没持有股票：dp[i][0] = max(dp[i-2][0], dp[i-2][1] + prices[i]) 不交易或者卖出    
//            当天持有股票：  dp[i][1] = max(dp[i-2][1], dp[i-2][0] + prices[i]) 不交易或者买入*

                // dp[i][0] = Math.max(dp[-2][0], dp[-2][1] + prices[i]);
                // =Math.max(0（没开始交易且不持有利润0）, -infinity（负无穷表示不可能） + prices[i])=0
                dp_i0 = 0;
                
                // dp[i][1] = Math.max(dp[-2][1], dp[-2][0] - prices[i]);
                // =Math.max(-infinity（负无穷表示不可能），0（没开始交易且不持有利润0） - prices[i])   
                // = -prices[i]
                dp_i1 = -prices[i];
                
                //类似没开始交易且不持有利润为0
                pre = 0;
                continue;
            }
            int temp = dp_i0;   //上一次的值
            dp_i0 = Math.max(dp_i0, dp_i1 + prices[i]); //不交易或者卖出
            dp_i1 = Math.max(dp_i1, pre - prices[i]);   //不交易或者买入
            pre = temp;     //因为要隔一天才能交易，所以保存上一次的值传给下一次买入的时候使用
        }
        return dp_i0;
    }
}

```
记录一下首次回答，加油！大家都