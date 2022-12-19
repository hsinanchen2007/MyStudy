注释：
premax记录此前最大数的下标；
maynot用于标记nums[premax]虽然是此前最大的数，但不满足大于2倍特性，当且仅当新的最大数>=2*nums[premax]时恢复为false；
时间复杂度O(n)，空间O(1);
```
class Solution {
public:
    int dominantIndex(vector<int>& nums) 
    {
        int n=nums.size();
        int premax=0;
        bool maynot=false;
        for(int i=1;i<n;++i)
        {
            if(nums[premax]<nums[i])
            {
                if (nums[i]>=2*nums[premax])                    
                    maynot=false;
                else
                    maynot=true;
                premax=i;
            }
            else
                if (2*nums[i]>nums[premax])
                    maynot=true;
        }
        if(maynot)
        return -1;
        else
        return premax;
    }
};
```
