### 从外向内遍历矩阵
[运用了js数学函数向上、向下取整等方法](https://www.cnblogs.com/Marydon20170307/p/8831055.html)

```
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let len = matrix[0].length;
    let n = Math.ceil(len / 2);
    // 第一层循环代表：(1)共有几层矩阵要旋转 (2)每一层起始的行坐标
    for(let i = 0; i < n; i++) {
        // 第二层循环代表：(1)每一层旋转矩阵的元素循环 (2)每次的列坐标
        for(let j = i; j < len - i -1; j++) {
                let tmp = matrix[j][len-i-1];
                matrix[j][len-i-1] = matrix[i][j];
                matrix[i][j] = matrix[len-j-1][i];
                matrix[len-j-1][i] = matrix[len-i-1][len-j-1];   
                matrix[len-i-1][len-j-1] = tmp;  
        }
    }   
    return matrix;
};
```
### 先矩阵转置再按行反转
```
var rotate = function(matrix) {
    // 矩阵的大小
    let len = matrix[0].length;
    // 共有几层需要旋转，向上取整
    let n = Math.ceil(len / 2);
    // 先矩阵转制，以矩阵左下半边为例，取不到最后一列和第一行，注意i,j的范围
    // 出错一：这样写错了，因为直接在这个循环中对行reverse了，所以行还是要取到len，否则最后一行无法reverse。
    // for(let j = 0; j < len-1; j++) {
    for(let j = 0; j < len; j++) {
        for(let i = j+1; i < len; i++){
            let tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
        // 列是外层循环，行是内层循环，因此此时第一行的值已重置
        // 列的索引可以当作行reverse的索引
        matrix[j].reverse();
    }
    
    return matrix;
};
```
