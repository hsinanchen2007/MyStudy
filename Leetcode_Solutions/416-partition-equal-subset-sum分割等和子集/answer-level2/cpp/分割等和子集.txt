### 解题思路
记dp[i][j]为在区间[0,i]中,nums是否存在若干个数字，使得他们的和为j
那么对dp[i][j]
若nums[i] == j,即只放入nums[i]即能满足,故dp[i][j] = true;
若nums[i] > j,即nums[i]必然不能放入集合中,dp[i][j] = dp[i-1][j],
若nums[j] < j,那么nums[i]有可能可以放入集合中,
若dp[i-1][j-nums[i]]为true，那么必然能放入，dp[i][j]为true,
若dp[i-1][j]为true,那么不需要放入nums[i]，dp[i][j]为true,
综上取dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]

### 代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,0));
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for(int i = 1;i < nums.size();++i){
            if(nums[i] > target)return false;
            if(nums[i] == target) return true;
            for(int j = 1;j <= target;++j){
                if(nums[i] == j) 
                    dp[i][j] = true;
                else if(nums[i] < j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()-1][target];
    }
};
```