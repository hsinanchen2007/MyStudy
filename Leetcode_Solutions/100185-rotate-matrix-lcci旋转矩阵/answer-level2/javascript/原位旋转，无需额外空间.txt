只需要遍历矩阵的1/4，对指定数字进行原位旋转即可
空间O(1)
```
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let n=matrix.length;
    let t=Math.ceil(n/2);
    for(let i=0;i<t;i++){

        for(let j=i;j<n-i-1;j++){
            let temp=matrix[i][j];
           
            matrix[i][j]=matrix[n-j-1][i];
            matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
            matrix[j][n-i-1]=temp;
        }
    } 
};
```

