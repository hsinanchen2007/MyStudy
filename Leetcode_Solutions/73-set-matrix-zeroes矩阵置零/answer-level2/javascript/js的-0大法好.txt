找到0就把行列设置成-0（好吧我就是作弊）
实际执行时间和内存其实差别不是很大...

```javascript []
var setZeroes = function(matrix) {
    let i, j;
    i = matrix.length;
    while(i--){
        j = matrix[i].length;
        while(j--){
            if(checkIsZero(i, j)){
                setZero(i, j);      
            }
        }
    }
    
    function checkIsZero(i, j){
        return !matrix[i][j] && 1 / matrix[i][j] > 0;
    }
    function setZero(i, j){
        let k;
        k = 0;
        while(k < matrix.length){
            matrix[k][j] = matrix[k][j] ? -0 : matrix[k][j];
            k++;
        }
        k = 0;
        while(k < matrix[i].length){
            matrix[i][k] = matrix[i][k] ? -0 : matrix[i][k];
            k++;
        }
    }
};
```