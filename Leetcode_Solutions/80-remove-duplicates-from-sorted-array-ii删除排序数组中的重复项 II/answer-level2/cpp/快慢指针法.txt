### 解题思路
p指针对应慢指针,[0,p]数组中保持着题目要求的，最多为2重复的数组，cur永远大于p
思路1:nums[p] != nums[p-1]时，那么无论i+1指向什么值都应该替换掉nums[p+1]
思路2:nums[p] == nums[p-1] 且num[i] != nums[p]时，p指针也要递增，否则p指针保持不变


### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int p = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(p == 0 || nums[p] != nums[p-1])
            {
                nums[p+1] = nums[i];
                p = p +1;
            }
            else
            {
                if(nums[p] != nums[i])
                {
                    nums[p+1] = nums[i];
                    p = p + 1;
                }
            }
        }
        return p+1;
    }
};
```