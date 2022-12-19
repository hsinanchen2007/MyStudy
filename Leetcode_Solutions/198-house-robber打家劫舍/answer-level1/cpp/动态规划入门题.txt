其实这道题和按摩师一样。

```cpp
dp[i] = max(dp[i-1], dp[i-2] + prices[i]);
当前打劫，就不能把相邻的值传送过来。
当前不打劫，就可以把相邻的值传送过来。
```

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0; 
        int max = nums[0];
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); ++i){
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i-1]);
            max = std::max(dp[i], max);
        }
        return max;
    }
};
```
