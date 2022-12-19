深度优先搜索，会将所有节点的下属相邻节点遍历，存在大量重复节点的计算，故会产生超时~
```
var minimumTotal = function(triangle) {
    let limit = triangle.length;
    let helper = function(i,j){
        if((i+1) == limit) return triangle[i][j];
        return Math.min(helper(i+1,j),helper(i+1,j+1))+triangle[i][j];
    }
    return helper(0,0);
};
```
动态规划
```
var minimumTotal = function(triangle) {
    let dp = [];
    let y = triangle.length;
    for(let i = y-1;i>=0;i-- ){
        dp[i] = [];
        let x = triangle[i].length;
        for(let j = 0;j<x;j++){
            if((i+1) == y) dp[i][j] = triangle[i][j];
            else dp[i][j] = Math.min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        }
    }
    return dp[0][0];
};
```
