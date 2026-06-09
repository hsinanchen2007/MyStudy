状态转移方程是：
dp[i]=max(dp[i-1], dp[i-2]+nums[i])
当前的盗窃金币要么是上一个房子的，要么是上上个房子再加上盗窃当前的房子金币的和，**两者取较大值**
没什么复杂的地方
```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
```
