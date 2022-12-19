
# m+n空间复杂度
```
var setZeroes = function(matrix) {
    let rowSet = new Set();
    let colSet = new Set();
    let rowLen = matrix.length
    let colLen = matrix[0].length;
    for(let i = 0;i<rowLen;i++){
        for(let j = 0;j<colLen;j++){
            if(matrix[i][j] == 0){
                rowSet.add(i);
                colSet.add(j);
            }
        }
    }
    for(let i = 0;i<rowLen;i++){
        for(let j = 0;j<colLen;j++){
            if(rowSet.has(i)||colSet.has(j)){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
};
```
# 常数空间复杂度
```
var setZeroes = function(matrix) {
    let rowLen = matrix.length
    let colLen = matrix[0].length;
    for(let i = 0;i<rowLen;i++){
        for(let j = 0;j<colLen;j++){
            if(matrix[i][j] == 0){
               for(let rowI = 0;rowI<rowLen;rowI++){
                    if(matrix[rowI][j] != 0){
                       matrix[rowI][j] = true;
                    }
                }
                for(let colI = 0;colI<colLen;colI++){
                    if(matrix[i][colI] != 0){
                       matrix[i][colI] = true;
                    }
                }
            }
        }
    }
    for(let i = 0;i<rowLen;i++){
        for(let j = 0;j<colLen;j++){
            if( typeof(matrix[i][j]) == 'boolean'){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
};
```
# 巧设-0
看到js另一位同学的写法，对自己的写法改进了一下，其实本质上的时间空间开销区别都不大
![image.png](https://pic.leetcode-cn.com/e4a1ab366fc0cd277912d88e04edc2045dba437d56d69f0d33a52515a4f12c57-image.png)

```
var setZeroes = function(matrix) {
    let rowLen = matrix.length
    let colLen = matrix[0].length;
    for(let i = 0;i<rowLen;i++){
        for(let j = 0;j<colLen;j++){
            if(matrix[i][j] == 0&&1/matrix[i][j]>0){
               for(let rowI = 0;rowI<rowLen;rowI++){
                    if(matrix[rowI][j] != 0){
                       matrix[rowI][j] = -0;
                    }
                }
                for(let colI = 0;colI<colLen;colI++){
                    if(matrix[i][colI] != 0){
                       matrix[i][colI] = -0;
                    }
                }
            }
        }
    }
    return matrix;
};
```
