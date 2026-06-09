### 解题思路
矩阵长(行数)为matrix.length,宽(列宽)为matrix[i].length

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    for(var i=0;i<matrix.length;i++){
        for(var j=0;j<matrix[i].length;j++){
            if(matrix[i][j]==target)
            return true;
        }
    }
    return false;
};
```