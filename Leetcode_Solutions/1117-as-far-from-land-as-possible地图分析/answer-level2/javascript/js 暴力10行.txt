js 暴力10行解决战斗
```js
var maxDistance = function(grid) {
    const record = {land: [], sea: []};
    for(let i = 0; i < grid.length; i++) {
        for(let j = 0; j < grid[0].length; j++) {
            record[grid[i][j] ? 'land' : 'sea'].push([i, j]) // 陆地区域
        }
    }
    if (!record.land.length || !record.sea.length) return -1;
    return record.sea.reduce(
        (max, [i, j]) => Math.max(max, record.land.reduce(
            (min, [x, y]) => Math.min(Math.abs(x - i) + Math.abs(y - j), min), Infinity)), -1);
};
```
