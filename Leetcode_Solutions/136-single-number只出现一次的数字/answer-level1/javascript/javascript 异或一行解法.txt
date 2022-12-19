

利用二进制异或的方法，再使用js的`reduce`api，可以实现一行完成。空间复杂度O(1)，时间复杂度O(n)

```
var singleNumber = function(nums) {
  return nums.reduce((before, now) => before^now)
};
```
