### 解题思路
1. 先找到所有腐烂橘子位置并存储该位置
2. 将腐烂橘子出栈并搜索上下左右方向是否有新鲜橘子，有则入栈存储该位置
3. 直到栈空

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    var stack = [];
    var count = 0;
    for(var i = 0; i < grid.length; i++){
        for(var j = 0; j < grid[0].length; j++){
            if(grid[i][j] == 2){
                var list = [i, j];
                stack.push(list);
            }
            if(grid[i][j] == 1) count++;
        }
    }
    var times = 0;
    var flag = false;
    while(stack.length){
        var len = stack.length;
        for(var i = 0; i < len; i++){
            var item = stack.shift();
            var x = item[0];
            var y = item[1];
            if(x > 0 && grid[x - 1][y] == 1){
                stack.push([x - 1, y]);
                grid[x - 1][y] = 2;
                flag = true;count--;
            }
            if(x < grid.length - 1 && grid[x + 1][y] == 1){
                stack.push([x + 1, y]);
                grid[x + 1][y] = 2;
                flag = true;count--;
            }
            if(y < grid[0].length - 1 && grid[x][y + 1] == 1){
                stack.push([x, y + 1]);
                grid[x][y + 1] = 2;
                flag = true;count--;
            }
            if(y > 0 && grid[x][y - 1] == 1){
                stack.push([x, y - 1]);
                grid[x][y - 1] = 2;
                flag = true;count--;
            }
        }
        if(flag){
            times++;
            flag = false;
        }
    }
    if(!times && !count) return 0;
    return (times && !count) ? times : -1;
};
```