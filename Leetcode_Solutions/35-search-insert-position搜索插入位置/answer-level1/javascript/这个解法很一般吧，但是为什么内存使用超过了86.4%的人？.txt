### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function searchInsert(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > target) {
        return i > 0 ? i: 0
        } else if (nums[i] === target) {
        return i
        }
    }
    return nums.length
};
```