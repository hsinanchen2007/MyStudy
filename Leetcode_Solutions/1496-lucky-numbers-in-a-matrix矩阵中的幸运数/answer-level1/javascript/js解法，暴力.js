```
var luckyNumbers  = function(matrix) {
    if(!matrix.length) return [];
    // 找到所有行最小的
    let rowA = []
    for(let i = 0; i < matrix.length; i++){
        let min = Math.min(...matrix[i]);
        let colIndex = matrix[i].indexOf(min);
        rowA.push(min)
    }
    // 找到所有列最大的数
    let colA = []
    for(let j = 0; j < matrix[0].length; j++){
        let max = Number.MIN_SAFE_INTEGER;
        for(let i = 0; i < matrix.length; i++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
        colA.push(max);
    }
    // 求两个数组的交集
    let res = []
    for(let i = 0; i < rowA.length; i++){
        for(let j = 0; j < colA.length; j++){
            if(rowA[i] === colA[j]){
                res.push(rowA[i]);
                break;
            }
        }
    }
    return res;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，
希望对前端同行找工作面试、修炼算法内功有帮助。
前端算法交流群：621067993