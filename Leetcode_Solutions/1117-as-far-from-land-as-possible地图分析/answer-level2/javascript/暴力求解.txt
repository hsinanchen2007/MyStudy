1：找出陆地和海洋的坐标
2：遍历求得海洋到达所有陆地的最小距离
3：找到所有最小距离当中的最大值

```javascript
var maxDistance = function(grid) {
    let maxDis = 0;
    let [island, ocean] = [[],[]];
    for(let i = 0; i < grid.length; i ++) {
        for(let j = 0; j < grid.length; j ++) {
            //遍历出来的每一个island坐标
            if(grid[i][j] === 1) island.push([i,j]);
            if(grid[i][j] === 0) ocean.push([i,j]);
        }
    }
    if(ocean.length === grid.length * grid.length) return -1;
    if(island.length === grid.length * grid.length) return -1;
    for(let x = 0; x < ocean.length; x ++) {
        let args = [];
        let abc;
        for(let y = 0; y < island.length; y ++) {
            abc = Math.abs(ocean[x][0] - island[y][0]) +
             Math.abs(ocean[x][1] - island[y][1]);  
            args.push(abc);

        }
        maxDis = Math.max(Math.min(...args), maxDis)
    }
    return maxDis;
};
```