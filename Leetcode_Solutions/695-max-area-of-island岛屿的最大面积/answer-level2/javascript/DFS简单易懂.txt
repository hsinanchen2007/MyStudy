### 解题思路
主要思路：
1、基础的i，j两层循环数组，每次碰到 1 就开始dfs
2、因为题目假设二维矩阵的四个边缘都被水包围着，所以边界上一定是0，所以当这五种条件下都返回0
```
if(i<0 || i>=x || j<0 || j>=y || grid[i][j]==0) return 0
```
3、如果grid[i][j]==1那么，先将本次访问节点grid[i][j]置零，表示本节点已经被访问过
4、dfs遍历其上下左右四个节点

注意：
1、为了避免重复计数，访问过的点置零即可
2、dfs的每一层返回的是本身计数 1 + 上下左右 的dfs返回值

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
        let x=grid.length,y=grid[0].length
        let max=0
        for(let i=0;i<x;i++){
            for(let j=0;j<y;j++){
                if(grid[i][j]==1) max = Math.max(max,countArea(grid, i, j, x, y))
            }
        }
    return max
};

let countArea = (grid, i, j, x, y) =>{
    if(i<0 || i>=x || j<0 || j>=y || grid[i][j]==0) return 0    
    // i>=x和j>=y 这两个判断条件是因为题目假设二维矩阵的四个边缘都被水包围着
    grid[i][j] = 0
    let count = 1
    count += countArea(grid, i+1, j, x, y)
    count += countArea(grid, i-1, j, x, y)
    count += countArea(grid, i, j+1, x, y)
    count += countArea(grid, i, j-1, x, y)
    return count
}
```