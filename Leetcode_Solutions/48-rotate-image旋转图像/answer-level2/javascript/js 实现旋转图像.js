思路：
规律其实就是先将矩阵转置，再将每一行倒序，如下：
1 2 3
4 5 6
7 8 9
转置后的结果是：
1 4 7
2 5 8
3 6 9
再每一行倒序，结果是
7 4 1
8 5 2
9 6 3

代码如下：
```
var rotate = function(matrix) {
    for(let i = 0; i < matrix.length; i++){
        const row = matrix[i];
        for (let j = i; j < row.length; j++){
            const temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    matrix.forEach(row=> row.reverse())
};
```
如有错误，欢迎指教
