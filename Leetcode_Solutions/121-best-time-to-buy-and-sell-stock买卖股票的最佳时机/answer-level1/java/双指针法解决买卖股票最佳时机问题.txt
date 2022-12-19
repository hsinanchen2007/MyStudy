感觉碰到这种求数组中差值、去重，双指针法比较好用
```java
class Solution {
    public int maxProfit(int[] prices) {
        // 买入时机
        int i = 0;
        int res = 0;
        for(int j = 1; j < prices.length; j++){
            //比买入时机价格高时，计算利润
            if(prices[i]< prices[j]){
              int sub =  prices[j]- prices[i];
              //更新最大利润
              res = Math.max(res, sub);
            }
            // 当遇到比之前买入价格更低时，更新买入时机
            if(prices[i] > prices[j]){
                i = j;
            }
        }
        return res;
    }
}
```
