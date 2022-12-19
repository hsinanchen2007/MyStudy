### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        int maxPro = 0;
        if(prices.Length == 0)return 0;
        for(int i = 0;i<prices.Length-1;i++)
            if(prices[i+1]>prices[i]) maxPro += (-prices[i]+prices[i+1]); 
        return maxPro;
    }
}
```