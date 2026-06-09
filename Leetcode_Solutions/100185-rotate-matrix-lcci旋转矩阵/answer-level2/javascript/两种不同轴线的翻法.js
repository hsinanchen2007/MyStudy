
- 第一种
    
``` javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    for (let i = 0; i < matrix.length; i++) {
      for (let j = i; j < matrix.length; j++) {
          [matrix[j][i],matrix[i][j]] = [matrix[i][j],matrix[j][i]]
      }
    }
    for (let i = 0; i < matrix.length; i++) {
      for (let j = 0; j < matrix.length / 2; j++) {
          [matrix[i][j],matrix[i][matrix.length - j - 1]] = [matrix[i][matrix.length - j - 1],matrix[i][j]]
      }
    }
    return matrix
};
```


- 第二种

``` javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    for(i = 0; i < matrix.length; i++){
        for(j = 0 ; j < matrix.length - i; j++){
            [matrix[i][j],matrix[matrix.length - 1 -j][matrix.length - 1 -i]] = [matrix[matrix.length - 1 -j][matrix.length - 1 -i],matrix[i][j]]
        }
    }
    for(i = 0; i < matrix.length / 2; i++){
        for(j = 0; j <matrix.length; j++){
            [matrix[i][j],matrix[matrix.length - i - 1][j]] = [matrix[matrix.length - i - 1][j],matrix[i][j]]
        }
    }
    return matrix
};
```