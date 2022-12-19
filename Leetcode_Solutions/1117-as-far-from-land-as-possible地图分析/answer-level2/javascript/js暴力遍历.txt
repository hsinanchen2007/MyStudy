### 解题思路
1. 遍历一次获取所有的海洋和陆地地址为两个列表
2. 两个列表嵌套遍历，获得结果。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    const oceans = [];
    const lands = [];
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid.length; j++) {
            if (grid[i][j] === 0) {
                oceans.push([i,j]);
            } else {
                lands.push([i,j]);
            }
        }
    }
    if (oceans.length === 0 || lands.length === 0) return -1;
    let res = 0;
    oceans.forEach(item => {
        let mindis = Number.MAX_SAFE_INTEGER;
        lands.forEach(land => {
            dis = Math.abs(item[0] - land[0]) + Math.abs(item[1] - land[1]);
            if (dis < mindis) mindis = dis;
        })
        if (mindis > res) res = mindis;
    })
    return res;
};
```