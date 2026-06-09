### 解题思路
求以每一个位置i结尾的最长升序序列长度，则最长升序序列长度一定在这些之中。
求以i位置结尾的升序序列长度dp[i];则dp[i]等于dp[j]+1(当nums[j]<nums[i]时>);j在0，i-1之间（0,i之间的最长的升序子序列长度再加一）

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        vector<int >dp(nums.size(),0);
        
        for(int i=0;i<nums.size();i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++)
            res=max(res,dp[i]);

    return res;

    }
};
```