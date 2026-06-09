```
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int N = nums.size();
        // pair<int, int> 分别为最长递增长度与对应的数目
        vector<pair<int, int> > dp(N, {1, 1});
        int mx = 1;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i].first < dp[j].first + 1) {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    } else if (dp[i].first == dp[j].first + 1) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
            mx = max(mx, dp[i].first);
        }
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (dp[i].first == mx) {
                res += dp[i].second;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/26805351da14c10985debf870448dae2c19b437e1816961ce209641131c62976-image.png)
