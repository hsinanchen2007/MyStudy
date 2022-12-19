# 思路
1. max_profit[i] 记录[0...i]中可获得的最大利润，故max_profit[n-1]即为最终所求；
2. buy_index 记录最近一次买入的位置，pre_profit和cur_profit分别记录最近一次交易和本次卖出的收益；
3. 根据动态规划思想，对于遍历到prices[i]时，仅存在两种情况：
    - 之前卖出：当前i处买入，并将上一次交易的收益置为0
    - 现在卖出：以最近一次买入及当前卖出为一次交易，并将本次交易收益置为上一次交易收益值
# 代码
```
public int maxProfit(int[] prices) {
    if (prices.length==0) {
        return 0;
    }
    int[] max_profit = new int[prices.length];
    int buy_index = 0;
    int pre_profit = 0;
    int cur_profit = Integer.MIN_VALUE;
    max_profit[0] = 0;
    for (int i = 1; i < prices.length; i++) {
        cur_profit = prices[i] - prices[buy_index];
        if (cur_profit > pre_profit) {
            // 现在卖出
            pre_profit = cur_profit;
            max_profit[i] = max_profit[buy_index] + prices[i] - prices[buy_index];
        } else {
            // 之前卖出，且现在买入
            buy_index = i;
            pre_profit = 0;
            max_profit[i] = max_profit[i - 1];
        }
    }
    return max_profit[prices.length - 1];
}
```
# 总结
一次遍历，时间复杂度O(n)，空间复杂度O(n)

Tip:可以修改通过记录最近一次买入的位置改为最近一次买入价格，并在原数组prices上修改记录当前位置最大收益，将空间复杂度降为O(1).