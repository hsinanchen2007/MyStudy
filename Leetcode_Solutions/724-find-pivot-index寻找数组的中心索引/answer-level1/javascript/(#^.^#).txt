## 第一版，虽然这道题很简单，但比起以前我也还算有进步吧。
> 80ms,37.4M,>97.51%。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
  }
  
  let sumLeft = 0;
  for (let i = 0; i < nums.length; i++) {
    sum -= nums[i];
    if (sumLeft === sum) return i;
    sumLeft += nums[i];
  }
  return -1;
};
```
#### 思路：两遍循环，第一遍算出总的和，第二遍拿左边的和（每次加一个值）与右边的和（从总和中每次减一个值）依次对比是否相等即可。