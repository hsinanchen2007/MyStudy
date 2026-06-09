### 解题思路
此处撰写解题思路
需要照顾 k==0 的情况，即完成0笔交易（买卖均完成）之后的状态。
dp[i][0][0] = 0，因为完成0笔交易之后，手里没有股票，也没花钱
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1)
            return 0;

        const int k = 2;
        const int max_op_count = k + 1;
        const int count = prices.size();

        //constexpr int count = prices.size();
        int*** dp = new int**[count];
        
        const int kInfinity = -65534;

        for (int i=0; i< count; ++i) {
            dp[i] = new int*[max_op_count];
            for (int j=0; j< max_op_count; ++j)
                dp[i][j] = new int[2];
        }

        for (int i = 0; i < prices.size(); ++i) {
            for (int j = max_op_count - 1; j >= 1; --j) {

                if (i - 1 < 0) {
                    dp[i][j][0] = max(0, kInfinity + prices[i]);
                    dp[i][j][1] = max(kInfinity, 0 - prices[i]);
                    continue;
                }

                if (j-1==0) {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1], 0 - prices[i]);
                    continue;
                }

                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }

        auto ans = dp[prices.size() - 1][k][0];
        delete[] dp;
        return ans;
            
    }
};
```