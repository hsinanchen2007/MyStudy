js 一层层剥开暴力解
```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    const record = {};
    for(let i = 0; i < n; i++) record[i] = new Set();
    edges.forEach(([a, b]) => {
        record[a].add(b);
        record[b].add(a);
    })
    let items = Object.keys(record).map(i => +i);
    let queues = items.filter(key => record[key].size === 1);
    let res;
    while(queues.length) {
        res = queues;
        items = Object.keys(record).map(i => +i);
        queues = items.filter(key => record[key].size === 1);
        queues.forEach(key => {
            const next = record[Array.from(record[key])[0]];
            if(next) next.delete(key);
            delete record[key];
        })
    }
    return items.length ? items : res;
};
```
BFS出度
```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    const record = {};
    for(let i = 0; i < n; i++) record[i] = new Set();
    edges.forEach(([a, b]) => {
        record[a].add(b);
        record[b].add(a);
    })
    const outDegree = [];
    for(let i = 0; i < n; i++) outDegree[i] = record[i].size;
    let queues = outDegree.reduce((t, i, index) => {
        i === 1 && t.push(index);
        return t;
    }, [])
    let res = [0];
    let i = queues.length;
    while(i) {
        res = queues.slice(0); // 记录倒数第2个结果
        while(i--) {
            const front = queues.shift();
            outDegree[front]--;
            const next = [...record[front]][0];
            if(next !== undefined) {
                record[next].delete(front);
                if(--outDegree[next] === 1) queues.push(next);
            }
        }
        i = queues.length;
    }
    return res;
};
```

