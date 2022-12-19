### 解题思路
利用递归将手动全排列的过程实现出来即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
  const res = []
  perm(nums, 0, nums.length - 1)
  return res

  function perm (nums, p, q) {
    if (p === q) {
      // 当遍历到最后一位时，将当前轮的结果放入 res
      res.push([...nums])
    } else {
      for (let i = p; i <= q; i++) {
        // 1. 交换第一位跟第 i 位
        // 如，未交换前：nums=[1,2,3] p=0 i=2  则交换后：nums=[2, 1, 3]
        swap(nums, i, p)
        // 2. 递归遍历 p+1 至 q 位
        // 如，此时nums=[2, 1, 3]，由于 2 是不变的，则只需找到后两位[1, 3]的结果
        perm(nums, p + 1, q)
        // 3. 复位第一步的交换
        swap(nums, i, p)
      }
    }
  }

  function swap (A, i, j) {
    [A[i], A[j]] = [A[j], A[i]]
  }
};
```