### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
    if(nums.size()==0)return 0;
    if(nums.size()==1)return nums[0];
     vector<int>dp(nums.size());
     dp[0]=nums[0];
     dp[1]=max(nums[1],nums[0]);
     for(int i=2;i<nums.size();i++)
     {
         dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
     }
     return dp[nums.size()-1];

    }
};
```