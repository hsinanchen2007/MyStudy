
```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                if(nums[nums[i]]==nums[i])
                    return nums[i];
                int tem=nums[nums[i]];
                nums[nums[i]]=nums[i];
                nums[i]=tem;
            }
        }
        return 0;
        
    }
};

```
