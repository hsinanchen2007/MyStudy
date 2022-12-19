### 解题思路
遍历循环二维数组，找到目标则置标识符为true返回

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    let targetFound = false;
    if(matrix === null || matrix.length === 0 || matrix[0].length === 0) return targetFound;
    for(let i = 0;i < matrix.length;i ++) {
        for(let j = 0;j < matrix[i].length;j ++) {
           if(target === matrix[i][j]) {
               targetFound = true;
           }
        }
    }
    return targetFound;
};

```