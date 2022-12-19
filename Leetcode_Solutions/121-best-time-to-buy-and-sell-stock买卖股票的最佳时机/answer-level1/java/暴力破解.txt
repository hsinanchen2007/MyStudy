```
class Solution {
    public int maxProfit(int[] prices) {
       int result = Integer.MIN_VALUE;
       for(int i =0; i< prices.length; ++i){
           for(int j = i+1; j < prices.length; ++j){
               int a = prices[j] - prices[i];
               if(result < a && a >= 0){
                   result = a;
               }
           }
       }
       if(result == Integer.MIN_VALUE){
           return 0;
       }
       return result;
    }
}
```
