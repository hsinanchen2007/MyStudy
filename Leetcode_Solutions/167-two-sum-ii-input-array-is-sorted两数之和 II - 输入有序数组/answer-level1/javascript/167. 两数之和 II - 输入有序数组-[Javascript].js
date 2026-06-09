```
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  let len = numbers.length;
  if (len === 0 || len === 1) {
    return [];
  }
  if (len === 2) {
    return [1, 2];
  }

  let left = 0;
  let right = len - 1;
  while (left < right) {
    let sum = numbers[left] + numbers[right];
    if (sum === target) {
      return [left + 1, right + 1];
    } else if (sum < target) {
      left ++;
    } else if (sum > target) {
      right --;
    }
  }
};
```
题目写明是有序数组, 运用双指针解决