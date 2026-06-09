### 解题思路
双指针

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
    for (let cur = m-- + n-- - 1; cur >= 0; cur--) {
            if (m < 0) {
                A[cur] = B[n--];
            } else if (n < 0) {
                A[cur] = A[m--];
            } else {
                A[cur] = A[m] >= B[n] ? A[m--] : B[n--];
            }
        }
        return A;
};
```