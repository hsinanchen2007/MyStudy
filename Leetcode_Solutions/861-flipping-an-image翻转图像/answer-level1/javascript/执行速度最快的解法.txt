```
var flipAndInvertImage = function (A) {

    for (let i = 0; i < A.length; i++) {
        let curs = A[i]
        let len = curs.length
        let end = len - 1
        for (let j = 0; j < len; j++) {
            if (j <= end - j) {
                let temp = curs[j] === 0 ? 1 : 0
                curs[j] = curs[end - j] === 0 ? 1 : 0
                curs[end - j] = temp
            }
        }
    }
    return A
};
```
