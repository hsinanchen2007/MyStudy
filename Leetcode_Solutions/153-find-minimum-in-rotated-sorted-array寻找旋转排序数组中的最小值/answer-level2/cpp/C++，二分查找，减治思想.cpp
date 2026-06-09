### 解题思路
这题只需要注意一个点：中值和右边界比较，就可以找到最小值的存在区间；而中值和左边界比较则不行。

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, mid, right = nums.size() - 1;

        while(left < right) {
            mid = left + (right - left) / 2;

            // nums[mid] < nums[right]，即 [mid, right] 有序，[left, mid] 可能有序可能无序
            // 此时最小值一定在 [left, mid] 区间（mid自己也可能是最小数）
            // eg: [6, 7, 1, 2, 3, 4, 5] or [1, 2, 3, 4, 5, 6, 7]
            if(nums[mid] < nums[right]) right = mid;

            // nums[mid] > nums[right]，即 [left, mid] 有序，[mid, right] 一定无序，[mid + 1, right] 可能有序可能无序
            // 此时最小值一定在 [mid + 1, right] 区间（mid自己就比右边界大了，一定不是最小值）
            // eg: [4, 5, 6, 7, 1, 2, 3]
            else left = mid + 1;
        }

        // 因为不存在重复元素，所以非空数组一定存在最小值
        return nums[left];
    }
};
```