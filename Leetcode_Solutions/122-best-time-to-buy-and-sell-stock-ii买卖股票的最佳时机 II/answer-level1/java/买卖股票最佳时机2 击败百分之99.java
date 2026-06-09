
我这个为啥这么短就通过了
```
class Solution {
    // 5  6  1   7
    public int maxProfit(int[] prices) {
        int x =0 ;
        for(int i=0;i<prices.length-1;i++){
            if(prices[i+1]>prices[i])
            x+=prices[i+1]-prices[i];
        }
        return x;
    }
}
```
