```
var singleNumber = function (nums) {
  return nums.reduce((xor, n) => n ^ xor);
};
```
