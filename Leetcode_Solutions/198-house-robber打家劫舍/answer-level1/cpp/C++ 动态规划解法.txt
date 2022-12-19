### 解题思路
将问题分为打劫当前房间 和 不打劫当前房间 ，取最大值即可

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        std::vector<int>  dp(nums.size(), 0);
        dp[0] =  nums[0];//dp 表示从0到i个房间中最大可能的金额
        dp[1] = std::max(nums[0], nums[1]);
        for(int i =  2; i< nums.size();  i++)
        {
            int temp =  nums[i] + dp[i-2];//打劫第i个房间
            dp[i] = std::max(temp, dp[i-1]);//打劫，或者不打劫i个房间的最大值
        }
        return dp[dp.size() -1];
    }
};
```