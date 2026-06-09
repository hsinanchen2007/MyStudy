```js
var duplicateZeros = function(arr) {
    let len = arr.length;
    for (let i = 0; i < len; i++) {
        if (arr[i] == 0) {
            arr.splice(i, 0, 0)
            arr.pop()
            i++
        }
    }
};
```
