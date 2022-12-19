![image.png](https://pic.leetcode-cn.com/5128da6623d937b71e304b94be0b4c4b44f76172581e16fb8fed376f36856025-image.png)

```
//所有正的delta加起来即可
class Solution {
    public int maxProfit(int[] prices) {
        int ans, i;

        ans = 0;
        for(i = 1; i < prices.length; i++)
            if(prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        return ans;
    }
}
```
