### 解题思路一
从大神题解那抄来的[极简Solution](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/)
大神的异或用的太强了，我要留个笔记。

    /*
     * 二分查找 -- 异或计算
     *
     * 通过规律可以总结出下面的图来：
     *                                            ┌ nums[mid] > target（移动右点）
     *                                            │
     *                   ┌ nums[mid] < nums[0] ─┼
     *                   │ （中点在右侧）        │
     *                   │                       └ nums[mid] < target (移动左点)
     * nums[0] > target ─┼
     *(目标在低处)       │
     *                   │
     *                   └ nums[mid] > nums[0] ── 移动左点 (此时肯定有 nums[mid] > target)
     *                     （中点在左侧）
     *
     *
     *                   ┌ nums[mid] < nums[0] ── 移动右点 (此时肯定有 nums[mid] < target)
     *                   │ （中点在右侧）
     *                   │
     * nums[0] < target ─┼
     *(目标在高处)       │                       ┌ nums[mid] > target（移动右点）
     *                   │                       │
     *                   └ nums[mid] > nums[0] ─┼
     *                      （中点在左侧）        │
     *                                            └ nums[mid] < target (移动左点)
     *
     * 从图中可以总结出：
     * 1> nums[0] > target
     * 2> nums[mid] < target
     * 3> nums[0] > nums[mid]
     * 三条件同时满足或仅满足一个，则在右区间，反之在左区间
     * （异或：相同为假，不同为真）
     *
     * 确定区间不断缩小后，最后需要判断该值是否在数组中
     * */

### 代码

```cpp
int search(std::vector<int> &nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    int left = 0, right = nums.size() - 1, mid = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 如果mid的值与target相等就返回
        if (nums[mid] == target) {
            return mid;
        }

        // 右区间有序
        if (nums[mid] < nums[right]) {
            // target在有序右区间内
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

            // 左区间有序
        } else {
            // target在有序左区间内
            if (nums[mid] > target && target >= nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    return -1;
}
```

### 解题思路二
    /*
     * 二分查找
     *
     * 因为即使旋转，旋转后的两部分仍然有序，
     * 则nums[mid]必定在某一有序序列中，
     * 所以需要先判断nums[mid]在哪边序列中，
     * 当nums[mid]<nums[right](或者nums[mid]<nums[left])在右序列中,
     * 当nums[mid]>nums[right](或者nums[mid]>nums[left])在左序列中,
     * 当判断是在那个序列中后，继而按照升序的二分查找，
     * 对target进行判断，转变左或右边界的值即可。
     * */
### 代码

```cpp
int search(std::vector<int> &nums, int target) {
    if (nums.empty()) {
        return -1;
    }

    int left = 0, right = nums.size() - 1, mid = 0;

    while (left < right) {
        mid = left + (right - left) / 2;

        // 当此三条件均为真或仅一个为真，则为右区间
        // 反之则为左区间
        // 异或：相同为假，不同为真
        if ((nums[0] > target) ^ (nums[mid] < nums[0]) ^ (nums[mid] < target)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // 比较到最后时，判断有无该值
    return (nums[left] == target ? left : -1);
}
```