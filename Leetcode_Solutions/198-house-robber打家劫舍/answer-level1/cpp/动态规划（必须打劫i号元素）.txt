基本思想：
动态规划，维护 *必须打劫i号元素时，能获得的最大金额* dpmax 以及 *i-2号元素及以前的最大可打劫金额* mmax.
更新：
dpmax[i]=mmax+nums[i];
mmax=max(mmax,dpmax[i-1]);
返回结果 max(dpmax[n-1],dpmax[n-2])
```
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
        return 0;
        if(n==1)
        return nums[0];
        vector<int> dpmax(nums.size());//dpmax[i]:必须打劫i号元素时，能获得的最大金额
        dpmax[0]=nums[0];
        dpmax[1]=nums[1];
        int mmax=dpmax[0];//i-2号元素及以前的最大可打劫金额
        for(int i=2;i<nums.size();++i)
        {
            dpmax[i]=mmax+nums[i];
            mmax=max(mmax,dpmax[i-1]);
        }
        return max(dpmax[n-1],dpmax[n-2]);
    }
};
```
