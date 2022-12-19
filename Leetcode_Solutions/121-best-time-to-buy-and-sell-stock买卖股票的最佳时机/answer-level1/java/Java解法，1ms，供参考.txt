### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0) return 0;
        int minBuy=prices[0];
        int maxProfit=0;
        for(int read=0;read<prices.length;read++){
            if(prices[read]<minBuy) minBuy=prices[read];
            maxProfit=Math.max(maxProfit,prices[read]-minBuy);
        }
        return maxProfit;
    }
}
```