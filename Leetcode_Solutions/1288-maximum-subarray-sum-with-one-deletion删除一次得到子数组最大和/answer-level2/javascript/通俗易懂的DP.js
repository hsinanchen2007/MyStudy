```
var maximumSum = function (arr) {
  if (arr.length === 1) return arr[0]
  let len = arr.length;
  // dpLeft[i]以arr[i-1]为结尾的最大子数组和
  let dpLeft = new Array(len + 1).fill(0)
  // dpRight[i]以arr[i]为开头的最大子数组和
  let dpRight = new Array(len + 1).fill(0)
  // 被删除的数arr[i] 结果就可以表示为 dpLeft[i] + dpRight[i+1]
  // 或者  dpLeft[i] 或者 dpRight[i+1]
  for (let i = 1; i <= len; ++i) {
    dpLeft[i] = Math.max(dpLeft[i - 1], 0) + arr[i - 1];
  }
  for (let i = len - 1; i >= 0; --i) {
    dpRight[i] = Math.max(dpRight[i + 1], 0) + arr[i];
  }
  // i = 0 或者 i = len - 1 的特殊情况 处理一下
  let res = Math.max(dpRight[1], dpLeft[len - 1], dpLeft[len--])
  for (let i = 1; i < len; ++i) {
    if (arr[i] < 0) {
      res = Math.max(res, dpLeft[i], dpRight[i + 1], dpLeft[i] + dpRight[i + 1]);
    }
  }
  return res;
};
```
