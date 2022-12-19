### 解题思路
    峰谷法:我们只需要每次都增加。我们就计数就行了
    时间复杂度：o(n)
    空间复杂度：o(1)
### 代码


class Solution {
    public int maxProfit(int[] prices) {
        int count = 0;
        for(int i = 1;i < prices.length;i++){
           if(prices[i] > prices[i-1]){
                count += prices[i] - prices[i - 1];
           }
        }
        return count;
    }
}