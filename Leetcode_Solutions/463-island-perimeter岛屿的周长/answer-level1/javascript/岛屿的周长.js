**思路:**

数学推理：`周长=个数*4-重合边*2`； 计算个数和重合边。

遍历遇到陆地的时候，【x>0&&y>0时】顺便查看它前面和上面是否也是陆地，是的话边长需要-2

```js
var islandPerimeter = function(grid) {
    let count = 0;
    for (let i = 0; i < grid.length; i++) {
        for(let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === 1) {
                count += 4;
                // 上面
                if (i > 0 && grid[i-1][j] == 1) {
                    count -= 2
                }
                // 前面
                if (j > 0 && grid[i][j-1] == 1) {
                    count -= 2;
                }
            }
        }
    }
    return count;
};
```

