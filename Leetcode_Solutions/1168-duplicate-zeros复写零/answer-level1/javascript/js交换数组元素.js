找到0就把后面的数组都向后移动一位
```
var duplicateZeros = function(arr) {
  let n = arr.length
  for (let i = 0; i < n - 1; i++) {
    if (arr[i] == 0) {
      for (let j = n - 1; j > i; j--) {
        arr[j] = arr[j - 1]
      }
      arr[i + 1] = 0
      i++
    }
  }
}
```
