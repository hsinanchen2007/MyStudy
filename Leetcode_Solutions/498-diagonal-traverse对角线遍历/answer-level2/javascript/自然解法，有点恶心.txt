```
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
let ans = []
var findDiagonalOrder = function(matrix) {
    ans = []
    go(matrix, 0, 0, 1)
    return ans
};
// dir -1是向下， 1是向上
function go(matrix, i, j, dir) {
    // 在范围内的才能加
    if((i > -1) && (i < matrix.length) && (j > -1) && (j < matrix[0].length)) {
        ans.push(matrix[i][j])
    } else return
    // 如果当前方向往上
    if(dir === 1) {
        // 如果不能往上
        if(i - 1 < 0) {
            j++
            if(j === matrix[0].length) {
                j--
                i++
                if(i === matrix.length) return
                go(matrix, i, j--, -1)
            }else go(matrix, i, j, -1)
        }else {
            j++
            if(j === matrix[0].length) {
                j--
                i++
                if(i === matrix.length) return
                go(matrix, i, j ,-1)
            } else go(matrix, --i, j, 1)

        }
    } else if(dir === -1) {
        if(j - 1 === -1) {
            i++
            if(i === matrix.length) {
                i--
                j++
                if(j === matrix[0].length) return
                go(matrix, i, j, 1)
            } else go(matrix, i, j, 1)
        } else {
            i++
            if(i === matrix.length) {
                i--
                j++
                if(j === matrix[0].length) return
                go(matrix, i, j ,1)
            } else go(matrix, i, --j, -1)
        }
    }
}

```
