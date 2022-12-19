### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    var lastFoundNotZero = 0; // 最后一个找到的非0元素
    for(var i=0; i<nums.length; i++) {
        if(nums[i] != 0) {
            [nums[i], nums[lastFoundNotZero]] = [nums[lastFoundNotZero], nums[i]];
            lastFoundNotZero++;
        }
    }
};
```