### 解题思路

通过本道题目，算是理解了动态规划从内到外，或者从下到上的问题解决思路。


1、初始化条件
2、处理边界情况，因为想这种情况只能处理size > 2的问题，而小于的情况就属于需要特殊处理的逻辑；
3、核心的动态规划方程：dp[j] = max(dp[j-2] + nums[j], dp[j-1]);


### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int size = nums.size();
        if(size == 1) return nums[0];
        if(size == 2) return std::max(nums[0], nums[1]);
        
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for(int j = 2; j < size; j++) {
            dp[j] = std::max(dp[j - 2] + nums[j], dp[j - 1]);
        }

        return dp[size - 1];
    }
};
```