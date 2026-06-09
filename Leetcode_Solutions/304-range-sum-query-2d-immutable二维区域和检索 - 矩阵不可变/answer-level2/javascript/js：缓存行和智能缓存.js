根据官方的讲解，我复现出第三种和第四种方法

## 缓存行
将第i行的的下标从零到j的和保存到数组dp[i][j]中,调用sumRegion方法时，只需要累加dp[i][col2],row1<=i<=row2,减去dp[i][col1-1]即可

~~~js
var NumMatrix = function (matrix) {

    for (let i = 0; i < matrix.length; i++) {
        dp[i] = [];
        for (let j = 0; j < matrix[0].length; j++) {
            if (j === 0) {
                dp[i][0] = matrix[i][0];
            } else {
                dp[i][j] = dp[i][j - 1] + matrix[i][j];
            }
        }


    }
};

/**
 * @param {number} row1
 * @param {number} col1
 * @param {number} row2
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function (row1, col1, row2, col2) {
    let res=0;
    if(col1===0){
        for (let i = row1; i <= row2 ; i++) {
            res+=dp[i][col2];
        }
        return res;
    }
    for (let i = row1; i <= row2; i++) {
        res+=dp[i][col2]-dp[i][col1-1];
    }
    return res;
};
~~~

## 智能缓存
思路：dp[i][j]表示从（0,0）到（i,j）区域累计的和，
结果就是dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1]
~~~js
let dp = [];//缓存i行从0到j个数的和
var NumMatrix = function (matrix) {

    for (let i = 0; i < matrix.length; i++) {
        dp[i] = [];
        for (let j = 0; j < matrix[0].length; j++) {
            if (j === 0) {
                dp[i][0] = matrix[i][0];
            } else {
                dp[i][j] = dp[i][j - 1] + matrix[i][j];
            }
        }
    }
    for (let i = 1; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            dp[i][j]=dp[i-1][j]+dp[i][j];
        }
    }
    console.log(dp);
};

/**
 * @param {number} row1
 * @param {number} col1
 * @param {number} row2
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function (row1, col1, row2, col2) {

    if(row1===0 && col1===0){
        return dp[row2][col2];
    }
    else if(row1===0){
        return dp[row2][col2]-dp[row2][col1-1];
    }
    else if(col1===0){
        return dp[row2][col2]-dp[row1-1][col2];
    }

    return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
};

~~~