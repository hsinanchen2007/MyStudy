# 14 - 搜索插入位置

## 题目

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

> 输入: [1,3,5,6], 5
> 输出: 2

示例 2:

> 输入: [1,3,5,6], 2
> 输出: 1

示例 3:

> 输入: [1,3,5,6], 7
> 输出: 4

示例 4:

> 输入: [1,3,5,6], 0
> 输出: 0

## 解答

感觉和`two sum`差不多，可以用哈希表和两分法

### 暴力解法

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  if (nums[0] > target) {
    return 0;
  }
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] >= target) {
      return i;
    }
  }
  return nums.length;
};
```

> Runtime: 52 ms, faster than 85.47% of JavaScript online submissions for Search Insert Position.
> 
> Memory Usage: 34.3 MB, less than 41.45% of JavaScript online submissions for Search Insert Position.

### 双指针

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  if (nums[0] > target) {
    return 0;
  } else if (nums[nums.length - 1] < target) {
    return nums.length;
  }
  let start = 0;
  end = nums.length - 1;
  while (start <= end) {
    let mid = Math.round((start + end) / 2);
    if (nums[mid] === target) {
      return mid;
    } else if (nums[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return start;
};
```

>Runtime: 76 ms, faster than 5.48% of JavaScript online submissions forSearch Insert Position.
>
>Memory Usage: 33.9 MB, less than 59.44% of JavaScript online submissions for Search Insert Position.

这运行时间简直惊呆了。。。