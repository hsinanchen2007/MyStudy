### 解题思路
归并排序是分治法的一种应用

### 算法描述
- 步骤1：把长度为n的输入序列分成两个长度为n/2的子序列；
- 步骤2：对这两个子序列分别采用归并排序；
- 步骤3：将两个排序好的子序列合并成一个最终的排序序列

### 动图演示

![image](https://pic.leetcode-cn.com/6a9695c185a358aa785a5797514af41826e4d2c132cea2924d2f4a8cac2e3bd5-file_1581503384141)

### 代码

```javascript
/**
 * 归并排序
 * @param {number[]} nums
 * @return {number[]}
 */
let sortArray = function(nums) {
  let len = nums.length
  if (len === 1) return nums
  let mid = len / 2
  let left = nums.slice(0, mid)
  let right = nums.slice(mid, len)
  return merge(sortArray(left), sortArray(right))
}
let merge = function(left, right) {
  let result = []
  while(left.length && right.length) {
    if (left[0] < right[0]) {
      result.push(left[0])
      left.splice(0, 1)
    } else {
      result.push(right[0]),
      right.splice(0, 1)
    }
  }
  return result.concat(left).concat(right)
}
```

### 复杂度分析

最好情况：T(n) = O(nlogn)

最坏情况：T(n) = O(nlogn)

平均情况：T(n) = O(nlogn)