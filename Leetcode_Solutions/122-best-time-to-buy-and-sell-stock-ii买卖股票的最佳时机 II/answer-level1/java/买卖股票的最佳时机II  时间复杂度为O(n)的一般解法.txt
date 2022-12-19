解题思路：股票价格数组可以分为三种情况，分别是：逐渐递增、逐渐递减、无序。设置两个变量buy、sell纪录购买和售出的价格，初值均设为第一天的价格，设置变量profit纪录利润，初值为0。在逐渐递增的情况下，最大利润其实就是第一天买最后一天卖，其值为按序依次将数组前后项的差值相加；在逐渐递减的情况下，不计算利润（即利润默认为0);在无序的情况下可以发现最大利润值其实就是将数组中的峰值相加（即售出价格一定是处于局部的峰顶）。
解法如下：

class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0)//防止空数组
            return 0;
        int buy=prices[0];
        int sell=prices[0];
        int profit=0;
        for(int i=0;i<=prices.length-1;i++)
        {
            if(prices[i]<buy)
            {
                buy=prices[i];
                continue;//递减的情况下不计算profit，即profit为初值0
            }
            else
            {
                sell=prices[i];
                profit+=sell-buy;
                buy=prices[i];
                if(i<prices.length-1&&prices[i+1]<prices[i])//数组无序的情况下，说明此时价格处于峰顶
                    buy=prices[i+1];
            }
        }
        return profit;
    }
}