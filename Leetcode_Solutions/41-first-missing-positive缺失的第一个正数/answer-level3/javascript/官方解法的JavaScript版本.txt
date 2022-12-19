稍微修改了一点，加了点自己的理解

时间复杂度 O(3n)
空间复杂度 O(1) 

```JavaScript
var firstMissingPositive = function (nums) {
  var n = nums.length;

  //处理负数
  //可以不处理超出 length+1 的值， 因为js数组没有越界问题
  //由于 NaN 会影响判断 并且 结果最大为 length+1， 所以将边界增加到 length+1
  //可以不添加边界，在结果判断NaN 
  for (var i = 0; i <= n + 1; i++) {
    if (nums[i] <= 0 || !nums[i]) nums[i] = n + 1;
  }

  //如果出现正整数 a，将第 a 项的值转成负数，标记 a 出现过
  for (var i = 0; i < n; i++) {
    var a = Math.abs(nums[i])
    nums[a] = - Math.abs(nums[a]);
  }

  //如果第 i 项为正整数，则说明 i 没有出现过（负数说明出现过），即为答案
  for (var i = 1; i <= n + 1; i++) {
    if (nums[i] > 0) return i
  }

};
```