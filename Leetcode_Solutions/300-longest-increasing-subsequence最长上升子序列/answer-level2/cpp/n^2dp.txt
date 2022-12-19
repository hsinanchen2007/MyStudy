### 解题思路


### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int ans = 1;
        int dp[nums.size()] = {0};
        dp[0] = 1;
        for(int i = 1 ; i < nums.size() ; ++i)
        {
            dp[i] = 1;
            for(int j = 0 ; j < i ; ++j)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```