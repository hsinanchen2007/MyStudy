遍历这个数组，每走一步都计算后面能走的最大路径。

```js
var canJump = function(nums) {
  var curMaxStep = 0;
  for (var i = 0; i < nums.length; i++) {
    curMaxStep = Math.max(curMaxStep, nums[i]);
    if (curMaxStep + i >= nums.length - 1) {
      return true;
    }
    if (--curMaxStep === -1) {
      return false;
    }
  }
};
```