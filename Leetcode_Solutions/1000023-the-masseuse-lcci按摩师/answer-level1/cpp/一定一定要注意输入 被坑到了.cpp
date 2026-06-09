### 解题思路
俺觉得解题思路倒是无可厚非 主要是这个整体规划一定要考虑全面丶 吃一堑长一智 亏我傻乎乎地不知道[]是怎么回事

### 代码

```cpp
class Solution {
public:
    int mmax(int a,int b)
    {
        if(a>=b)
            return a;
        return b;
    }
    int massage(vector<int>& nums) {

        if(nums.size()<1)
        return 0;
        if(nums.size()==1)
        return nums[0];
        int dp0=0;
        int dp1=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int tdp0=mmax(dp0,dp1);
            int tdp1=dp0+nums[i];
            dp0=tdp0;
            dp1=tdp1;
        }
        return mmax(dp1,dp0);
    }
};
```