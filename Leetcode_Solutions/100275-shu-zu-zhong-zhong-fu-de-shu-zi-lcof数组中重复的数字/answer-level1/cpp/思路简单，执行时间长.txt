### 解题思路
将数据排序，然后找出有序数组中的重复数字。
内存消耗较小，但执行时间较长

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
         return 0;
    }
   
};
```