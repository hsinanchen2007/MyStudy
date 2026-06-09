**动态规划**
```js
var maxSubArray = function(nums) {
  let len = nums.length;
  let max = nums[0];
  for (let i = 0; i < len; i++) {
    if (nums[i - 1] > 0) nums[i] += nums[i - 1];
    max = Math.max(max, nums[i]);
  }
  return max;
};
```

**贪心算法**
```js
var maxSubArray = function(nums) {
  let len = nums.length;
  let max = nums[0];
  let curr = nums[0];
  for (let i = 0; i < len; i++) {
    curr = Math.max(nums[i], curr + nums[i]);
    max = Math.max(max, curr);
  }
  return max;
};
```