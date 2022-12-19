### 解题思路
只需要比较i+1 是否和 i 相等，相等的话，将i+1处的移除，i--,重新比较i+1 和 i.

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
     for(var i = 0;i<nums.length;i++)
     {
        if(nums[i+1] === nums [i]) {
            nums.splice(i+1,1);
            i--;
        }
     }
     return nums.length;
};
```