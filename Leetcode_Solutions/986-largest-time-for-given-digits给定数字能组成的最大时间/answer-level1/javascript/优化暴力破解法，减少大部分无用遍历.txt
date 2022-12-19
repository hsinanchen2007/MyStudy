看到大部分题解都是用暴力，仔细思考了一下，其实有优化空间，
其一，第一位肯定要是小于3的数字；
其二，可以先对数组进行排序，这样就可以从最大的结果往小遍历，从而减少很多不必要的遍历

```
var largestTimeFromDigits = function(A) {
    A.sort((a, b) => a - b)
    let res = [0,0,':',0,0]
    let less3Index = -1
    for (let i = 0; i < 4; i++) {
        if (A[i] < 3) {
            less3Index = i
        } else {
            break
        }
    }
    if (less3Index < 0) return ''
    for (; less3Index >= 0; less3Index--) {
        for (let i = 3; i >= 0; i--) {
            if (i === less3Index) continue
            let hour = A[less3Index] + '' + A[i]
            for (let j = 3; j >= 0; j--) {
                if (j === i || j === less3Index) continue
                for (let k = 3; k >= 0; k--) {
                    if (k === j || k === i || k === less3Index) continue
                    let minute = A[j] + '' + A[k]
                    if (isValid(hour, minute)) {
                        return hour + ':' + minute
                    }
                }
            }
        }
    }
    return ''

    function isValid(hour, minute) {
        return hour < 24 && minute < 60
    }
};
```
