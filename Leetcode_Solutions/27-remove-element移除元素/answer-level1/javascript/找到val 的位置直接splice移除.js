### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
     while(nums.indexOf(val) !== -1) {
         nums.splice(nums.indexOf(val),1)
     }
     return nums.length;
};
```