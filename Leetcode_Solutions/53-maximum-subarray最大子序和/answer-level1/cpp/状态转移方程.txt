### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int dp[32768];
        if(nums.size()==1)
        {
            return nums[0];
        }
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
  dp[i]=max(nums[i],dp[i-1]+nums[i]);//状态转移方程
        }
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
if(dp[i]>dp[j])
{
    j=i;
}
        }
        return dp[j];
    }
};
```