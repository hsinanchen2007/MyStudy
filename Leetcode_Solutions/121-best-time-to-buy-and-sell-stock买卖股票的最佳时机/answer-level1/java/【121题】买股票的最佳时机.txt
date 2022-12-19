**方法一：暴力法**
```
class Solution {
    /**
    * 思路：
    * 由题知卖出时机一定在买入之后。
    * (1) 第一层循环遍历买入的时机，第二层循环遍历卖出的时机。
    * (2) 记录卖出时利润的最大值。
    */
    public int maxProfit(int[] prices) {
        int cur = 0;
        for (int i = 0; i < prices.length - 1; i++){
            for (int j = i + 1; j < prices.length; j++){
                cur = Math.max(cur, prices[j] - prices[i]);
            }
        }
        return cur;
    }
}
```

**方法二：一次遍历**
```
class Solution {
    /**
    * 思路：
    * 从第一天开始记录为买入时机，初始化卖出时利润为0，之后遍历股票行情。
    * 如果股票当天行情比记录的买入时机价格低或者一样，则记录当天为买入时机；
    * 如果股票当天行情比记录的买入时机价格高，则记录当前利润和记录利润的最大值。
    */
    public int maxProfit(int[] prices) {
        int cur = 0;
        int left = 0;
        for (int i = 1; i < prices.length; i++){
            if(prices[i] <= prices[left]){
                left = i;
            }else {
                cur = Math.max(prices[i] - prices[left], cur);
            }
        }
        return cur;
    }
}
```
