很明显是dp
关键点在于找到状态转移方程 dp[i] = max(dp[i-1]+nums[i],nums[i])
可以直接在原数组上直接进行修改，并用一个值来存储当前最大的数组序列和
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i =1;i<nums.size();++i){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }
        int max = dp[0];
        for(int i=1;i<nums.size();++i)
        {
            if(max<dp[i])
                max =dp[i];
        }
        return max;
    }
};
```