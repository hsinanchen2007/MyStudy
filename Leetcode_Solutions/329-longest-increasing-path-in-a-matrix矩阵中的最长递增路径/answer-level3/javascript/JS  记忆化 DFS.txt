### 解题思路
注释写的挺清楚了。
主要就是记忆化，不然一直超时很烦。
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number}
 */

var longestIncreasingPath = function(matrix) {
    if(matrix.length <= 0 || matrix[0].length <= 0){
        return 0;
    }
    let xlen = matrix.length, ylen = matrix[0].length;
    let visited = [];
    let max = 1;
    for(let i = 0; i < xlen; i++){
        visited[i] = [];
    }
    let ans = [] //用以存储每个点得最长长度
    for(let i = 0; i < xlen; i++){
        ans[i] = [];
    }
    function DFS(i, j, last){
        if(i >= 0 && i < xlen && j >= 0 && j < ylen && !visited[i][j]){
            //假设上下左右都走不通，所以上下左右都为count
            if(last < matrix[i][j]){
                if(ans[i][j]){
                    //记忆化，如果此处已经找到了一条路径，则直接返回
                    return ans[i][j]
                }
                visited[i][j] = true;
                //向上下左右都走一遍
                let top  = i > 0 ? DFS(i-1, j, matrix[i][j]) + 1 : 1;
                let left = j > 0 ?  DFS(i, j-1, matrix[i][j]) + 1 : 1;
                let bottom = i < xlen-1 ?  DFS(i+1, j, matrix[i][j]) + 1 : 1;
                let right = j < ylen-1 ?  DFS(i, j+1, matrix[i][j]) + 1 : 1;
                visited[i][j] = false;
                let nowMax = Math.max(right,Math.max(left, Math.max(top, bottom)));
                ans[i][j] = nowMax;
                return nowMax;
            }
            return 0;
        } 
        return 0;
    }
    for(let i = 0; i < xlen; i++){
        for(let j = 0; j < ylen; j++){
            if(!ans[i][j]){
                ans[i][j] =  DFS(i, j, -1);
                max = Math.max(max, ans[i][j])
            }
        }
    }
    return max;
};
```