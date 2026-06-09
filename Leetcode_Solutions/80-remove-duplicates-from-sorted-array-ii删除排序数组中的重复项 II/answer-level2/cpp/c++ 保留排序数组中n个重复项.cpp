```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int repeat=0;
        if(nums.size()<3)
        return nums.size();
        int index=0;
        int prevalue=nums[0];
        for(int i=0;i<nums.size();i++)
            if(nums[i]==prevalue)
            {
                ++repeat;
                if(repeat<3)
                {
                    if (index != i)
                        nums[index] = nums[i]; // 优化，避免不必要的赋值。
                    index++; // 必须要递增的
                }
            }
            else
            {
                if (index != i)
                    nums[index] = nums[i]; // 优化，避免不必要的赋值。
                index++; // 必须要递增的
               prevalue=nums[i];
               repeat=1;
            }
        return index;
    }
};
```
