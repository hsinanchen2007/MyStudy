### 解题思路
一边遍历选择最低价格买入，同时比较所有大于最低价格所获得的利润，取最大

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0){
            return 0;
        }
        int min = prices[0];
        int max_pro = 0;
        for(int i = 0;i<prices.length;i++){
            //最低价格
            if (min > prices[i]){
                min = prices[i];
            }else if(prices[i] - min > max_pro){
                max_pro = prices[i] - min;
            }
        }
    return max_pro;
    }
}
```