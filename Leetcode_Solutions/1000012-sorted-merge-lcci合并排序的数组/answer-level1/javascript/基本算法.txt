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
    let realLen = m;
    let j = m - 1;
    for (let i = 0; i < n; i++) {
        while(B[i] < A[j]) {
            A[j + 1] = A[j--];
        }

        A[j + 1] = B[i];
        j = realLen++;
    }
};
```