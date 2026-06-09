### 解题思路
将该问题看成一个动态规划问题，首先，当`nums`为空时，返回0。当`nums`长度为1时，因为只有一种情况，所以直接返回`nums[0]`, 当`nums`长度为2时，返回最大的。
当`nums`长度大于2时，我们将该问题看成动态规划问题。对于`nums[i]`有两种情况，
1. 抢--那么收益为抢前前房子的收益加上该房子的收益:`dp[i-1] + nums[i]`
2. 不抢--那么收益为抢上一个房子的最大收益
3. 取两种情况的最大值

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);
        
        int dp[len + 1] = {0};
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < len; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[len - 1];
    }
};
```