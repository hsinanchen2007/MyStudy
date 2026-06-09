### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    return nums.reduce(function(acc, cur) {
        return acc + (cur.toString().length % 2 ? 0 : 1);
    }, 0);
};
```