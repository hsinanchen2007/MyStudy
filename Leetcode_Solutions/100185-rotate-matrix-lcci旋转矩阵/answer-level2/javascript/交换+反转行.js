### 解题思路

旋转90°就是matrix[row][column]与matrix[column][row]交换后在将每一行翻转, 无法给出证明, 只是找规律发现的

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const l = matrix.length
    for(let i = 0; i < l; i ++) {
        for(let j = 0; j < l; j ++) {
            // 只交换一次, 否则就跟没交换一样了, 可以看作在对角线以上区域进行交换
            if(i < j) [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]]
        }
    }
    // 反转行, 实现90°旋转
    matrix.map(row => row.reverse())
};
```