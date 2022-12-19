1. 将string => number
2. 使用广度优先搜索获得最快路径:
第一步：0000 => 第二步：1000 9000 0100 0900 0010 0090 0001 0009 => ...
2. 用Set来储存已经检测过的结果(主要是查询方便，性能反而不如Array)
3. 递归，当发现目标值的时候返回层级；当所有可能的数字都被查询完之后返回-1；

```js
const openLock = function(deadends, target) {
    const t = ~~target;
    if (t === 0) return 0;
    const d = deadends.map(v => ~~v);
    let visited = new Set(d);
    if (visited.has(0)) return -1;
    // 引用
    let step = { step: 0, isBlock: false };
    function bfs(currentNodes, step, visited) {
        const childs = getChild(currentNodes, visited);
        // 跳出条件：child长度为0，表示已经将所有可能性已经递归完毕了
        if (childs.size === 0) {
            step.isBlock = true;
            return;
        }
        step.step = step.step + 1;
        // 如果下一层级有目标节点，则返回step
        if (childs.has(t)) {
            return;
        }
        visited = new Set([...visited, ...childs]);
        bfs(childs, step, visited);
    }
    function getChild(currentNodes, visited) {
        let childs = new Set();
        currentNodes.forEach((k, v) => {
            for (let i = 0; i < 4; i++) {
                let n = Math.pow(10, i);
                const a0 = checkNotZero(v, i) ? v - n : v + 9 * n;
                const a1 = checkNotZero(v + n, i) ? v + n : v - 9 * n;
                if (!visited.has(a0)) {
                    childs.add(a0);
                }
                if (!visited.has(a1)) {
                    childs.add(a1);
                }
            }
        });
        return childs;
    }
    function checkNotZero(target, n) {
        return ~~(target / Math.pow(10, n)) % 10 !== 0;
    }
    const start = new Set([0]);
    bfs(start, step, visited);
    return step.isBlock ? -1 : step.step;
};
```

