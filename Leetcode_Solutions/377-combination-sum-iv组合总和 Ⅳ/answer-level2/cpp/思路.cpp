### 解题思路
背包问题 需要总结一下，另外可能会越界

### 代码

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      vector<int> dp(target + 1, 0);
      sort(nums.begin(), nums.end());
      dp[0] = 1;
      for(int i = 1; i <= target; i++){
        for(int j = 0; j < nums.size(); j++){
          if(nums[j] <= i)
            dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]];
          else
            break;
        }
      }
      return dp[target];
    }
};
```