### 解题思路
此处撰写解题思路

可以无限次交易，即可以认为 k vs k-1没有区别， 即没有K这个状态，所以只用二维数组就可以了

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
            if (prices.size()<=1)
                return 0;

            const int kInfinity = -65534;
            const int count = prices.size();
            // const int k = 2;
            // const int max_op_count = k + 1;


            //constexpr int count = prices.size();
            int** dp = new int*[count];

            for (int i=0; i< count; ++i) {
                dp[i] = new int[2];
            }

            for (int i = 0; i < prices.size(); ++i) {

                    if (i - 1 < 0) {
                        dp[i][0] = max(0, kInfinity + prices[i]);
                        dp[i][1] = max(kInfinity, 0 - prices[i]);
                        continue;
                    }

                    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            }

            auto ans = dp[count - 1][0];
            delete[] dp;
            return ans;
    }
};
```