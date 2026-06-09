![64.最小路径和.png](https://pic.leetcode-cn.com/e1dace91ff1fd4dd465f293126f1dede60562506a89348e8730cc9518a0561d3-64.%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.png)


![64.最小路径和.jpg](https://pic.leetcode-cn.com/a9f349197642d193f2922085f549c4b257acec6438302ce08a26e1986c2f23c1-64.%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.jpg)


```
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
     let m = grid.length,n = grid[0].length;
    if(m == 0 || n == 0){
        return 0;
    }
    if(m == 1 && n == 1){
        return grid[0][0];
    }
    
    let start = new Array(m);
    for(let i=0;i<m;i++){
        start[i] = new Array(n);
    }
    start[0][0] = grid[0][0];
    //列和行先加上前一个元素
    for(let i=1;i<m;i++){
        start[i][0] = start[i-1][0] + grid[i][0]; 
    }
    for(let i=1;i<n;i++){
        start[0][i] = start[0][i-1] + grid[0][i]; 
    }

    for(let i=1;i<m;i++){
        for(let j=1;j<n;j++){
            start[i][j] = Math.min(start[i-1][j],start[i][j-1]) + grid[i][j];
        }
    }
    console.log(start);
    return start[m-1][n-1];
};
```
