# 暴力求和
每次遍历都将索引两边元素相加求和，然后进行判断相等就抛出结果；
``` javascript
var pivotIndex = function(nums) {
    var left = [];
  var sum = 0;
  nums.forEach(function(item) {
    sum = sum + item;
  });

  for (var i = 0; i < nums.length; i++) {
    var item = nums[i];
    var leftSum = 0;
    var rightSum = 0;
    if (i > 0) {
      left.push(nums[i - 1]);
    }
    left.forEach(function(item) {
      leftSum += item;
    });
    rightSum = sum - leftSum;
    if (leftSum === rightSum - item) {
      return i;
    }
  }
  return -1;
};
```