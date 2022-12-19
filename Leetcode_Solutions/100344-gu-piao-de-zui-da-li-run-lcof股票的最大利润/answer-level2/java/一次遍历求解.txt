### 解题思路
每次判断当前是否为高价，是则替换max和priceHigh。
同时判断是否低于最低价，在判断完max后更新priceLow。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        int priceLow = prices[0];
        int priceHigh = prices[0];
        int sub = 0;
        int max = 0;
        for(int price : prices){
            sub = price - priceLow;
            if(sub > max){
                max = sub;
                priceHigh = price;
            }
            if(price < priceLow) priceLow = price;
        }
        return max;
    }
}
```