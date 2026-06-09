### 解题思路
深度优先搜索基本思路
```
int check(参数)
{
    if(满足条件)
        return 1;
    return 0;
}
 
void dfs(int step)
{
        判断边界
        {
            相应操作
        }
        尝试每一种可能
        {
               满足check条件
               标记
               继续下一步dfs(step+1)
               恢复初始状态（回溯的时候要用到）
        }
}  
```


### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    var maxarea = 0;
    for(var i=0;i<grid.length;i++){
        for(var j=0;j<grid[0].length;j++){
            var area = Area(grid,i,j);
            maxarea = Math.max(maxarea,area);
        }
    }
    return maxarea;
};
function Area(grid,i,j){
    if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j]==0){
        return 0;
    }
    grid[i][j]=0
    var count;
    count = 1 + Area(grid,i-1,j) + Area(grid,i+1,j) + Area(grid,i,j-1) + Area(grid,i,j+1);
    return count;
}
```