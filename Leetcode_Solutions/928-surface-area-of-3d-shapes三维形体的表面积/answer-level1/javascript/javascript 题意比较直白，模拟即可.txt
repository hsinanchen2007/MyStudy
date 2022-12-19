方法比较简单，遍历即可。考虑格子数值为0 和边界的特殊情况。
格子底部和顶部一定是可以计入面积的（为0的时候除外），其他四个面跟四周的格子逐一比较大小，扣除被遮掩部分的面积
```
var surfaceArea = function(grid) {
    let res=0;
    for(let i=0;i<grid.length;++i){
        for(let j=0;j<grid[0].length;++j) {
            res+= gteS(grid,i,j);
        }   
    }
    return res;
};

//获取对应格子的表面积
var   gteS = function(grid,x,y){
        if(grid[x][y]==0) return 0;
        //顶部 和  底部 固定和为2
        let s = 2;
        var position = [[0,1],[0,-1],[1,0],[-1,0]];
        for(let i=0;i<position.length;++i){
            if(isIn(grid,x+position[i][0],y+position[i][1])){
                if(grid[x][y]-grid[x+position[i][0]][y+position[i][1]]>0) s+=(grid[x][y]-grid[x+position[i][0]][y+position[i][1]]);
            } else s+=grid[x][y];
        }
        return s;   
}
    //是否在grid范围内
var isIn = function(grid,x,y){
    return x>=0 && x<grid.length && y>=0 && y<grid[0].length;
}
```
