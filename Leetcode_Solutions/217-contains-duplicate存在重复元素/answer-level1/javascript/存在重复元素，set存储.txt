### 解题思路
has的搜索速度或许比sort排序速度快

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const setData = new Set();
    for (let i = 0; i < nums.length; i++) {
        if (setData.has(nums[i])) {
            return true;
        } else {
            setData.add(nums[i]);
        }
    }
    return false;
};
```