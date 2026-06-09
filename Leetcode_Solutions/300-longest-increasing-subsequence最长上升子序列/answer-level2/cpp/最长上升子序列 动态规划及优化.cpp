```C++ []
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = nums.size();
        vector<int> dp(len, 1);
        for(int i=1; i<len; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        int max_val = INT_MIN;
        for(int i=0; i<len; i++)
            max_val = max(max_val, dp[i]);
        return max_val;

    }
};
```
