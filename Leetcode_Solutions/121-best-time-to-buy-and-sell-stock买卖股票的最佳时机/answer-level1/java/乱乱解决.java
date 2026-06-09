```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n <= 1:
            return 0
        max1 = 0
        min1 = prices[0]
        for i in range(1, n):
            max1 = max(max1, prices[i] - min1)
            min1 = min(min1, prices[i])
        return max1
```
```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length <= 1) return 0;
        int min = prices[0];
        int maxProfit = 0;//定义之前最小值，以及最大利润
        for(int i = 1; i < prices.length; i++) {//遍历数组
            maxProfit = Math.max(maxProfit, prices[i] - min);//更新最大利润，当前最大和当前金额减去之前最小值
            min = Math.min(min, prices[i]);//找当前元素之前的最小值，以便更新最大利润
        }
        return maxProfit;
    }
}
```
