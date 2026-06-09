- right表示以arr[arr.length - 1]为结尾的最大的连续子数组和
- left表示以arr[0]为开头的最大的连续子数组和
- max表示arr数组中最大的连续子数组和
- toRightSum表示arr从左到右的和
- toLeftSum表示arr从右到左的和
- 如果数组不复制 直接返回max
- 如果数组的和小于等于0 则不需要复制的整个数组 返回 Math.max(left + right, max) % 1000000007
- 否则和大于0 返回
- Math.max(toRightSum * (k - 2) + left + right, max) % 1000000007
```
var kConcatenationMaxSum = function (arr, k) {
  let right = 0;
  let left = 0;
  let toLeftSum = 0;
  let toRightSum = 0;
  let max = 0;
  for (let l = 0, len = arr.length - 1, curMax = 0, r = len; l <= len; ++l, --r) {
    toRightSum += arr[l]
    toLeftSum += arr[r]
    curMax = Math.max(0, curMax + arr[l])
    max = Math.max(max, curMax)
    left = Math.max(left, toLeftSum)
    right = Math.max(right, toRightSum)
  }
  if (k === 1) {
    return max % 1000000007;
  } else if (toRightSum <= 0) {
    return Math.max(left + right, max) % 1000000007
  } else {
    return Math.max(toRightSum * (k - 2) + left + right, max) % 1000000007
  }
};
```
