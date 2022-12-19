```js
var minimumAbsDifference = function(arr) {
    arr.sort((a, b) => a - b)
    let res = []
    let minDiff = arr[1] - arr[0]
    for (let i = 1; i < arr.length - 1; i++) {
        minDiff = Math.min(arr[i+1] - arr[i], minDiff)
    }
    for (let i = 0; i < arr.length - 1; i++) {
        if (arr[i+1] - arr[i] == minDiff) {
            res.push([arr[i], arr[i+1]])
        }
    }
    return res
};
```
