### 解题思路
例：输入的数组是：{5, 7, 7, 8, 8, 10}，目标数是 8，那么返回 {3, 4}，其中 3 是 8 第一次出现的下标位置，4 是 8 最后一次出现的下标位置。
在二分搜索里，比较难的是判断逻辑，对这道题来说，什么时候知道这个位置是不是 8 第一次以及最后出现的地方呢？
把第一次出现的地方叫下边界（lowerbound），把最后一次出现的地方叫上边界（upperbound）。

那么成为8的下边界的条件应该有两个：
1. 该数必须是8；
2. 该数的左边一个数必须不是8：
    - 8的左边有数，那么该数必须小于8
    - 8的左边没数，即8是数组第一个数

而成为8的上边界条件也有两个：
1. 该数必须是8；
2. 该数的右边一个数必须不是8：
    - 8的右边有数，那么该数必须大于8
    - 8的右边没数，即8是数组的最后一个数

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};
        result[0] = searchLowerBound(nums, target, 0, nums.length - 1);
        result[1] = searchUpperBound(nums, target, 0, nums.length - 1);
        return result;
    }

    // 搜索下边界
    public int searchLowerBound(int[] nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }

        int middle = low + (high - low) / 2;
        // 判断是否为下边界
        // 先看看middle的数是否为target，并判断该数是否已为数组的第一个数，或者它左边的第一个数是不是已经比它小，如果都满足即为下边界
        if (nums[middle] == target && (middle == 0 || nums[middle - 1] < target)) {
            return middle;
        }

        if (target <= nums[middle]) {
            return searchLowerBound(nums, target, low, middle - 1);
        } else {
            return searchLowerBound(nums, target, middle + 1, high);
        }
    }

    // 搜索上边界
    public int searchUpperBound(int[] nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }

        int middle = low + (high - low) / 2;
        // 判断是否为上边界
        // 先看看middle的数是否为target，并判断该数是否已为数组的最后一个数，或者它右边的第一个数是不是比它大，如果都满足即为上边界
        if (nums[middle] == target && (middle == nums.length - 1 || nums[middle + 1] > target)) {
            return middle;
        }

        if (target < nums[middle]) {
            return searchUpperBound(nums, target, low, middle - 1);
        } else {
            return searchUpperBound(nums, target, middle + 1, high);
        }
    }
}
```