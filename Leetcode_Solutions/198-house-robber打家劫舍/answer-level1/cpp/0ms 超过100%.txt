class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);

        dp[0] = 0;
        if(nums.size() > 0)
            dp[1] = nums[0];

        if(nums.size() > 1)
            dp[2] = max(nums[0],nums[1]);

        for(int i = 3;i <= nums.size();++i){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }

        return dp[nums.size()];
    }
};