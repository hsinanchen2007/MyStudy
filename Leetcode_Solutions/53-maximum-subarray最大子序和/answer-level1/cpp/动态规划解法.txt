### 解题思路

最大子序，还是连续的，那问题简单了。

符合最优子结构性质：

dp[i] = max(dp[i-1] + nums[i], nums[i]);


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = std::max(dp[0]+nums[1], nums[1]);
        for(int i = 2; i < size; i++){
            dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
```