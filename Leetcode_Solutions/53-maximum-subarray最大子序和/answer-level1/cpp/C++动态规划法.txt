### 解题思路


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int numsize=nums.size();
        if(numsize==0) return 0;
        vector<int> dp(numsize,0);
        dp[0]=nums[0];
        int res=dp[0];
        for(int i=1;i<numsize;++i)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            //if(dp[i]<0) dp[i]=0;
            res=max(res,dp[i]);
        }
        return res;
        
    }
};
```