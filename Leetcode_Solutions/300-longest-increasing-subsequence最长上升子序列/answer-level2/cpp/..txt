### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
   if(nums.size()==0)return 0;
   if(nums.size()==1)return 1;
   int res=0;
   vector<int>dp(nums.size(),1);
   for(int i=0;i<nums.size();i++)
   {
       for(int j=0;j<i;j++)
       {
           if(nums[i]>nums[j])
           dp[i]=max(dp[i],dp[j]+1);
       }
       res=max(res,dp[i]);
   } 
   return res;
    }
};
```