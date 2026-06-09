### 解题思路
顺序遍历股票，每次计算最小价格，和当前价格和最小价格的差值，遍历完成后最大差值为所求。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices==null||prices.length<=1){
            return 0;
        }
        int min=prices[0];
        int maxP=0;
        for(int i=1;i<prices.length;i++){
            min=Math.min(min,prices[i]);
            maxP=Math.max(maxP,prices[i]-min);
        }
        return maxP;
    }
}
```