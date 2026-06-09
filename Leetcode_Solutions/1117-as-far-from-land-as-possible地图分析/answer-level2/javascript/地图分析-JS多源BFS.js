### 解题思路
![image.png](https://pic.leetcode-cn.com/fb202645c1dcc349c99d374f7592105a3c596b8512c0dd93bc3ddbf98692460c-image.png)

像我这么菜，顶多知道BFS，肯定不会听过什么叫多源啊；看了甜姐和一个老哥的题解，恍然大悟：

[甜姐的通俗易懂](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/jian-dan-java-miao-dong-tu-de-bfs-by-sweetiee/);
[老哥的原理剖析](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/zhen-liang-yan-sou-huan-neng-duo-yuan-kan-wan-miao/);  

看完上面两位大人的图，解题思路就出来了：
 - 寻找多源；
 - 多源的广度优先遍历，记住，是广度；
 - 遍历时，不断与当前最大值比较，并更新；

### 代码
```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    // 数组行数；
    const length = grid.length;
    // 数组列数；
    const rowLength = (grid[0] && grid[0].length) || 0;
    // 存放遍历结果，避免重复遍历
    const cache = {};
    const queue = [];
    let total = 0;
    let max = -1;
    for (let i = 0; i < length; i++) {
        const row = grid[i];
        for (let j = 0; j < rowLength; j++) {
            total++;
            if (row[j] === 1) {
                cache[`${i}-${j}`] = 1;
                queue.push([i, j]);
            }
        }  
    }
    // 全是陆地或者海洋；
    if (queue.length === 0 || queue.length === total) {
        return max;
    }
    // 只有未被遍历的点会在这里被遍历；
    function jgePoint(x, y, start, point) {
        cache[point] = start + 1; // 距离加1
        queue.push([x, y]); // 加入下一轮被遍历的点
        max = Math.max(max, cache[point]); // 看是否是最大值
        return;
    }

    // 四个方向依次遍历
    function bfs(source) {
        const [i, j] = source;
        const start = cache[source.join('-')];
        let x = i;
        let y = j - 1;
        let point = `${x}-${y}`;
        // 向左；
        if (y > -1 && !cache[point]) {
            jgePoint(x, y, start, point);
        }
        x = i;
        y = j + 1;
        point = `${x}-${y}`;
        // 向右；
        if (y < rowLength && !cache[point]) {
            jgePoint(x, y, start, point);
        }
        x = i + 1;
        y = j;
        point = `${x}-${y}`;
         // 向下；
         if (x < length && !cache[point]) {
            jgePoint(x, y, start, point);
        }
        x = i - 1;
        y = j;
        point = `${x}-${y}`;
        // 向上；
        if (x > -1 && !cache[point]) {
            jgePoint(x, y, start, point);
        }
    }
    // 广度优先遍历；
    while(queue.length) {
        const temp = queue.slice();
        queue.length = 0;
        for (let i = 0; i < temp.length; i++) {
            bfs(temp[i]);
        }
    } 
    // 为什么要减一，因为前面为了好判断，是从1开始累加的
    return max - 1;
};
```