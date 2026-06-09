### 解题思路

大家好， 我是 17。

设 max 为当前可以达到的最远距离。
1. 迭代。
2. 如果当前位置超出最远距离，返回 false
3. 计算新的 max

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
   //当前可以达到的最远距离
   let max=0
   for(let i=0;i<nums.length;i++){
       if(i>max) return false
       max=Math.max(max,i+nums[i])
   }
   return true
};
```