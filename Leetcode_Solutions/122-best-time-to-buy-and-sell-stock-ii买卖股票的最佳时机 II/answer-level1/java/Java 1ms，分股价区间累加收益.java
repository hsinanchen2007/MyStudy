方法：阶段性的计算区间的最小值和最大值，累加这些区间的和。
具体的见代码注释：

```java
class Solution {
    public static int maxProfit(int[] prices) {
        if (prices==null || prices.length == 0) return 0;
        // minPrice和maxPrice表示日期区间内的最低股价和最高股价
        int minPrice = prices[0];
        int maxPrice = prices[0];
        // max表示最大受益
        int max = 0;
        int i = 1;
        while (i<prices.length){
            // 只要后面一天的价格比前一天低，则该区间计算完毕，更新收益
            if (prices[i]<prices[i-1]){
                // 更新收益
                max += maxPrice-minPrice;
                // 进入下一区间，将股价最小值和股价最大值重新初始化为新区间第一个数
                minPrice = maxPrice = prices[i++];

            }else{
                // 后面一天的收益比前一天大(或相等)，则更新该区间内最高股价
                maxPrice = prices[i++];
            }
        }
        // 关键！之所以要加上maxPrice-minPrice，是因为最后一个日期区间的收益可能没更新到max中
        // 比如{6,1,3,2,4,7}。第一个区间是{1,3}，收益为3-1 = 2,走到这一步的时候 max = 2
        // 第二个区间是{2,4,7},走到7的时候将maxPrice更新为7，但是下一步就跳出循环了，
        // 没有将该区间的收益7-2（5）添加到最大收益max中
        // 所以最后return的时候要返回 max+maxPrice-minPrice
        return max + maxPrice-minPrice;
    }
}
```
