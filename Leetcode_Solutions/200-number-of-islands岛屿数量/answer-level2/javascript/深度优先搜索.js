### 解题思路
重点是与自己相连的岛屿都是一个，所以要把周围的变成0
所有的点都循环一遍
深度优先搜索来扫清1周围的1

### 代码

```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    if(grid.length ==0) return 0
    let all = 0;
    let size = grid[0].length
    for(let r = 0; r < grid.length; r++){
        for(let l = 0; l < size; l++){
            let temp = grid[r][l];
            if(temp == '1'){
               all = all +1;
               grid = dfs(grid,r,l);
            }
        }
    }
    return all
};

var dfs = function(grid ,r, l){
  grid[r][l] = '0'
  if(grid.length >(r +1) && grid[r+ 1][l] == '1') {dfs(grid ,r+1, l)}
  if((r -1) >=0 && grid[r- 1][l] =='1') {dfs(grid ,r-1, l)}
  if(grid[0].length >(l +1) && grid[r][l +1] =='1') {dfs(grid ,r, l +1)}
  if((l -1) >=0 && grid[r][l-1] =='1') {dfs(grid ,r, l-1)}

  return grid
}
```