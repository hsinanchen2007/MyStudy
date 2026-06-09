基本思想：
记dpmax[i]和dpmin[i]分别记录以i号元素结尾的最大子数组乘积和最小子数组乘积。
如何更新dpmax和dpmin？
莽就完事了。dpmax[i]=max{nums[i],nums[i]*dpmax[i-1],nums[i]*dpmin[i-1]}，类似可更新dpmin[i].
进一步地，为了降低空间复杂度，使用premax，premin记录i-1时的最值。
时间复杂度 O(n)，空间复杂度O(1).
```
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int mmax,premax,nowmax;
        int premin,nowmin;
        int n=nums.size();
        mmax=premax=premin=nums[0];
        for(int i=1;i<n;++i)
        {
            nowmax=max(nums[i],max(nums[i]*premax,nums[i]*premin));
            nowmin=min(nums[i],min(nums[i]*premax,nums[i]*premin));
            mmax=max(mmax,nowmax);
            premax=nowmax;
            premin=nowmin;
        }
        return mmax;
    }
};
```
