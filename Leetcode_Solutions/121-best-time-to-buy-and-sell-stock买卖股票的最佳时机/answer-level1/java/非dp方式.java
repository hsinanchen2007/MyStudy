没想到怎么dp实现，不过非dp的效率也不错。
```
class Solution {
    /**
      就题目来说，如果前x个元素中，已知min和max，那么：
      1. 如果prices[x+1]<min, 那么原先的max就失效了，max = prices[x+1];
      2. 如果prices[x+1]>max, 那么只需要更新max即可;
      每遍历一个元素，执行以上判断，如果新的差比较大，就记下来。遍历完成后的差就是所求。
    */
    public int maxProfit(int[] prices) {
        if(prices==null||prices.length==0){
            return 0;
        }
        int min = prices[0], max = prices[0], result = 0;
        boolean b = true;
        for(int i = 0; i < prices.length; i++){
            if(min>prices[i]){
                min = prices[i];
                b = false;
            }
            if(max<prices[i]){
                max = prices[i];
                b = true;
            }
            if(!b){
                max = prices[i];
                b = true;
            }
            if(b){
                if(result < max-min){
                    result = max-min;
                }
                b = false;
            }
        }
        return result;
    }
}
```
