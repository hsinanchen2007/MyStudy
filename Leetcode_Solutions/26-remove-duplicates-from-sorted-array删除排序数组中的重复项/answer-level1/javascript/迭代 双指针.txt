### 解题思路
把不重复的都往前移 返回不重复的length
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if (!nums || !nums.length) return [];
    if (nums.length === 1) return nums;
    let len = 1;
    for (let i =  1; i < nums.length; i++) {
        if (nums[i] !== nums[i-1]) {
            nums[len] = nums[i];
            len++;
        }
    }
    return len;
};
```