### 解题思路
设置两个索引i j，然后根据题意要加入两个隐含条件
1. i必须在j左边
2. prices[i]要小于其右边的数值

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        
        int i= 0,profit = 0;
        

        for (int j = i; j < prices.length; j++) {
            if (j > i) {
                if (prices[j] >= prices[i]) {
                    profit = profit > (prices[j] - prices[i]) ? profit : (prices[j] - prices[i]);
                } else {
                    i = j;
                }
            }
        }
        return profit;
    }
}
```