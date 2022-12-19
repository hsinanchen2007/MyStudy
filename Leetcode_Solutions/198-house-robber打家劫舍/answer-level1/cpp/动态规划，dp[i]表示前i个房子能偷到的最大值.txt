### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        if(nums.size() == 1)return nums[0];
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;  //0个房子，没钱
        dp[1] = nums[0];  //前1个房子的价值
        //dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])，表示前i个房子能偷盗的最大值[0,i)
        for(int i = 2; i <= nums.size(); ++i)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];
    }
};
```