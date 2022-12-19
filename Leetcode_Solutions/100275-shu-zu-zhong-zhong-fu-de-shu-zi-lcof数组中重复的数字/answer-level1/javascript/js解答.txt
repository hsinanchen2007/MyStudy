### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
   var set = new Set();
   var repeat = -1;
   for(let i=0;i<nums.length;i++){
       if(!set.has(nums[i])) {
           set.add(nums[i]);
       } else {
           repeat = nums[i];
           break;
       }
   }
   return repeat;
};
```