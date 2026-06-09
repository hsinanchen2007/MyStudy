### 解题思路
    // 题意
    // v  = grid[i][j]
    // [[2]]           表示在网格[0,0]位置放置2个立方体;
    // [[1,2],[3,4]]   表示在
    // 【[0,0]放1个,[0,1]放2个】,【[1,0]放3个,[1,1]放4个】
    // 注意二位数组值的变化，就可以发现是按什么规则来放的了，类推
    // [[1,1,1],[1,0,1],[1,1,1]]
    // 【[0,0]放1个,[0,1]放1个,[0,2]放1个】,【[1,0]放1个,[1,1]放0个...】...

    // 思路
    // 当 v > 0 时， 贡献上下2个面，四周v*4
    // 当 v > 1 时， 贡献上下2个面, 四周v*4
    // 当 v 上测有 v2 时，-Min(v,v2)*2
    // 同理，右侧v3 存在时，-Min(v,v3)*2

### 代码

```javascript

var surfaceArea = function(grid) {
    var sum = 0;
    var temp;
    for(var i = 0; i<grid.length;i++){
        for(var j =0; j < grid[i].length; j++){
            // 特殊情况排除
            if(grid[i][j] == 0){ continue }
            temp = 2 + grid[i][j]*4;
            // 校验平面纵向是否重叠
            if( (i-1)>-1 ){
                temp = temp - Math.min(grid[i-1][j],grid[i][j])*2;
            }
            // 校验平面横向是否重叠
            if((j-1)>-1){
                temp = temp - Math.min(grid[i][j-1],grid[i][j])*2;
            }
            sum +=temp;
        }
    }
    return sum;
};
```