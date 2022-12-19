由题意，可转换为
    每天都可以买卖，然后最后累加上涨阶段的差值

当价格下降，我们就等待买入，直到买入的价格是最低的价格
当价格上涨的时候，我们就等待卖出，直到卖出的价格是最高价

最后累加最低买入和最高卖出，就是我们的最大利润









class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        if(prices.length == 0) return 0;
        int temp = prices[0];
        for(int i=1; i<prices.length; i++){
            if(temp > prices[i]){
                temp = prices[i];
            }
            else{
                ans = ans + prices[i] - temp;
                temp = prices[i];
            }
        }
        return ans;
    }
}