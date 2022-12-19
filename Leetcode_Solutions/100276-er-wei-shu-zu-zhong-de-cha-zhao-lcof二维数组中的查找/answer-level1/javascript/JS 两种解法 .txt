## 一、暴力解法

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    const rowLen = matrix.length;
    if(!rowLen){
        return false
    }
    const colLen = matrix[0].length;
    for(let i=0;i<rowLen;i++){
        for(let j=0;j<colLen;j++){
            if(matrix[i][j] === target){
                return true
            }
        }
    }
    return false
};
```
时间复杂度：O(n^2)
空间复杂度：O(1)

## 二、二分查找解法

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    const rowLen = matrix.length;
    if(!rowLen){
        return false
    }
    const colLen = matrix[0].length;
    let row = 0,
        col = colLen-1;
    while(row<=rowLen-1 && col>=0){
        if(matrix[row][col]<target){
            row++
        }else if(matrix[row][col]>target){
            col--
        }else{
            return true
        }
    }
    return false
};
```
时间复杂度：O(M+N) 
空间复杂度：O(1)