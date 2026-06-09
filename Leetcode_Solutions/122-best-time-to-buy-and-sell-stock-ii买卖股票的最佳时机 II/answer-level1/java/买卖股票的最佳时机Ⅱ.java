根据题解思路，
数组后项减前项，为正则有收益，为负数忽略
逐步获取所有有利润的区间，累加，返回

代码块
```
class Solution {
    public int maxProfit(int[] prices) {
        int count = 0;
        if(prices.length<2) return 0;
        for(int i=0;i<prices.length-1;i++){
            if(prices[i+1]-prices[i]>0)
            count += prices[i+1] - prices[i];
        }
        return count;
    }
}```