### 解题思路
贪心算法，总是找到后面比自己大的元素，一旦遇到比自己小的，就停止。同时让这个比自己小的元素充当买入价。
请看下方代码和注释

### 代码

```java
class Solution {
    /**
     * 解决思路：- 贪心算法
     * 股票的价格的计算是买入价格和后续最大卖出价格的差值
     * 举例如下：
     * [7,1,5,3,6,4]
     * 从i=0开始遍历，第一个是7，继续遍历，后边是1，比7小停止遍历，利润是0
     * 然后i=1，买入价是1，后边第一个是5，尝试买入；继续+i，后边是3，不行，停止，取利润为5-1=4
     * 这个时候下标i已经到了2（是5）
     * 从i=3开始，买入价是3，第一个是6，买入做差得到3，此时总利润为4+3
     * 这个时候最后一个是4，无法买入，计算停止
     *
     * @param prices
     * @return
     */
    public int maxProfit(int[] prices) {
        int index = 0;
        int max_profit = 0;
        // 从0开始遍历，到最后一个元素终止
        while(index < prices.length-1){
            // 当前价格（作为比较参数）
            int current_price = prices[index];
            // 定义买入价格
            int buy_price = current_price;
            // 从当前价格的下一个脚标继续往下走
            // 遇到比自己大的就记录下来，直到遇到一个比前一个小的
            while(++index < prices.length){
                if(prices[index] > current_price){
                    // 遇到的比当前大的就记录下来
                    current_price = prices[index];
                }else{
                    // 只要遇到一个下降的趋势就停止
                    break;
                }
            }
            // 总利润就是被记录下来的最大的价格减去打头的价格
            int tmp_profit = current_price - buy_price;
            // 记录总利润
            if(tmp_profit > 0){
                max_profit += tmp_profit;
            }
        }
        return max_profit;
    }
}
```