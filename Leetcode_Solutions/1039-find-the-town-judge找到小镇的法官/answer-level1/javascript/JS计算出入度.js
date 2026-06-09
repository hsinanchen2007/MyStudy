# 思路
遍历并计算出度与入度。找到满足入度为N-1且出度为0的标记

# 代码
```
/**
 * @param {number} N
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(N, trust) {
    var inDegree = new Array(N);
    var outDegree = new Array(N);
    
    for(var i = 0; i < N; i++) {
        inDegree[i] = 0;
        outDegree[i] = 0;
    }
    
    
    for(var i = 0; i < trust.length; i++) {
        inDegree[trust[i][1] - 1]++;
        outDegree[trust[i][0] - 1]++;
    }
    
    
    for(var i = 0; i < N; i++) {
        if ((inDegree[i] == (N - 1)) && 
             (outDegree[i] == 0)) {
            return (i + 1);
        }
    }
    
    return -1;
    
};
```
