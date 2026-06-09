```js
var commonChars = function(A) {
    let res = []
    for (let i = 0; i < A[0].length; i++) {
        let flag = true
        for (let j = 1; j < A.length; j++) {
            let index = A[j].indexOf(A[0][i])
            if (index !== -1) {
                A[j] = A[j].substr(0, index) + A[j].substr(index + 1)
            } else {
                flag = false
                break
            }
        }
        if (flag) {
            res.push(A[0][i])
        }
    }
    return res
};
```
