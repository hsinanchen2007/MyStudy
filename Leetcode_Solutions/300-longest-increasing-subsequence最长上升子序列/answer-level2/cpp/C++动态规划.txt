```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] >= dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        int max = 1;
        for (auto v : dp) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }
};
```