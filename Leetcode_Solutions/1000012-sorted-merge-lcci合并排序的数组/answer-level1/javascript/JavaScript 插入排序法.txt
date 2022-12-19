
### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function (A, m, B, n) {
  A.splice(m)

  for (let i = 0; i < B.length; i++) {
    if(A.length == 0){
       A.push(B[i])
       continue
    }
    for (let j = 0; j < A.length; j++) {
      if (B[i] < A[j]) {
        A.splice(j, 0, B[i])
        break
      }
      if (j == A.length - 1) {
        A.push(B[i])
        break
      }
    }
  }
};
```