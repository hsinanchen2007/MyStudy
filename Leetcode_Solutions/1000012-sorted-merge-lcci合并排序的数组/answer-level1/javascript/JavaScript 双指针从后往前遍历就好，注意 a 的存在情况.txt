```
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    let len = m + n
    let a = m-1
    let b = n-1
    for(let i=len-1;i>=0&&b>=0;i--) {
        if(A[a] === undefined || B[b] >= A[a]) {
            A[i] = B[b]
            b--
        } else {
            A[i] = A[a]
            a--
        }
    }
};
```
