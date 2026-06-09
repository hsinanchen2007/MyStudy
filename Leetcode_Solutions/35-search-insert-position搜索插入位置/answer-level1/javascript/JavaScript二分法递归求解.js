### 解题思路
看到这种有顺序的数组，第一想法就是二分法。
二分法每次取对半,时间复杂度为：O(logN).
采用递归的方式更好理解。
先取数组最中间的值跟target比较，相等则找到了，返回中间的下标；
target值大于中间值，则在中间值和右边值，左开右闭的区间再递归寻找；
target值小于中间值，则在左边值和中间值，左闭右开的区间内寻找。
当左边的下标大于右边下标时，说明没找到相当的值，而此时左边的下标正是插入的下标，返回左边的下标。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
    let left = 0;
    let right = nums.length - 1;
    return binarySearch(left, right, nums, target)
};

function binarySearch(left, right, nums, target) {
    if (left > right) {
        return left;
    }
    let mid = parseInt((left + right) / 2);
    if (target === nums[mid]) {
        return mid;
    } else if (target > nums[mid]) {
        return binarySearch(mid + 1, right, nums, target)
    } else {
        return binarySearch(left, mid - 1, nums, target)
    }
}
```