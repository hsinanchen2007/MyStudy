### 解题思路
在 [0, 1, 2, 3, 5, 6, 7] 这个数组中，数组被分为了左右两部分。
左边部分是 [0, 1, 2, 3]，元素特征是 nums[i] == i。
右边部分是 [5, 6, 7]，元素特征是 nums[i] != i。
我们要找的数字，就是这两个部分相接的地方的位置。

我们维护 left 和 right 两个变量，left 永远指向左边那部分，right 永远指向右边那部分，然后 left 和 right 一起从两边向中间不断移动。移动到什么时候停止呢？当 right - left == 1 时，此时就说明我们找到了相接的位置。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    if (nums[0] > 0) {
        // 比如 [1, 2, 3] 这种情况无法初始化 left 指针，因为压根不存在 nums[i] == i 的位置
        return 0;
    }
    if (nums[nums.length - 1] < nums.length) {
        // 比如 [0, 1, 2] 这种情况无法初始化 right 指针，因为压根不存在 nums[i] != i 的位置
        return nums.length;
    }
    var left = 0;
    var right = nums.length - 1;
    while (right - left > 1) {
        var mid = left + ((right - left) >> 1);
        if (nums[mid] == mid) {
            // 说明我们找到的 mid 这个位置的元素属于“左边的部分”，可以安全地把 left 指针移过来
            left = mid;
        } else if (nums[mid] != mid) {
            // 说明我们找到的这个 mid 这个位置的元素属于“右边的部分”，可以安全地把 right 指针移过来
            right = mid;
        }
    }
    // 比如 [1, 2, 4, 5] 这个数组，此时 left 会指向数字 2，right 会指向数字 4，显然 left + 1 就是我们要的答案
    return left + 1;
};
```