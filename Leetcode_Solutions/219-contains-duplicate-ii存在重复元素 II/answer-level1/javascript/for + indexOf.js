### 解题思路
循环nums,循环得当前值与除当前值以外第一个值相等得值得索引，两个索引相减对比k

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
   for(let i =0; i< nums.length; i++) {
       if (nums.indexOf(nums[i], i + 1) >= 0) {
           if (nums.indexOf(nums[i], i + 1) - i <= k) {
               return true
           }
       }
   }
   return false
};
```