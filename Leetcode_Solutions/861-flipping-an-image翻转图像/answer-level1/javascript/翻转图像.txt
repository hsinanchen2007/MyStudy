*法一*

```js
var flipAndInvertImage = function(A) {
    let res = []
    for (let i = 0; i < A.length; i++) {
        let len = A[i].length;
        let halfLen = parseInt(len / 2);
        let arr = [];
        for (let j = 0; j < halfLen; j++) {
            let temp = A[i][j];
            A[i][j] = A[i][len-j-1];
            A[i][len-j-1] = temp;
        }
        for (let j = 0; j < len; j++) {
            if (A[i][j] === 0) {
                arr.push(1)
            } else {
                arr.push(0)
            }
        }
        res.push(arr)
    }
    return res
};
```

*法二*

```js
var flipAndInvertImage = function(A) {
    return A.map((item) => {
        return item.reverse().map((num) => {
            return num === 1 ? 0 : 1
        })
    });
};
```

