### 解题思路

### 代码

```cpp
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size(),M=INT_MIN;
        vector<int> dp(n,0); 

        for(int i=0;i<n;i++)
        {
            if(i==0) dp[i]=nums[i];
            else dp[i]=max(nums[i],nums[i]+dp[i-1]);

            M=max(M,dp[i]);
        }

        return M;
    }
};
```