假设从第一个元素开始买入
然后计算在下一个元素卖出时的利润
若在下一个元素时卖出的利润小于上一个元素卖出的利润
那么最大利润应该包含上一个元素卖出时的利润
最大利润是不断加入目前最大的利润
```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0) return 0;
        int buy = prices[0];//买入
        int sell;//卖出
        int profit=0;//一开始时设利润为0
        int creament;//卖出时的利润
        int total=0;//总的利润
        for(int i=1;i<prices.length;i++){
            sell = prices[i];
            profit = Math.max(profit,sell - buy);
            creament = sell-buy;
            if(creament<profit){
                //在i时卖出的利润要小于i-1时卖出的利润
                //因此 要在i-1时卖出
                //而i-1的利润被存放在profit中
                total = total + profit;
                //于是在i时买入 
                buy = prices[i];
                //每次买入 它的利润重置为0
                profit = 0;
            }
            else{
                //i时卖出的利润大于i-1时卖出的利润
                //若是最后一个元素 则加入总利润
                if(i==prices.length-1) total =total + profit;
            }
        }
        return total;
    }
}
```
![QQ截图20200321004555.png](https://pic.leetcode-cn.com/b46e85da132fe08c9e0ec6cdc92603183c091dbf8b52a7a9350aa914c566cd32-QQ%E6%88%AA%E5%9B%BE20200321004555.png)

