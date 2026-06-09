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
    if(matrix.length === 0){
        return false
    }
    let rows = matrix.length-1;
    let cols = matrix[0].length;
    let l = 0;
    let r = cols -1;
    while(l<=rows&&r>=0){
        if(matrix[l][r] === target){
            return true
        }else if(matrix[l][r] < target){
            l++;
        }else{
            r--
        }
    }
    return false
};
```