### 解题思路
这题和26.删除排序数组中的重复项 简单 C++的思路很相似，不同的地方在于判断条件和"新数组下标"而已。快慢指针，定义两个指针i和newIndex，前者用于遍历数组，后者用于“新数组”插入元素（newIndex为“新数组”指针，所谓“新数组”其实只是原有数组，其指针移动比遍历数组指针i移动慢，不影响i遍历，并且能作为“新数组”长度返回）。当遍历数组过程中，遇到不等于移除目标值val的数组元素，则在“新数组”中插入，遍历完整个数组即可，最终返回newIndex为长度。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int newIndex = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[newIndex] = nums[i];
                newIndex++;
            }
        }
        return newIndex;
        
    }
};  


```