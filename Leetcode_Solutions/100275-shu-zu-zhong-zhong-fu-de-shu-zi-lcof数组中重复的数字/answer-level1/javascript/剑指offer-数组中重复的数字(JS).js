```js
var findRepeatNumber = function(nums) {
  let result = {};
  for (let i of nums) {
    if (result[i]) {
      return i;
    } else {
      result[i] = 1;
    }
  }
  return -1;
};
```