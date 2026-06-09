### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    return nums.filter(i=> i.toString().length %2 == 0).length
};
```