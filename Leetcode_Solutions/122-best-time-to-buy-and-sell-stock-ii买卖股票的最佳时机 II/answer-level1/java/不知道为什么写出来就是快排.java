### 解题思路
每次取一个最大和最小的区间，再把各区间的收益相加。

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int i = prices.length - 1;
        int max = 0;
        while (i > 0){
            while(i > 0 && prices[i-1] >= prices[i]){i--;}
            int high = prices[i];
            while(i > 0 && prices[i-1] <= prices[i]){i--;}
            int low = prices[i];
            max += high - low;
        }
        return max;
    }
}
```