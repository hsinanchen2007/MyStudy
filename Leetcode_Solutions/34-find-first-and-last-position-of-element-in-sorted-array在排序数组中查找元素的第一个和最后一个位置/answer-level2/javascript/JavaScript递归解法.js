解题思路，第一步先二分查找，找到一个等于target值的索引，然后再去左边找最左边等于target值的索引，右边找最右边等于target值的索引。

```JavaScript
var searchRange = function (nums, target) {
  let len = nums.length;
  let left = 0;
  let right = len - 1;
  return binarySearch(left, right, nums, target)
};

function binarySearch(left, right, nums, target) {
  if (left > right) {
      // 没找到
      return [-1, -1]
  }
  let mid = parseInt((left + right) / 2);
  if (nums[mid] === target) {
      // 找最左边等于target的索引
      let minIndex = leftSearch(left, mid - 1, nums, target);
      if (minIndex === -1) {
          minIndex = mid;
      }
      // 找最右边等于target的索引
      let maxIndex = rightSearch(mid + 1, right, nums, target);
      if (maxIndex === -1) {
          maxIndex = mid;
      }
      return [minIndex, maxIndex]
  } else if (nums[mid] > target) {
      return binarySearch(left, mid - 1, nums, target);
  } else {
      return binarySearch(mid + 1, right, nums, target)
  }
}

function leftSearch(left, right, nums, target) {
  if (left > right) {
      return -1;
  }
  let mid = parseInt((left + right) / 2);
  if (nums[mid] === target) {
      let index = leftSearch(left, mid - 1, nums, target);
      if (index === -1) {
          return mid;
      }
      return index;
  } else {
      return leftSearch(mid + 1, right, nums, target);
  }


}

function rightSearch(left, right, nums, target) {
  if (left > right) {
      return -1;
  }
  let mid = parseInt((left + right) / 2);
  if (nums[mid] === target) {
      let index = rightSearch(mid + 1, right, nums, target);
      if (index === -1) {
          return mid;
      }
      return index;
  } else {
      return rightSearch(left, mid - 1, nums, target);

  }
}

```
