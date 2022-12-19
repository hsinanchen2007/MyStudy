### 解题思路
此处撰写解题思路

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
    //  行数
    const rowNum = matrix.length;
    // 列数
    const columnNum = matrix[0].length;
    let row = 0;
    let column = columnNum - 1;
    while(row < rowNum && column >= 0) {
        if(matrix[row][column] > target) {
            column --;
        } else if(matrix[row][column] < target) {
            row ++;
        } else if(matrix[row][column] === target) {
            targetFound = true;
            break;
        }
    }
    return targetFound;
};

```