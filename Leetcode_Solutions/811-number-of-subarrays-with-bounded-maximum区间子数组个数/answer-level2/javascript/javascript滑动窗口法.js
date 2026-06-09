### 解题思路

大家好，我是 17

这道题首先需要归纳总结。依题意，需要把数分成两种，一种是大于 R 的，一种是小于 R 的。

1. 小于 R 的分两种。

  一种是在区间的，计数公式是 当前元素位置减去窗口第一个元素位置。
  比如现在窗口内的元素是 [3,4] 区间范围是 [3,6]，新加一个元素 5 ,从后向前看，可以组成的连续分组有 [5,4] [5,4,3]。

  一种是小于 L 的，必须有一个区间内的元素包含在内，所以计数公式是区间内最右边元素位置减去窗口第一个元素位置。

2. 大于R 的不计数，更新 窗口最左位置 left,和最后一个区间内元素的位置 lastLeft

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var numSubarrayBoundedMax = function (A, L, R) {
  let count = 0
  //窗口中的最右边的 区间内元素的索引 lastLeft
  let lastLeft = -1
  //窗口最左位置索引
  let left = -1
  for (let i = 0; i < A.length; i++) {
    if (A[i] <= R) {
      if (A[i] >= L && A[i] <= R) {
        lastLeft = i
        count += i - left
      }
      else {
        count += lastLeft - left
      }
    }
    else {
      lastLeft = i
      left = i
    }

  }
  return count
};
```