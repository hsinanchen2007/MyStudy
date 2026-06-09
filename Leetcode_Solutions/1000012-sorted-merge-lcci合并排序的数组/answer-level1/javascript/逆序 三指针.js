```
var merge = function(A, m, B, n) {
  if (!A || !B || m < 0 || n < 0) {
    return []
  }
  
  let p1 = m - 1
  let p2 = n - 1
  let p0 = m + n - 1
  
  while (p0 >= 0) {
    if (p1 < 0) {
      A[p0] = B[p2]
      p2--
      p0--
    } else if (p2 < 0) {
      A[p0] = A[p1]
      p1--
      p0--
    } else if (A[p1] < B[p2]) {
      A[p0] = B[p2]
      p2--
      p0--
    } else {
      A[p0] = A[p1]
      p1--
      p0--
    }
  }
};
```
