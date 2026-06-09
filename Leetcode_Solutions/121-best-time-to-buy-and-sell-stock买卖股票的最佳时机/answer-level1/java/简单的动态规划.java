### 解题思路
 以 当前点为最高点，与之前的比，最大的差距，之前的点选择一个最小点
   f(i) = s(i) - min( 0--i) 

### 代码

```java
class Solution {
     public int maxProfit(int[] prices) {
		   if(prices.length <= 1 ) {
			   return 0;
		   }

		   int max = 0;
		   int min = 0;
		   int len = prices.length;
		   for(int i = 0 ; i < len ; i ++ ) {
			   if(i == 0) {
				   min = prices[i];
				   continue;
			   }
			   max = Math.max( max, prices[i] - min);
			   min = Math.min(min, prices[i]);
			   
		   }
		   
		   return max;
	    }
}
```