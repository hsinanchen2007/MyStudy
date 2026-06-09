简单的遍历加上适当的剪纸就可以通过这道题。
向大神们学习好的解法。
代码如下：
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    if(matrix.length == 0) return 0;
    let rows = matrix.length;
    let columns = matrix[0].length;
    let maxArea = 0;
    for(let i =0; i<matrix.length; i++) {
        for (let j =0; j < matrix[0].length; j++) {
            if(matrix[i][j] === 0 )
                continue;
            let sum = 0;
            for (let k = 0;i+k<rows && j+k<columns ;k++) {
                sum = calSum(matrix, i,j,k);
                if(sum>=(k+1)*(k+1)) {
                    maxArea = Math.max(maxArea, sum);
                }else {
                    break;
                }
            }
        }
    }
    return maxArea;
};

function calSum (matrix, i,j,k) {
    let sum = 0;
    for(let n =i; n<=i+k;n++) {
        for (let w = j; w<=j+k; w++) {
            sum = sum + parseInt(matrix[n][w]);
        }
    }
    return sum;
}