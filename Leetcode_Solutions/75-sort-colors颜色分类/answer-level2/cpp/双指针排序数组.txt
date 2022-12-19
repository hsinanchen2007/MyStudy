### 解题思路
题意需要一次遍历排序，想到类似的3个while循环排序数组的样式
首尾分别记录已序的0与2的个数
同时考虑到双指针都遇到1的情况，需分别记录下一次0之前遇到的1的个数 以及下一次2之后的1的个数，用于交换元素

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return;
        }

        int sz = nums.size();
        int start = 0, end = sz - 1;
        int arr[3] = {0};   // 记录已排好序的0，2的数量
        int oneBefore = 0;  // 记录当前0值之前出现的1的情况
        int oneAfter = 0;   // 记录当前2值之后出现的1的情况
        while (start <= end) {
            while (start <= end && nums[start] == 0) {
                if (oneBefore != 0) {
                    swap(nums[start], nums[arr[0]]);
                }
                ++arr[0];
                ++start;
            }
            if (start > end) {
                break;
            }
            
            while (start <= end && nums[end] == 2) {
                if (oneAfter != 0) {
                    swap(nums[end], nums[sz - 1 - arr[2]]);
                }
                ++arr[2];
                --end;
            }

            if (end < start) {
                break;
            }

            if (nums[start] == 2 && nums[end] == 0) {
                swap(nums[start], nums[end]);
            } else if (nums[start] == 1 && nums[end] == 0) {
                swap(nums[start], nums[end]);
                ++oneAfter;
            } else if (nums[start] == 2 && nums[end] == 1) {
                ++oneBefore;
                swap(nums[start], nums[end]);
            } else {
                // 1 1的情况，记录下来
                ++oneBefore;
                ++oneAfter;
                ++start;
                --end;
            }
        }
    }
};
```