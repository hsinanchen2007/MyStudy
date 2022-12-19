### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0){
            return 0;
        }
        int curSum = 0;
        int get = prices[0];
        for(int i = 1; i < prices.length; i++){
            curSum = Math.max(curSum, prices[i]-get);
            get = Math.min(get, prices[i]);
           
        }
        return curSum;
    }
}
```