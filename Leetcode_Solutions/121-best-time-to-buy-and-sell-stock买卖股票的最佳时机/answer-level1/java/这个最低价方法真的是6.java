### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution {
    public int maxProfit(int prices[]) {
        if(prices.length==0){
            return 0;
        }
        int maxP = 0;
        int low = prices[0];
        for(int current : prices) {
            //如果当天价比上次的最低价低，那么就替换为新的最低价，否则还用上次的最低价。
            if(current < low) {
                low = current;
            }
            //只有当新的差价比旧的最大值大的时候才替换。
            maxP = Math.max(maxP, current - low);
        }
        return maxP;
    }

}
```