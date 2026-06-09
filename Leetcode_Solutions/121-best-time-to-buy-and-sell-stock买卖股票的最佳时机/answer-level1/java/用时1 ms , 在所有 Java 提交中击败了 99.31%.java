### 解题思路
定义一个永远指向最小的指针和一个永远保留最大差的变量，然后遍历数组，找到最大的差

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int sum = 0,min = 0;
        for(int i = 1;i < prices.length;i++) {
            if(prices[i] > prices[min])
                sum = Math.max(prices[i] - prices[min], sum);
            else 
                min = i;
        }
        return sum;
        
    }
}
```