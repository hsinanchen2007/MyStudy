### 解题思路
暴力法找最大值

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        for (int i = 0; i < prices.length; i++){
            for(int j = i+1; j < prices.length; j++){
                if (prices[j]-prices[i] > max){
                    max = prices[j] - prices[i];
                }
            }
        }
        return max;
        



    }
}
```