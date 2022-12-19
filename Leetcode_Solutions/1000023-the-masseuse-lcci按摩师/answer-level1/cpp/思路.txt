### 解题思路
和打家结社差不多，比较容易想到的dp，自己多写就找到规律

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
      if(nums.size() == 0) return 0;
      if(nums.size() == 1) return nums[0];

      vector<int> dp(nums.size(), 0);
      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);

      for(int i = 2; i < nums.size(); i++){
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
      }

      return dp[nums.size() - 1];
    }
};
```