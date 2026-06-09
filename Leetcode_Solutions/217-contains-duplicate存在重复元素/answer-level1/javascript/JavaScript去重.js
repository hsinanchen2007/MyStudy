### 解题思路

js去重对比长度即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const arr = [...new Set(nums)]
    return arr.length !== nums.length
};
```