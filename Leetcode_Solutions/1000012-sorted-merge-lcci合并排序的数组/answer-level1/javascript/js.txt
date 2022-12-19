### 解题思路
插入即可

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
    let i = m - 1, j = n - 1, p = m + n - 1
  
  while (i >= 0 || j >= 0) {
    let l = i >= 0 ? A[i] : -Infinity,
        r = j >= 0 ? B[j] : -Infinity
    
    if (l > r) {
      A[p] = l
      i--
    } else {
      A[p] = r
      j--
    }
    
    p--
  }
  
  return A
};
```