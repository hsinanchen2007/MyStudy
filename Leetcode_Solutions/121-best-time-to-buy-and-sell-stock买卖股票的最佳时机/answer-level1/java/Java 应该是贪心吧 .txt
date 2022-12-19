```
class Solution {
    public int maxProfit(int[] prices) {
        /*
        遍历数组 ，不断迭代两个值
        一个是买入的价格 要最小
        另一个是利润 要最大
        类似于贪心
        */
        if(prices.length==0) return 0;
        int buy = prices[0];//一开始买入
        int sell;//卖出价格
        int profit=0;//利润 默认为0
        for(int i=1;i<prices.length;i++){
            sell = prices[i];//假设在第i日卖出
            profit=Math.max(profit,sell-buy);//迭代利润的最大值
            buy=Math.min(buy,prices[i]);//迭代买入的最小值
        }
        return profit;
    }
}
```
![QQ截图20200320210325.png](https://pic.leetcode-cn.com/b153f89a62f01383d82d3ee2f2a5d036f0722e5ec1e3ac6545dcf060d2326bcb-QQ%E6%88%AA%E5%9B%BE20200320210325.png)
