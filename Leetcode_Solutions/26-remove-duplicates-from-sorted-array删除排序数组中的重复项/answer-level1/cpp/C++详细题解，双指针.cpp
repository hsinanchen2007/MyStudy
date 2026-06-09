## 思路
- 同时有一个慢指针和一个快指针。慢指针指向新数组，快指针遍历旧数组
- 由于数组已排序，若nums[i] ！=nums[j] 将i 的下一位赋值为nums[j]
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())  return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); ++ j)
        {
            if(nums[i] != nums[j])
            {
                ++ i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
```