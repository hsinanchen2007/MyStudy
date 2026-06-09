- 这题的本质是“求所有子数组和中不大于K的最大的数组和”，只是包装成了二维矩阵；
- 那么如何分解问题呢？只需要把矩阵压缩成一列即可，压缩就是把同一行的元素求和作为这一行的元素。那么就需要两重循环枚举所有的情况；
- 剩下来要做的时候就是本题的考点，求不大于K的最大子数组和，为了不让复杂度过高，可以利用二分；
  - 利用前缀和的思想，求[i, j]的和就是求 accu[j] - accu[i - 1]
  - 所以遍历accu，对于指针j就是要找满足最小的大于accu[j] - k的前缀和即可，这样两者做差得到的数组和就是最大的小于K的和
  - “找最小”这种事就是二分的使用场景

js实现如下
```js
var maxSumSubmatrix = function(matrix, k) {
  const row = matrix.length;
  if (!row) return 0;
  const col = matrix[0].length;
  if (!col) return 0;

  let max = -Infinity;
  for (let l = 0; l < col; l++) {
    const list = new Array(row).fill(0);
    for (let r = l; r < col; r++) {
      for (let k = 0; k < row; k++) list[k] += matrix[k][r];
      const m = maxSubarraySumNoMoreThanK(list, k);
      max = Math.max(max, m);
    }
  }

  function maxSubarraySumNoMoreThanK(list, k) {
    let max = -Infinity;
    const preSum = [0];
    let accu = 0;
    for (let i = 0; i < list.length; i++) {
      accu += list[i];
      const index = findLowerBound(preSum, accu - k);
      const sum = accu - preSum[index];
      if (sum <= k) max = Math.max(max, sum);
      insert(preSum, accu);
    }
    return max;
  }

  function insert(nums, target) {
    if (target >= nums[nums.length - 1]) {
      nums.push(target);
      return;
    }
    const index = findLowerBound(nums, target);
    nums.splice(index, 0, target);
  }

  function findLowerBound(nums, target) {
    let l = 0;
    let r = nums.length - 1;
    while (l < r) {
      const mid = l + r >>> 1;
      if (nums[mid] >= target) r = mid;
      else l = mid + 1;
    }
    return l;
  }

  if (max === -Infinity) return 0;
  return max;
};
```
