### 解题思路
将股票价格在坐标轴上画出来，找出递增的片段，将每个递增片段的差加起来就是最大值

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if(len <= 1) return 0;
        int last = prices[0], delta = 0;
        for(int i=1; i<len; i++){
            if(prices[i]>=last){
                delta += prices[i] - last;
            }
            last = prices[i];
        }
        return delta;
    }
}
```