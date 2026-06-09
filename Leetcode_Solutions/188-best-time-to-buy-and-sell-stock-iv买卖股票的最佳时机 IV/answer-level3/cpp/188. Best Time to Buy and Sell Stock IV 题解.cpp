### 解题思路
    参考了参考通用算法的算法

### 代码

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        // 如果输入数组长度为空或者交易次数为0时，返回0
        if(len == 0 || k == 0) return 0;  // 数组为空返回0
        
        // 当交易次数大于等于`len/2`相当于不限次数交易，这里相当与 Best Time to Buy and Sell Stock II
        if(k >= len/2){
            return greedy(prices);
        }

        // 第一个索引对应天数
        // 第二个索引对应交易次数
        // 第三个索引对应是否持有股票， 0代表没有持有， 1代表持有
        int dp[len][k + 1][2];


        for(int i = 0; i < len; ++i){
            for(int j = k; j >= 1; --j){
                // 第一天
                if(i - 1 == -1){
                    // 第一天没有持有, 两种可能
                    // 1. 因为一直就没有持有，所以收益为0
                    // 2. 收益为原来的基础上卖出当天的
                    dp[i][j][0] = max(0, INT_MIN + prices[i]);
                    // 第一天就持有, 两种可能
                    // 1. 前一天就持有（实际上并没有），所以收益设为一个尽可能小的值`INT_MIN`
                    // 2. 前一天没有没有持有，今天买入，所以收益为`0 - prices[i]`
                    dp[i][j][1] = max(INT_MIN, -prices[i]);
                    continue;
                }
                // 第i天，最多交易j次的情况下，如果没有持有，那么有两种可能
                // 1. 前一天也没有持有 `dp[i-1][j][0]`
                // 2. 前一天持有，到今天卖出，那么收益应该昨天的加`prices[i]` , 所以收益为`dp[i - 1][j][1] + prices[i]`
                dp[i][j][0] = max(dp[i-1][j][0], dp[i - 1][j][1] + prices[i]);

                // 第i天，最多交易j次的情况下，如果持有，那么有两种可能
                // 1. 原来就持有，收益与前一天一样`dp[i - 1][j][1]`
                // 2. 原来没与持有，当天买入（消耗一次交易次数），收益为前一天的的收益减当天买入的费用`dp[i - 1][j - 1][0] - prices[i]`,其中，这里的`j-1`是因为当天买入消耗了一次交易数
                if(j == 1){
                    // 这里j的取值范围设为`1~k`,当`j = 1`时，如果当天买入，前一天的交易次数最大为0,也就说明前一天收益为0,总收益为`0-prices[i]`
                    dp[i][j][1] = max(dp[i - 1][j][1], -prices[i]);
                }
                else{
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
        return dp[len - 1][k][0];
    }
    int greedy(vector<int>& prices) {
        int len = prices.size();
        int sum = 0;

        if(len == 0){
            return 0;
        }
        
        for(int i = 1; i < len; ++i){
            int temp = prices[i] - prices[i - 1];
            if(temp > 0){
                sum += temp;
            }
        }

        return sum;
    }
};
```