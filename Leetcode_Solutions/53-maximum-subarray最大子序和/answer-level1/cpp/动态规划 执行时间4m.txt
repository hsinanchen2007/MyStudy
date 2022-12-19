### 解题思路
dp[i]的值是以nums[i]结尾的最大子序和
显然
如果dp[i]>=0，那么dp[i+1]=dp[i]+nums[i+1]。
如果dp[i]<0,dp[i+1]=nums[i+1]。
例如[-2,1]，dp[0]=-2，显然-2+1<1,所以dp[1]=1.
例子：
[3,-2,4,-2,-5,4,2]
dp[0]=3; result=3
dp[1]=1; result=3
dp[2]=5; result=5
dp[3]=3; result=5
dp[4]=-2;result=5
dp[5]=4; result=5
dp[6]=6; result=6
输出 6
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0); // dp[i]是以nums[i]结尾的最大子序和
        dp[0]=nums[0];
        int result=dp[0];
        for(int i=0;i<n-1;i++)
        {
            if(dp[i]>=0)
            {
                dp[i+1]=dp[i]+nums[i+1];
            }
            else 
                dp[i+1]=nums[i+1];
            result=max(dp[i+1],result);
        }                                   
        return result;
    }
};
```