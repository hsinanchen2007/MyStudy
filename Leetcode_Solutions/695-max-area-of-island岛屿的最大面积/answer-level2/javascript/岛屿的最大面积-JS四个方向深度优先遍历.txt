### 解题思路
![image.png](https://pic.leetcode-cn.com/c91dd76b31f2826c1effc797681d8d4e3e58bb5dbc22277bccef753b3d681830-image.png)

这数字有点不理想，我猜是服务器现在压力太大。不至于这么低。。。。思路同[地图分析](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/di-tu-fen-xi-jsduo-yuan-bfs-by-closertb/), 只是一个是BFS，一个时DFS。但思路一致，都是先找出所有岛屿，然后对每个岛屿向四个方向展开；
>步骤
 - 寻找所有陆地；
 - 遍历陆地，但遍历前，先检查是否已遍历过；
 - 四个方向深度遍历，然后求和；
 - 遍历结果和当前最大值比较；
 
### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(words) {
    const length = words.length;
    const rowLength = (words[0] && words[0].length) || 0;
    const cache = {};
    const queue = [];
    let total = 0;
    let max = -1;
    // 寻找所有的目标岛屿
    for (let i = 0; i < length; i++) {
        const row = words[i];
        for (let j = 0; j < rowLength; j++) {
            total++;
            if (row[j] === 1) {
                // cache[`${i}-${j}`] = 1;
                queue.push([i, j]);
            }
        }  
    }
    // 全是陆地或者海洋；
    if (queue.length === 0 || queue.length === total) {
        return queue.length;
    }

    // 深度遍历
    function dfs(source) {
        const [i, j] = source;
        const target = source.join('-');
        // 为0的点，或者已遍历过的，大小都返回0；
        if (words[i][j] === 0 ||  cache[target]) {
            return 0;
        }
        // 先预存一个值，免得形成死循环；
        cache[target] = 1;

        let x = i;
        let y = j - 1;
        let point = `${x}-${y}`;
        let arr = [0, 0, 0, 0];
        // 向左；遍历过的点不再遍历
        if (y > -1 && !cache[point]) {
            arr[0] = dfs([x, y]);
        }
        x = i;
        y = j + 1;
        point = `${x}-${y}`;
        // 向右；
        if (y < rowLength && !cache[point]) {
            arr[1] = dfs([x, y]);
        }
        x = i + 1;
        y = j;
        point = `${x}-${y}`;
         // 向下；
         if (x < length && !cache[point]) {
            arr[2] = dfs([x, y]);
        }
        x = i - 1;
        y = j;
        point = `${x}-${y}`;
        // 向上；
        if (x > -1 && !cache[point]) {
            arr[3] = dfs([x, y]);
        }
        cache[target] = arr.reduce((cur, pre) => cur + pre, 1);
        return cache[target];
    }

    for (let i = 0; i < queue.length; i++) {
       // 如果已经被遍历过，那就是给其他岛屿当过陪衬的，就无需遍历了；
       if (cache[queue[i].join('-')]) {
           continue;
       }
       max = Math.max(dfs(queue[i]), max);
    }
    return max;
};
```