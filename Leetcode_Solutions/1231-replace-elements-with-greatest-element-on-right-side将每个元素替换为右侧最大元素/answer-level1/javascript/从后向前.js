
```
var replaceElements = function (arr) {
  let max = -1;
  for (let i = arr.length - 1; i >= 0; i--) {
    const curr = arr[i];
    arr[i] = max;
    if (max < curr) {
      max = curr;
    }
  }
  return arr;
};

```
