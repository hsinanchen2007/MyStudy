### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
         int len = prices.Length;
        int max = int.MinValue;
        int res = 0;
        for(int i = len-1; i > 0; i--)
        {
            max = Math.Max(max,prices[i]);
            res = Math.Max(res,max - prices[i-1]);
        }
        return res;
    }
}

```