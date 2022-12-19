### 解题思路
其实我一共用了三种方法来做的：

### 代码
暴力使用时间三百多毫秒：
```java
class Solution {
    public int maxProfit(int[] prices) {
       int maxprofit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
}
```
更加的暴力，使用时间是六百多毫秒：
```
    int[] prices = {7,6,4,3,1};
		int max = 0;
		if (prices.length==0) max = 0;
		for(int i=0;i<prices.length;i++) {
			int end = prices.length-1;
			while(end>i) {
				max = Math.max(max, prices[end]-prices[i]);
				end--;
			}
		}
```
这个算法只用了1ms：
```
public int test(int[] prices) {
		int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
	}
```
还是少点运算是最好的，多点思考，最主要的还是找的一个无论当前节点在哪个地方都通用的一个方法；
