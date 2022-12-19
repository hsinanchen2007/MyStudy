```js
var transpose = function(A) {
    let arr = []
    for (let j = 0; j < A[0].length; j++) {
        let temp = [];
        for (let i = 0; i < A.length; i++) {
            temp.push(A[i][j])
        }
        arr.push(temp)
    }
    return arr
};
```

