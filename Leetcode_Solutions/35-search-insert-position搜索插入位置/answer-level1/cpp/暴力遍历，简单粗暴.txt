### 解题思路
因为是排序数组，找到则返回位置，找不到则到返回第一个大于它的索引，否则插到最后

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
            if(nums[i]>target){
                return i;
            }
        }
        return nums.size();
    }
};
```