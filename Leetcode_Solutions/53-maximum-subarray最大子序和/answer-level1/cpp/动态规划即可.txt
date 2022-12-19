### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        const int a=nums.size();
        int dp[a];
        dp[0]=nums[0];
        for(int i=1;i<a;i++)
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
        int max=0;
        for(int i=1;i<a;i++)
            if(dp[max]<dp[i])max=i;
        return dp[max];
    }
};
```