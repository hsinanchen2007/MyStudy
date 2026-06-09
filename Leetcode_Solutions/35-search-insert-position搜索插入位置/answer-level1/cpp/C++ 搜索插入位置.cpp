### 解题思路
注意到nums是一个有序数组，所以从nums头部开始查找，如果当前元素大于等于target，则说明target应该在这里找到了（当前元素等于target），或者说明需要在此处插入（当前元素大于target），因此一层循环就可以搞定。


### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        for(;i<nums.size();i++){
            if(nums[i]>=target) return i;
        }
        return i; 
    }
};
```