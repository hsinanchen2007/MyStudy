

```js

var sortColors = function(nums) {
  
  if (!nums.length) return nums;

  let length = nums.length;

  let zeroLastIndex = length;

  for (let i = 0; i < length; i++) {
    switch (nums[i]) {
      case 0:
        nums.splice(zeroLastIndex, 0, 0);
        // 更新 zeroLastIndex
        zeroLastIndex++;
        break;
      case 1:
        nums.splice(zeroLastIndex, 0, 1);
        break;
      case 2:
        nums.push(2);
        break;
    }
  }

  nums.splice(0, length);
};
```