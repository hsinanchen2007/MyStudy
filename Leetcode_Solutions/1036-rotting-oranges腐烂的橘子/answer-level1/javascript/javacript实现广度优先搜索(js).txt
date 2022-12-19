方法二：多源广度优先搜索

思路:

观察到对于所有的腐烂橘子，其实它们在广度优先搜索上是等价于同一层的节点的。

假设这些腐烂橘子刚开始是新鲜的，而有一个腐烂橘子(我们令其为超级源点)会在下一秒把这些橘子都变腐烂，而这个腐烂橘子刚开始在的时间是 -1 ，那么按照广度优先搜索的算法，下一分钟也就是第 0 分钟的时候，这个腐烂橘子会把它们都变成腐烂橘子，然后继续向外拓展，所以其实这些腐烂橘子是同一层的节点。那么在广度优先搜索的时候，我们将这些腐烂橘子都放进队列里进行广度优先搜索即可，最后每个新鲜橘子被腐烂的最短时间其实是以这个超级源点的腐烂橘子为起点的广度优先搜索得到的结果。

为了确认是否所有新鲜橘子都被腐烂，可以记录一个变量表示cnt当前网格中的新鲜橘子数，广度优先搜索的时候如果有新鲜橘子被腐烂，则 cnt-=1 ，最后搜索结束时如果 cnt 大于 0 ，说明有新鲜橘子没被腐烂，返回 −1 ，否则返回所有新鲜橘子被腐烂的时间的最大值即可，也可以在广度优先搜索的过程中把已腐烂的新鲜橘子的值由 1 改为 2，最后看网格中是否由值为 1 即新鲜的橘子即可


```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    const queue = [];
    const hashMap = {};
    const iLen = grid[0].length;
    const jLen = grid.length;
    for (let i = 0; i < iLen; i++) {
        for (let j = 0; j < jLen; j++) {
            if (grid[j][i] === 2) {
                const code = j * iLen + i;
                queue.push(code);
                hashMap[code] = 0;
            }
        }
    }

    const arrI = [0, 1, 0, -1];
    const arrJ = [-1, 0, 1, 0];
    let time = 0;
    while (queue.length) {
        const code = queue.shift();
        const i = code % iLen;
        const j = Math.floor(code / iLen);
        for (let k = 0; k < 4; k++) {
            const newI = i + arrI[k];
            const newJ = j + arrJ[k];
            if (newI >=0 && newI < iLen && newJ >= 0 && newJ < jLen && grid[newJ][newI] === 1) {
                grid[newJ][newI] = 2;
                const newCode = newJ * iLen + newI;
                queue.push(newCode);
                time = hashMap[newCode] = hashMap[code] + 1;
            }
        }   
    }

    for (let i = 0; i < iLen; i++) {
        for (let j = 0; j < jLen; j++) {
            if (grid[j][i] === 1) {
                return -1;
            }
        }
    }
    return time;
};
```