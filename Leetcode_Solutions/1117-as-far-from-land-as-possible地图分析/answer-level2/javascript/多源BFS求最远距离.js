### 解题思路
1.一开始，我们找出所有陆地格子，将它们放入队列，作为第 0 层的结点。
2.然后进行 BFS 遍历，每个结点的相邻结点可能是上、下、左、右四个方向的结点，注意判断结点位于网格边界的特殊情况。
3.当遍历结束时，当前的遍历层数就是海洋格子到陆地格子的最远距离。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    var result=-1; //距离
    var land=[];//存放陆地的队列
    var row = grid.length;//行数
    var col = grid[0].length;//列数
    for(var i=0;i<row;i++){ // 所有陆地入队
        for(var j=0;j<col;j++){
            if(grid[i][j]==1){
                land.push([i,j]);
            }
        }
    }
    //全是海洋或者陆地
    if(land.length==0 || land.length == row*col){return -1;}
    //对每一块陆地进行BFS，对每一块遍历过的海洋标记成陆地
    while(land.length>0){
        var size=land.length;//记录当前层陆地的个数
        while(size>0){
            size--;
            var cur=land.shift();//第一个入队的陆地
            //四个方向
            var directions=[[-1,0],[0,1],[1,0],[0,-1]];
            for(var i=0;i<4;i++){
                var r = cur[0] + directions[i][0];
                var c = cur[1] + directions[i][1];
                //越界，跳过此方向
                if(r<0 || r>col-1 || c<0 || c>row-1 || grid[r][c]==1){
                    continue;
                }
                //如果是海洋，标记为陆地，加入到队列中，距离＋1
                if(grid[r][c]==0){
                    grid[r][c]=1;
                    land.push([r,c]);
                }
            }
        }
        result++;
    }
    return result;
};
```