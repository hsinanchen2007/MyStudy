### 解题思路
计算两两元素间的利润
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxpro = 0;
        for(int i=0; i<prices.length-1;i++)
            for(int j=i+1;j<prices.length;j++){
                int profit = prices[j] - prices[i];
                if(profit>maxpro)
                    maxpro = profit;
            }
        return maxpro;
    }
}
```