```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int res = 0;
        int dp[nums.size()];
        for(int& i: dp)
            i = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = std::max(dp[i], dp[j]+1);
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
```
