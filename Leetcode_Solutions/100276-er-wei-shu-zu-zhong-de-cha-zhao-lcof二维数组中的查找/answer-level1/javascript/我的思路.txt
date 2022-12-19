### 解题思路
按行遍历，大于target则直接返回false，等于则返回true，小于遍历该行。
    找到等于的返回true，找不到则continue
按行遍历完，返回false

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    for(let i=0;i<matrix.length;i++){
        if(matrix[i][0]<target)
            for(let j=0;j<matrix[i].length;j++){
                if(matrix[i][j]==target)
                    return true;
                else
                    continue;
            }
        if(matrix[i][0]==target)
            return true;
        if(matrix[i][0]>target)
        return false;           
    }
    return false;
};
```