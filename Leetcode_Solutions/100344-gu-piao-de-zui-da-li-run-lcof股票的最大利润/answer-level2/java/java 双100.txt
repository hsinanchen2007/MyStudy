### 解题思路
此处撰写解题思路
设置 一个 变量来存储 最小值， 便利整个数组  当前数 - 最小值 来找 最大值   复杂度O（n）
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
      int min = Integer.MAX_VALUE;
      int max = 0;
      for( int i =0; i < prices.length; i++){
           if(prices[i] <= min){
               min = prices[i];
           } 
           max = Math.max(prices[i] - min, max);




      }
      return max;
    }
}
```