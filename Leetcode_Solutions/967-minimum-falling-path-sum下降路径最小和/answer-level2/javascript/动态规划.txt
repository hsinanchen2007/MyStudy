
简单的讲就是每遍历一行找出与上一行之间的最小值
```
var minFallingPathSum = function(A) {
    const rowLen = A.length;
    const colLen = A[0].length;
    for(let i = 1; i < rowLen; i++) {
        for(let j =0; j <colLen; j++) {
            switch (true) {
                case j === 0:
                A[i][j] += Math.min(A[i-1][j], A[i-1][j+1])
                break;
                case j === colLen-1:
                A[i][j] += Math.min(A[i-1][j], A[i-1][j-1])
                break;
                default:
                A[i][j] += Math.min(A[i-1][j-1], A[i-1][j], A[i-1][j+1])
            }
        }      
    }
    return Math.min(...A[rowLen -1])
};
```
