js DFS 9行解决战斗

```js
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    const dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    function numDFS(i, j, isVisited) {
        const key = i + '-' + j;
        if (i < 0 || i >= m || j < 0 || j >= n || isVisited[key]) return 0;
        if (('' + i + j).split('').reduce((t, i) => t + +i, 0) > k) return 0;
        isVisited[key] = true;
        return dir.reduce((t, [offsetX, offsetY]) => t + numDFS(i + offsetX, j + offsetY, isVisited), 0) + 1;
    }
    return numDFS(0, 0, {});
};
```
// BFS 版本，只需要走两个方向
```js
var movingCount = function(m, n, k) {
    const queue = [[0, 0]];
    let res = 0, i = 1;
    const isVisited = {};
    while(i) {
        while(i--) {
            const [i, j] = queue.shift();
            const key = i + '-' + j;
            if (i >= m || j >= n || isVisited[key] || ('' + i + j).split('').reduce((t, i) => t + +i, 0) > k) continue;
            res++;
            isVisited[key] = true;
            queue.push([i + 1, j], [i, j + 1])
        }
        i = queue.length;
    }
    return res;
};
```

