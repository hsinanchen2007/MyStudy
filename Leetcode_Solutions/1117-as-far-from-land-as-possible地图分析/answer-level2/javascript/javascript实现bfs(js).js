题目分析

相信对于Tree的BFS大家都已经轻车熟路了：要把root节点先入队，然后再一层一层的无脑遍历就行了。

对于图的BFS也是一样滴～ 与Tree的BFS区别如下：
1、tree只有1个root，而图可以有多个源点，所以首先需要把多个源点都入队。
2、tree是有向的因此不需要标志是否访问过，而对于无向图来说，必须得标志是否访问过！
并且为了防止某个节点多次入队，需要在入队之前就将其设置成已访问！

这是一道典型的BFS基础应用，为什么这么说呢？
因为我们只要先把所有的陆地都入队，然后从各个陆地同时开始一层一层的向海洋扩散，那么最后扩散到的海洋就是最远的海洋！
并且这个海洋肯定是被离他最近的陆地给扩散到的！

你可以想象成你从每个陆地上派了很多支船去踏上伟大航道，踏遍所有的海洋。每当船到了新的海洋，就会分裂成4条新的船，向新的未知海洋前进（访问过的海洋就不去了）。如果船到达了某个未访问过的海洋，那他们是第一个到这片海洋的。很明显，这么多船最后访问到的海洋，肯定是离陆地最远的海洋。


```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    const dx = [0, 0, 1, -1];
    const dy = [1, -1, 0, 0];
    const len = grid.length;
    const queue = [];
    for (let i = 0; i < len; i++) {
        for (let j = 0; j < len; j++) {
            if (grid[i][j] === 1) {
                queue.push([i, j]);
            }
        }
    }

    let point = null;
    let hasOcean = false;
    while (queue.length) {
        point = queue.shift();
        const x = point[0];
        const y = point[1];
        for (let i = 0; i < 4; i++) {
            const newX = x + dx[i];
            const newY = y + dy[i];
            if (newX < 0 || newX >= len || newY < 0 || newY >= len || grid[newX][newY]) {
                continue;
            }
            queue.push([newX, newY]);
            grid[newX][newY] = grid[x][y] + 1;
            hasOcean = true;
        }
    }
    if (!hasOcean || !point) {
        return -1;
    }
    return grid[point[0]][point[1]] - 1;
};
```