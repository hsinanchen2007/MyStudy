### 解题思路
dp

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        vector<int> dp=nums;
        int ans=0;
        for(int i=2;i<nums.size();i++)
        {
            for(int j=0;j<i-1;j++)
            {
                dp[i]=max(dp[i],dp[j]+nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
```