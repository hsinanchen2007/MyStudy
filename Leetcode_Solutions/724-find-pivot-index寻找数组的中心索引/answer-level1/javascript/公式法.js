### 解题思路
1、和官方解题思想保持一致，使用公式leftSum + item + rightSum = sum
2、leftSum和rightSum相等时，2*leftSum + item = sum

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
   let leftSum = 0;
   let sum = nums.reduce(
       (i, j) => i + j, 0
   );

      return nums.findIndex((item, i) => {
       if((sum - item - leftSum) === leftSum) {
           return true;
       }
       leftSum = leftSum + item;
   });
};
```