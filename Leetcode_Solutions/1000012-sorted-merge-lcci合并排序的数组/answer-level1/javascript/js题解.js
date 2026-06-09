### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
  let length = m + n - 1;
  let indexA = m-1, indexB = n-1;
  while (length >= 0) {
    while (indexA >= 0 && indexB >= 0) {
      if (A[indexA] > B[indexB]) {
        A[length--] = A[indexA--];
      } else {
        A[length--] = B[indexB--];
      }
    }
    while (indexA >= 0) {
      A[length--] = A[indexA--]
    }
    while (indexB >= 0) {
      A[length--] = B[indexB--]
    }
  }
  return A
};
```