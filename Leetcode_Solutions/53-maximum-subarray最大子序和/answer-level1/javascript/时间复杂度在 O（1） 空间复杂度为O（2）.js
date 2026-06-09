### 解题思路

分别定义两个不同 变量存放最大值和上次相加的最大做或者上次nums[i]的最大值，在对比current和max对比得到最大值
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let max=nums[0];
     let current=nums[0];
   for(let i =1;i<nums.length;i++){
        current=Math.max(current+nums[i],nums[i]);
        max=Math.max(current,max)
   }
    return max
};
```