### 解题思路
简单的贪心算法即可通过。

### 代码

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        int profit;
        int maxProfit = 0;
        for(int i=0; i<prices.Length; i++) {
            for(int j=i+1; j<prices.Length; j++) {
                profit = prices[j] - prices[i];
                if(profit >= maxProfit) maxProfit = profit;
            }
        }
        return maxProfit;
    }
}
```