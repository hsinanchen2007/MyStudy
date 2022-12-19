```
class Solution {
    public int maxProfit(int[] prices) {
        int result = 0 ;
        for(int i=1;i<prices.length;i++){
            if(prices[i]>prices[i-1]){
                //这是一个买入卖出的过程。
                //这就是一种贪心，每一步都获取局部最大利益
                //for循环得到全局的最大利益。
                result+=(prices[i]-prices[i-1]);
            }
        }
        return result ;
    }
}
```
其实贪心算法是一种简化性的动态规划，是算法导论上的原话，
贪心也是一种特殊的动态规划。
每一步都直走最优解，最后得到全局最优解。