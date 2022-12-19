题目说了，不能多次重复买，所以只要我当天卖得比前一天贵，那就是赚。只挑赚的买就最大

```
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        for(int i=1;i<prices.length;i++){
            max = Math.max(prices[i]-prices[i-1]+max,max);
        }
        return max;
    }
}
```
