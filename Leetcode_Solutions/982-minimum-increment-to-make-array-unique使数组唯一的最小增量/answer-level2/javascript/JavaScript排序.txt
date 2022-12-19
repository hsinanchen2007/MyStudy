排序后将数组中当前元素增加到对应位置，记录增加到"对应"位置需要花费的值

```js
var minIncrementForUnique = function(A) {
  let len = A.length
  if (len < 2) return 0
  A.sort((a, b) => a - b)
  let result = 0
  for (let i = 1; i < len; i++) {
    if (A[i] <= A[i - 1]) {
      result += A[i - 1] + 1 - A[i]
      A[i] = A[i - 1] + 1
    }
  }

  return result
}
```
