### 解题思路
row设置为数组宽度，col设置为数组第一项的宽度，双循环遍历

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var transpose = function(A) {
    //边缘情况
    const row = A.length
    const col = A[0].length
    let res = Array.from({ length: col }, () => [])

    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            res[j][i] = A[i][j]
        }
    }

    return res
    

    //高端做法
    // return A[0].map((_, idx) => {
    //     return A.map(row => row[idx])
    // })
};
```