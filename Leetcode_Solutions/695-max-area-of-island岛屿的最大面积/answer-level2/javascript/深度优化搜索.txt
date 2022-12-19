### 解题思路
该题的解法，我参照之前的臭橘子的广度优化搜素和树最长路径的深度优化搜索。深度优化搜索利用栈来解，递归解法可以实现栈的操作。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    // 声明4个方向上下左右
    var direct_1 = [1,0,-1,0];
    var direct_2 = [0,1,0,-1];
    var a = grid.length;
    var b = grid[0].length;
    var max = 0;
    var arr = [0];
    function getCont(p){
        var currx = p%b;
        var curry = ~~(p/b);
        var v = 1;

        for(var m =0;m<4;m++){
            var x =currx + direct_1[m];
            var y = curry + direct_2[m];
            if(x>=0 && x<b && y>=0 && y < a && grid[y][x] === 1) {
                grid[y][x] = 0;
                var newP = b*y + x;
                 arr[0] = arr[0] + 1;
                 getCont(newP);
            }
        }
    }
    for(var i= 0;i<a;i++){
        for(var j = 0;j<b;j++){
            var p = b*i +j;
            if(grid[i][j] === 1){
                grid[i][j] = 0;
                arr[0] = 1;
                 getCont(p);
                max = Math.max(max,arr[0]);
            }
            arr[0] = 0;
        }
    }
return max;

};
```