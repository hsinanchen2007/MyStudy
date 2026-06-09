### 解题思路
用时：4ms 击败90.56%
内存消耗：8.5MB， 击败99.43%

根据目标值和第一个元素的关系，确定从前还是从后开始比较
循环的终止条件: 要么找到了某元素和目标值相等，要么某元素值和第一个元素值的关系被破坏

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) {
            return -1;
        }
        if(size == 1) {
            return nums[0] == target ? 0:-1;
        }
        if(nums[0] < nums[size-1]) {
            // 没有旋转
            int i;
            for(i=0; i < size; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            if(i == size) {
                return -1;
            }
        } else {
            // 已经旋转过
            if (target < nums[0]) {
                // 目标值小于第一个元素，需要从后面开始找
                for (int i = size - 1; nums[i] < nums[0] ; --i) {
                    if(nums[i] == target) {
                        return i;
                    }
                }
                return -1;
            } else {
                // 目标值大于等于第一个元素，从前面往后找
                for (int i = 0; nums[i] >= nums[0]; ++i) {
                    if(nums[i] == target) {
                        return i;
                    }
                }
                return -1;
            }
        }
        return -1;
    }
};
```