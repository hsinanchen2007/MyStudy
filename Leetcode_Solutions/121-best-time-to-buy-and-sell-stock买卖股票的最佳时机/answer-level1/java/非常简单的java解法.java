


### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0)//考虑特殊情况。
            return 0;
    	int max = 0,buytemp = prices[0],soldtemp = prices[0];
    	for(int i = 0;i<prices.length;i++) {
    		if(prices[i]<buytemp) {//当股票跌的时候重新买
    			buytemp = prices[i];
    			soldtemp = prices[i];
    		}else if(soldtemp<prices[i]) {//股票涨的时候卖
                soldtemp = prices[i];
    			max = Math.max(max, soldtemp - buytemp);
    		}
    			
    	}
    	return max;
    }
}
```