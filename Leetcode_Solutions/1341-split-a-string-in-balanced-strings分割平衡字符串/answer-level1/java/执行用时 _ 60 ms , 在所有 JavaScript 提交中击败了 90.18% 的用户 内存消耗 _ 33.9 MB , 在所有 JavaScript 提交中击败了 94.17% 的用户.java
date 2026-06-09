```
var balancedStringSplit = function (s) {
    let arr = s.split('')
    let length = arr.length
    if (length < 2) return 0
    let left = 0, right = 1, count = 0, same = 1
    while (right < length) {
        if (arr[left] !== arr[right]) {
            same--
            if (same === 0) {
                count++
                left = right + 1
                right++
                same = 1
            }
        } else {
            same++
        }
        right++
    }
    return count
};
```
