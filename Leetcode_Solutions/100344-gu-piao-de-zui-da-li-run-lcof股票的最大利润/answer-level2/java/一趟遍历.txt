### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0) return 0;
        int min=prices[0],max=0;
        int min_index=0;
        int ans=0;
        for(int i=1;i<prices.length;++i)
        {
            if(prices[i]>min&&min_index<i)
            {
                max=prices[i];
                ans=Math.max(max-min,ans);
            }
            if(min>prices[i])
            {
                min=prices[i];
                min_index=i;
            }
        }
        return ans;
    }
}
```