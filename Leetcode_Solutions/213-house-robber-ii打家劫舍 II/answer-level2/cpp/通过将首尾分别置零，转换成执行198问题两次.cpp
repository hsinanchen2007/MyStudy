### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector <int> dp(nums.size(),0);
        if (nums.size()==0)
            return 0;
        if (nums.size()==1)
            return nums[0];
        if (nums.size()==2)
            return max(nums[0],nums[1]);
        //不偷0号
        int n0=nums[0],mx;
        nums[0]=0;
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(auto it=nums.begin()+2;it<nums.end();it++){
            int i=it-nums.begin();
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        mx=dp.back();
        //偷0号
        nums[0]=n0;
        nums[nums.size()-1]=0;
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(auto it=nums.begin()+2;it<nums.end();it++){
            int i=it-nums.begin();
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        mx=max(mx,dp.back());
        return mx;
    }
};
```