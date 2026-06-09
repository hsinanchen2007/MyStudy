### 解题思路
我们用dp[i][j]表示直到第i个数，和为j的情况的个数，那么对于第i+1个数，和为j+nums[i]的以及和为j-nums[i]也为dp[i][j]

### 代码

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int,int>> dp(nums.size()+1);
        dp[0] = {{0,1}};
        for(int i = 1;i <= nums.size();++i){
            for(auto& m:dp[i-1]){
                int sum = m.first,count = m.second;
                dp[i][sum+nums[i-1]] += count;
                dp[i][sum-nums[i-1]] += count;
            }
        }
        return dp[nums.size()][S];
    }
};
```