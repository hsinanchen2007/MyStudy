以暴制暴
```
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canReorderDoubled = function(A) {
    let arr = A.sort((i, j) => i - j)
    let len = A.length
    while(arr.length) {
        let item = arr.pop()
        if (item >= 0) {
            let pair = item/2
            let idx = arr.indexOf(pair)
            if (idx === -1) return false
            arr.splice(idx, 1)
        } else {
            let pair = item * 2
            let idx = arr.indexOf(pair)
            if (idx === -1) return false
            arr.splice(idx, 1)
        }
    }
    return true
};
```
