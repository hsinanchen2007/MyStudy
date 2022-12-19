### 解题思路
此处撰写解题思路
我们可以画出一个折线图出来，则最低点和他右侧的最高点之差就是最大收益
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0)
            return 0;
        int temp = prices[0];
        int max = 0;
        for(int i = 1; i < prices.length; i++){
            if(prices[i] > temp){
                max = Math.max(prices[i]-temp,max);
            }else{
                temp = prices[i];
            }
        }
        return max;
        
    }
}
```