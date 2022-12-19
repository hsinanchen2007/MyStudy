### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let maxLength = 0;
    let visitedNode = [];
     /*初始化访问数组（二维数组） */
    for(let i = 0; i < grid.length; i++){
        visitedNode[i] = [];
        for(let j = 0; j < grid[i].length; j++){
            visitedNode[i][j] = 0;
        }
    }
    /*节点是否被访问过 */
    function isVisited(i, j){
        return visitedNode[i][j] === 1;
    }
    /*往四个方向进行递归寻找 */
    function findNeighbors(i, j){
        let landLength = 0;
        if(grid[i][j] === 1){
            landLength = 1;
            if(isVisited(i, j)){
                return 0;
            }else{
                visitedNode[i][j] = 1;
            }
            if(i > 0){
                landLength += findNeighbors(i-1, j);
            }
            if(i < grid.length - 1){
                landLength += findNeighbors(i + 1, j);
            }
            if(j > 0){
                landLength += findNeighbors(i, j - 1);
            }
            if(j < grid[i].length - 1){
                landLength += findNeighbors(i, j + 1);
            }
        }
        
        return landLength;
    }

    for(let i = 0; i < grid.length; i++){
        for(let j = 0; j < grid[i].length; j++){
            let landLength = findNeighbors(i, j);
            if(landLength > maxLength){
                maxLength = landLength;
            }
        }
    }

    return maxLength;

};
```