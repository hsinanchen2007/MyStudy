虽然算法慢了一点，但还是自己写了出来。

### 代码
```js
var minIncrementForUnique = function (A) {
  if (A.length <= 1) {
    return 0;
  }
  let res = 0
  let map = new Map()
  for (let i = 0; i < A.length; i++) {
    if (map.has(A[i])) {
      let index = map.get(A[i]) + 1
      while (map.has(index)) {
        index = map.get(index) + 1
      }
      map.set(A[i], index)
      map.set(index, index)
      res = res + (index - A[i])
    } else {
      map.set(A[i], A[i])
    }
  }
  return res
};
```