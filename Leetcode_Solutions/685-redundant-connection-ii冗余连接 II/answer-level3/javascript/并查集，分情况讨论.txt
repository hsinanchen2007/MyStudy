- 这题需要分三种情况讨论
    - 有环，有2入度 
        - => 找一条边同时满足这两个条件，删掉2入度的且在环中的边 
        - => 用并查集，因为希望找的是入度2的边，所以这两条边最后union，union失败的边就是要找的
    - 有环，无2入度 
        - => 找一条在环中的边，看成无向图找形成环的边 
        - => 并查集的经典应用
    - 无环，有2入度 (1、2两种情况处理完后还没有结果输出，说明是情况3)
        - => 找去掉后仍然连通的边 
        - => 因为多余的边是在原本就是树的基础上找两个现有的点连的边，所以删哪一条都行，按照题意可删最后一条

![image.png](https://pic.leetcode-cn.com/0bc483cbab02f2df906fe1d777fbbd98c1234d692630a70646c6a7ee7123de55-image.png)

js实现如下
```javascript
var findRedundantDirectedConnection = function(edges) {
    const N = edges.length + 10;

    const indegrees = [];
    for (let [start, end] of edges) {
        indegrees[end] = (indegrees[end] || 0) + 1;
    }
    let endNode= null;
    let cand1 = null;
    let cand2 = null;
    for (let i = 0; i < indegrees.length; i++) {
        if (indegrees[i] === 2) {
            endNode = i;
            break;
        }
    }
    if (endNode) {
        for (let edge of edges) {
            const [start, end] = edge;
            if (end !== endNode) continue;
            if (cand1 === null) cand1 = [start, end];
            else cand2 = [start, end];
            edge[1] = null; // 为了让这两条边最后union
        }
    }

    class UF {
        constructor(size) {
            this.parent = new Array(size).fill(-1);
            this.size = new Array(size).fill(1);
        }
        findRoot(i) {
            while (this.parent[i] !== -1) i = this.parent[i];
            return i;
        }
        union(i, j) {
            const iRoot = this.findRoot(i);
            const jRoot = this.findRoot(j);
            if (iRoot === jRoot) return [i, j];
            if (this.size[iRoot] > this.size[jRoot]) {
                this.parent[jRoot] = iRoot;
                this.size[iRoot] += this.size[jRoot];
            } else {
                this.parent[iRoot] = jRoot;
                this.size[jRoot] += this.size[iRoot];
            }
        }
    }

    const uf = new UF(N);
    for (let [start, end] of edges) {
        if (end == null) continue;
        const t = uf.union(start, end);
        if (t) return t; // 情况2 会在这里输出
    }
    if (endNode) { // 情况1 会在这里输出
        const t1 = uf.union(cand1[0], cand1[1]);
        if (t1) return t1;
        const t2 = uf.union(cand2[0], cand2[1]);
        if (t2) return t2;
    }

    return cand2; // 情况3 会在这里输出
};
```
