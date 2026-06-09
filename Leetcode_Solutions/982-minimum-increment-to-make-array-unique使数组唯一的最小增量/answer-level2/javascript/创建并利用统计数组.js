```
var minIncrementForUnique = function(A) {
  if (A.length === 0) {
    return 0
  }
  let res = 0
  let min = A[0]
  const countArr = []
  for (let i = 0; i < A.length; ++i) {
    if (A[i] < min) {
      min = A[i]
    }
    if (countArr[A[i]] === undefined) {
      countArr[A[i]] = 1
    } else {
      countArr[A[i]]++
    }
  }
  const max = countArr.length - 1
  let pointer = min
  while (!(pointer >= max && countArr[pointer] === 1)) {
    if (countArr[pointer] > 1) {
      res += countArr[pointer] - 1
      if (countArr[pointer + 1] === undefined) {
        countArr[pointer + 1] = countArr[pointer] - 1
      } else {
        countArr[pointer + 1] += countArr[pointer] - 1
      }
    }
    ++pointer
  }
  return res
};
```
