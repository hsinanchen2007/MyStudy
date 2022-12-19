  假设存在一个数列（不考虑空或一个元素的情况）
  **a,b,c,d,e,f**
  我们用一个i指针从下标1开始，每次i运动的过程中，我们计算的就是以下标i为结束（即在第i+1天卖出）的最大利润，另用一个start指针指向以下标i结束的买入股票的时间（即包括d及之前所有元素的最小值）。

  当i运动到e处时，假设start为b，由我们定义可知，b即为e前所有元素中最小的值，分两种情况：
（1）e>=b，则start不变，以e为结尾的最大值即为e-b。
（2）e<b，则start指向e，以e为结尾的最大值即为0。
我们只需要用一个max记录遍历过程中最大值即可。
```
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0||prices.length == 1)
            return 0;
        int start = 0;
        int res = 0;
        for(int i = 1;i<prices.length;i++){
            if(prices[i]>=prices[start])
                res = Math.max(res,prices[i]-prices[start]);
            else{
                start = i;
            }
        }
        return res;
    }
}
```
