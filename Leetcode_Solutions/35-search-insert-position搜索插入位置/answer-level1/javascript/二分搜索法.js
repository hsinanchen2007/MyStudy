### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let low = 0;
    let high = nums.length - 1;
    let mid;
    let element;

    while (low <= high) {
        mid = Math.floor((low + high) / 2);
        element = nums[mid];

        if (element < target) {
            low = mid + 1;
        } else if (element > target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return Math.floor((low + high) / 2) + 1;
};
```