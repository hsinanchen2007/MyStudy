### 解题思路
获取当前腐烂橘子 -> 感染周围橘子, 同时获取新的被感染橘子, 时间+1 -> 继续感染
没有新的被感染橘子后检查是否有新鲜橘子 //此处可以优化为记录新鲜橘子

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    //获取当前所有腐烂橘子的坐标
    function getRot(grid){
        let positionList = []
        for(let i = 0; i < grid.length; i++){
            for(let j = 0; j < grid[i].length; j++ ){
                if(grid[i][j] === 2){
                    positionList.push([i, j])
                }
            }
        }
        return positionList
    }
    //执行一次感染, 同时返回新被感染的橘子的坐标
    function rot(grid, positionList){
        let nextPositionList = []
        positionList.forEach(([i, j]) => {
            if(grid[i - 1] !== undefined){
                if(grid[i - 1][j] === 1){
                    nextPositionList.push([i - 1, j])
                    grid[i - 1][j] = 2
                }
            }
            if(grid[i + 1] !== undefined){
                if(grid[i + 1][j] === 1){
                    nextPositionList.push([i + 1, j])
                    grid[i + 1][j] = 2
                }
            }
            if(grid[i][j - 1] !== undefined){
                if(grid[i][j - 1] === 1){
                    nextPositionList.push([i, j - 1])
                    grid[i][j - 1] = 2
                }
            }
            if(grid[i][j + 1] !== undefined){
                if(grid[i][j + 1] === 1){
                    nextPositionList.push([i, j + 1])
                    grid[i][j + 1] = 2
                }
            }
        })
        return nextPositionList
    }
    //查询当前是否有新鲜的橘子
    function checkGrid(grid){
        let flag = false
        for(let i = 0; i < grid.length; i++){
            if(flag){
                break
            }
            for(let j = 0; j < grid[i].length; j++ ){
                if(grid[i][j] === 1){
                    flag = true
                    break
                }
            }
        }
        return flag
    }

    let time = -1
    let nowRot = getRot(grid)
    while(nowRot.length){
        nowRot = rot(grid, nowRot)
        time += 1
    }
    if(checkGrid(grid)){
        return -1
    }else{
        return time > 0 ? time : 0
    }
};
```