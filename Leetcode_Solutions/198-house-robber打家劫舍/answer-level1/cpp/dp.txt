状态转移方程：`dp[i]=max(dp[i],dp[j]+nums[i])(i-j>1)`;最后的结果必定是`dp[-1]和dp[-2]`之间的最大值
```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>dp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            dp[i]=nums[i];
            for(int j=0;j<i-1;j++){
                dp[i]=max(dp[i],dp[j]+nums[i]);
            }
        }
        return nums.size()>1?max(dp[nums.size()-2],dp[nums.size()-1]):dp[nums.size()-1];
    }
};
```
