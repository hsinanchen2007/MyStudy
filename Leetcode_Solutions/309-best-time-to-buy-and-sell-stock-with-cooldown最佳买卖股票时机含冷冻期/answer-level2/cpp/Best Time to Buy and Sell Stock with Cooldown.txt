### 解题思路
参考了团灭的方法

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;

        // int profit[len][2];
        // profit[0][0] = 0;   // 第一天没有持有，利润为0
        int profit_i_0 = 0;     // 前一天没有持有，利润为0
        // profit[0][1] = INT_MIN;     // 第一天就持有的利润为负无穷
        int profit_i_1 = INT_MIN;   // 前一天就持有，初始化为服务穷，因为最开始之前不可能持有
        int profit_pre_0 = 0;       // 前两天就卖出
        

        for(int i = 0; i < len; ++i){
            int temp = profit_i_0;  // 记录前一时刻没有持有的状态
            // 如果当天没有持有，有两种情况
            // 1. 前一天也没有持有
            // 2. 前一天持有，并且卖出了，利润加prices[i]
            // profit[i][0] = max(profit[i -1][0], profit[i - 1][1] + prices[i]);
            profit_i_0 = max(profit_i_0, profit_i_1 + prices[i]);
            /* 如果当天持有，那么也有两种情况
            1. 前一天就持有
            2. 当天买入的，但是前一天需要cooldown，所以前两天没有持有的利润减去当天买入的价格
            */
            // profit[i][1] = max(profit[i - 1][1], profit[i - 2][0] - prices[i]);
            profit_i_1 = max(profit_i_1, profit_pre_0 - prices[i]);
            profit_pre_0 = temp;    // 记录前两时刻没有持有的状态
        }

        return profit_i_0;
    }
};
```