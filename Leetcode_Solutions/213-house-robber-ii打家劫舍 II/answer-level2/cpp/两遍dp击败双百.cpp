### 解题思路
因为首尾相连，所以ans = max(ans{nums(1, n - 1)}, ans{nums(2, n)})。

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int ans = dp[1];
        for(int i = 2 ; i < nums.size() - 1 ; ++i)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        ans = dp[nums.size() - 2];
        fill(dp.begin(), dp.begin() + nums.size(), 0);
        dp.back() = nums.back();
        dp[nums.size() - 2] = max(nums.back(), nums[nums.size() - 2]);
        for(int i = nums.size() - 3 ; i >= 1 ; i--)
            dp[i] = max(dp[i + 2] + nums[i], dp[i + 1]);
        ans = max(ans, dp[1]);
        return ans;
    }
};
```