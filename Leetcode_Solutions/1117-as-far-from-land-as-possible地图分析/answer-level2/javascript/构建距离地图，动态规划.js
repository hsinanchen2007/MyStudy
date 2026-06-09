### 解题思路
 * 创建一个新的地图，标出来地图上所有点到陆地的距离，如果本身是陆地0，海洋maxNumber
 * 给所有的点+1，向四周扩展，如果小于原来的举例，则替换
 * 重复这一步，len * 2次，所有的海洋都被覆盖
 * 返回最大值
### 代码

```javascript
/**
 * 创建一个新的地图，标出来地图上所有点到陆地的距离，如果本身是陆地0，海洋maxNumber
 * 给所有的点+1，向四周扩展，如果小于原来的举例，则替换
 * 重复这一步，len * 2次，所有的海洋都被覆盖
 * 返回最大值
 * 
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function (grid) {
    let max = 0;
    const len = grid.length;
    let dist = [];
    dist.length = len;
    //init
    for (let i = 0; i < len; i++) {
        dist[i] = [];
        dist[i].length = len;
        for (let j = 0; j < len; j++) {
            dist[i][j] = grid[i][j] === 1 ? 0 : Number.MAX_SAFE_INTEGER;
        }
    }


    for (let i = 0; i <= len * 2; i++) {
        extend(i);
    }

    for (let i = 0; i < len; i++) {
        for (let j = 0; j < len; j++) {
            max = Math.max(dist[i][j], max);
        }
    }
    if(max === Number.MAX_SAFE_INTEGER || max === 0) return -1;
    else return max;

    //距离 + 1
    //给距离陆地扩展
    function extend(n) {
        // const maxDist = len * 2;
        for (let i = 0; i < len; i++) {
            for (let j = 0; j < len; j++) {
                if (dist[i][j] === n) {
                    let newDist = dist[i][j] + 1;
                    //右
                    if (i < len - 1) {
                        dist[i + 1][j] = Math.min(dist[i + 1][j], newDist);
                    }
                    //左
                    if (i > 0) {
                        dist[i - 1][j] = Math.min(dist[i - 1][j], newDist);
                    }
                    //上
                    if (j > 0) {
                        dist[i][j - 1] = Math.min(dist[i][j - 1], newDist);
                    }
                    //下
                    if (j < len - 1) {
                        dist[i][j + 1] = Math.min(dist[i][j + 1], newDist);
                    }
                }
            }
        }
    }
};
```