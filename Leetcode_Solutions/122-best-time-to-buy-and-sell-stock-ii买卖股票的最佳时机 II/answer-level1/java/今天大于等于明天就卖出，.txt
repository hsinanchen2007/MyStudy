### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
       int gain=0;
		int buyPrice =Integer.MAX_VALUE;
		for(int i=0;i<prices.length-1;i++) {
			if(prices[i]<buyPrice) {//今天小于buyPrice
				buyPrice = prices[i];
			}else {//今天大于buyPrice且今天大于明天
				if(prices[i]>=prices[i+1]) {
					gain = gain+prices[i]-buyPrice;
					buyPrice = Integer.MAX_VALUE;
				}
			}
			//对于最后一天的判断
			if(i==prices.length-2&&prices[i+1]>prices[i]) {
				return gain+prices[i+1]-buyPrice;
			}
		}
        return gain;
    }
}
```