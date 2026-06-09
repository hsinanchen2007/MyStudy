![image.png](https://pic.leetcode-cn.com/49f1a86fd19657fd276995021041c1aa5ee6d602447c98cadd8bd093949426cb-image.png)

### 解题思路
```js
初始化 sum 为 -Infinity
一个一个遍历 nums 数组

遇到每一个数 nums[i] 做判断：
  - 自己的 sum 是否为正数？
    是 -> 继续累加 nums[i]
    否 -> 丢弃掉自己手中的 sum，直接把 nums[i] 更新过来，变成 sum，
          因为不管当前数 nums[i] 是多少，此时自己手中的 sum 是负数，都会把
          累加后的和变小，所以直接丢弃
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var maxSubArray = function(nums) {
  let sum = -Infinity, max = -Infinity;
  
  for (let i = 0, len = nums.length; i < len; i++) {
    if (sum < 0) {
      sum = nums[i];
    } else {
      sum += nums[i];
    }
    
    max = Math.max(sum, max);
  }
  
  return max;
}

/*
  一次遍历
  维护一个累计的和 sum，每次遇到一个新的数，判断
    - 如果新的数加上 sum 大于当前当前累加和，那么重置 sum = 0
    - 否则 sum 加上这个数
*/
// var maxSubArray = function(nums) {
//   let sum = 0, max = -Infinity;
  
//   for (let i = 0, len = nums.length; i < len; i++) {
//     if (sum + nums[i] < nums[i]) {
//       sum = nums[i];
//     } else {
//       sum += nums[i];
//     }
    
//     if (sum > max) max = sum;
//   }
  
//   return max;
// };
```