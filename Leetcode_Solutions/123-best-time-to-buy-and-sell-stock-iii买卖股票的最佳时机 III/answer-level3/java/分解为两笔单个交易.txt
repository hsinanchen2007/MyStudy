### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==2){
        if(prices[prices.length-1]>prices[prices.length-2])
        return prices[prices.length-1]-prices[prices.length-2];
        else return 0;
        }
      int minprice = Integer.MAX_VALUE,max=0;
      int minprice1=Integer.MAX_VALUE;
      int maxprofit =0,maxprofit1=0,number=0;
        for(int j=1;j<prices.length-1;j++){
            minprice=Integer.MAX_VALUE;
            minprice1=Integer.MAX_VALUE;
            maxprofit=0;maxprofit1=0;
        for (int i = 0; i <=j; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
                
        }
        for (int i = j; i <prices.length; i++) {
            if (prices[i] < minprice1)
                minprice1 = prices[i];
            else if (prices[i] - minprice1 > maxprofit1)
                maxprofit1 = prices[i] - minprice1;     
        }
        number=maxprofit+maxprofit1;
        if(number>max)
        max=number;
    }
        return max;
    }
}
```