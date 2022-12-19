### 解题思路
看成纵向的每一列旋转~就完事了

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let N = matrix.length
    for(let i=0;i<N;i++) {
        let arr = []
        for(let j=0;j<N;j++) {
            arr.push(matrix[j][i])
        }
        matrix.push(arr.reverse())
    }
    matrix.splice(0,N)
    return matrix
};
```