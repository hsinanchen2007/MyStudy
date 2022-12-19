1.sort
2.DP
3.求max
```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(nums.size(), {0,0});
        
        int maxLength = 1;
        dp[0] = {1, nums[0]};
        for (int i = 1; i < dp.size(); ++i) {
            if (nums[i] == dp[i - 1].second + 1 || nums[i] == dp[i - 1].second) {
                int length = dp[i - 1].first + (nums[i] == (dp[i - 1].second + 1) ? 1 : 0);
                int lastData = nums[i] == (dp[i - 1].second + 1) ? nums[i] : dp[i - 1].second;
                dp[i] = {length,lastData};
            } else {
                int length = 1;
                int lastData = nums[i];
                dp[i] = {length,lastData}; 
            }
            maxLength = max(maxLength, dp[i].first);
        }
                                                                       
        return maxLength;
    }
};
```
