能够遮挡正方形表面积的情况只跟之前已放置的方块有关，因此这里在循环过程，只去寻找之前已经放置的的`[i-1, j]`和`[i, j-1]`位置的方块，两块被遮挡的面积取它的交集，即最小值。并且这里被遮挡都是属于两个方块，因此要乘以个2，具体看代码：

```javascript
var surfaceArea = function(grid) {
    let res = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[ i ].length; j++) {
            // 若当前没有方块直接跳过
            if (grid[ i ][ j ] === 0) continue;
            // 上下面积和方块个数的4周面积
            res += (4 * grid[ i ][ j ] + 2);
            if (j >= 1) {
                res -= 2 * Math.min(grid[ i ][ j - 1 ], grid[ i ][ j ]);
            }
            if (i >= 1) {
                res -= 2 * Math.min(grid[ i - 1 ][ j ], grid[ i ][ j ]);
            }
        }
    }
    return res;
};
```
