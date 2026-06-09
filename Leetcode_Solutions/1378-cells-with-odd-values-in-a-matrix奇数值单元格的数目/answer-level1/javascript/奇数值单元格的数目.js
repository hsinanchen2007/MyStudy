

### 代码

```javascript
var oddCells = function(n, m, indices) {
    let arr = []
    let res = 0
    for (let i = 0; i < n; i++) {
        let temp = []
        for (let j = 0; j < m; j++) {
            temp[j] = 0
        }
        arr.push(temp)
    }
    for (let i = 0; i < indices.length; i++) {
        let row = indices[i][0]
        let col = indices[i][1]
        arr[row].forEach((item, index) => {
            arr[row][index] += 1
        })
        arr.forEach((item, index) => {
            arr[index][col] += 1
        })
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (arr[i][j] % 2 == 1) {
                res++
            }
        }
    }
    return res
};
```