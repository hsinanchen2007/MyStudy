```
/**
    收益为 多个递增曲线的 （波峰 - 波谷）和
    1、当刚过波峰时计算一次差额（或跑到最后一个计算一次）
    2、计算成功后重置 最大、最小值
    3、由于是 最大值-最小值，最小值计算是在最大值、差额计算前一轮中获得的
    （一定是先有最小值后有最大值）
    4、获得最小值时最大值重置
*/ 
public class Solution {
    public int MaxProfit(int[] prices) {
        int profit = 0;
        int lowestPrice = int.MaxValue;
        int highestPrice = int.MinValue;
        for(int i = 0; i < prices.Length; i++) {
            int price = prices[i];
            bool calculate = false;     
            if (highestPrice <= price) {
                highestPrice = price;
            } else {
                calculate = true;
            }
            if (i == prices.Length - 1 || calculate) {
                if (highestPrice > lowestPrice) {
                    profit += (highestPrice - lowestPrice);
                }
                lowestPrice = int.MaxValue;
                highestPrice = int.MinValue;
            }
            if (lowestPrice >= price) { 
                lowestPrice = price;
                highestPrice = int.MinValue;
            }  
        }
        return profit;
    }
}
// Accepted
//     201/201 cases passed (116 ms)
//     Your runtime beats 82.68 % of csharp submissions
//     Your memory usage beats 5.36 % of csharp submissions (24.1 MB)
```
