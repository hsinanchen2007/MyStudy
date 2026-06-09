### 解题思路
将数组从中间分成两个数组 L 和 R。比较 L 最后一个值 l 与 R 的第一个值 r 的大小。如果 l > r 则数组 L 必有一个及以上原数组的峰值，取数组 L 再做上一步。反之则数组 R 必有一个及以上原数组的峰值，取数组 R 再做上一步。当数组长度为 1 时。其值为峰值。

### 代码

```javascript
var findPeakElement = function(nums) {
    let lIndex = 0; // 虚拟数组第一个元素下标
    let rIndex = nums.length - 1; // 虚拟数组最后一个元素下标
    let mid; // 数组中间元素下标。
    while (lIndex < rIndex) { // 当数组长度不为 1 时。
        mid = Math.floor((lIndex + rIndex) / 2); // 取当前虚拟数组的中间元素的下标（当数组长度为偶数时取小的那个），可将虚拟元素隔开成两个数组。
        if (nums[mid] > nums[mid + 1]){ // 比较左边数组最后一个元素与右边数组的第一个元素的大小
            rIndex = mid; // 左边数组最后一个元素大、则取左边数组
        } else {
            lIndex = mid + 1; // 右边数组第一个元素大、则取右边数组
        }
    }
    return lIndex;
};
```