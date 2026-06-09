### 解题思路
dp[n] = max(dp[n-1], dp[n-2] + num)，要么n-1家钱多，要么n-2家和这一家相加起来钱多。

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0], nums[1]);
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); ++i)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[nums.size()];
    }
};
```