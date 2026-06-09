- 如果数组已经排好序 则插入数据和删除数据的时间复杂度都是logn
- 先将k个数插入排序数组中 若最后一个元素的索引是i
- 求出中位数
- 再删除第i-k+1个元素
- 增加元素 二分查找
- 删除元素 二分查找
```
var medianSlidingWindow = function (nums, k) {
  let isOdd = k % 2;
  let arr = [];
  let res = [];
  let add = function (num) {
    let left = 0;
    let right = arr.length;
    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      if (arr[mid] < num) {
        left = mid + 1
      } else {
        right = mid;
      }
    }
    arr.splice(left, 0, num);
  }
  let remove = function (num) {
    let left = 0;
    let right = arr.length - 1;
    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      if (arr[mid] < num) {
        left = mid + 1
      } else {
        right = mid;
      }
    }
    arr.splice(left, 1);
  }
  for (let i = 0; i < k - 1; ++i) {
    add(nums[i])
  }
  for (let i = k - 1, len = nums.length; i < len; ++i) {
    add(nums[i])
    if (isOdd) {
      res.push(arr[(k - 1) / 2])
    } else {
      res.push((arr[k / 2] + arr[k / 2 - 1]) / 2)
    }
    remove(nums[i - k + 1])
  }
  return res;
};
```
