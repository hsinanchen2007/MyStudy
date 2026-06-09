![a7860d78711ff1784fcc0e8a614546ef.png](https://pic.leetcode-cn.com/87320c210ed2fc9b3ebd113c6f6dda85eb21ec9702d169fde9e8e99d95227004-a7860d78711ff1784fcc0e8a614546ef.png)

```javascript
var maxDistance = function(grid) {
    const sideLen = grid.length;
    let lands = [];
    let maxDist = -1;
    for (let i = 0; i < sideLen; i++) {
        for (let j = 0; j < sideLen; j++) {
            grid[i][j] === 1 && lands.push([i, j]);
        }
    }
    if (sideLen * sideLen === lands.length || 0 === lands.length) return -1;
    const dx = [1, 0, -1, 0];
    const dy = [0, 1, 0, -1];
    while (lands.length > 0) {
        let size = lands.length;
        while(size-- > 0) {
            let curLand = lands.shift();
            for (let n = 0; n < 4; n++) {
                let nx = curLand[0] + dx[n];
                let ny = curLand[1] + dy[n];
                if (nx < 0 || ny < 0 || nx >= sideLen || ny >= sideLen) continue;
                if (grid[nx][ny] === 0) {
                    grid[nx][ny] = 1;
                    lands.push([nx, ny]);
                }
            }
        }
        maxDist++;
    }
    return maxDist;
};
```

可以想象为陆地向海洋扩张
每次行动1个单元格（上下左右四方向扩张）
每扩张一次就把海洋标记位陆地
最后一次当所有海洋都被标记位陆地，则当前扩张步数则为所求

首先遍历二维数组将陆地点获取所有陆地点
外层循环条件为当陆地数组内有元素则循环，无元素表示所有海洋已标记为陆地
内部循环先获取当前需遍历陆地的总数
对每个陆地格四个方向进行扩张
如果为海洋则标记为陆地并且推入陆地数组用来下次循环扩张
最后所得步数即为最大曼哈顿距离