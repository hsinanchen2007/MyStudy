### 解题思路
这题我见过,算法导论上有

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
            
        vector<int> norm(prices.size());
        for (int i = 0 ; i < prices.size(); ++i)
        {
            if (i == 0)
                norm[i] = 0;
            else
                norm[i] = prices[i] - prices[i-1];
        }
        // 最大连续子数组
        vector<int> dp(norm.size()+1);
        dp[0] = norm[0];
        for (int i = 1; i <= norm.size(); ++i)
        {
            dp[i] = max(dp[i-1], dp[i-1]+norm[i-1]);
        }
        // for(int n : dp)
        //     cout<<n<<" ";
        // cout<<endl;

        return dp[dp.size()-1];
    }
};
```