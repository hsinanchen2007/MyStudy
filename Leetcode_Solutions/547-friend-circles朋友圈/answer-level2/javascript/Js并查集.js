```js
/**
 * @param {number[][]} M
 * @return {number}
 */
var findCircleNum = function(M) {
    const n = M.length;

    const uf = new UnionFind(n);

    for (let r = 0; r < n; r++) {
        for (let c = r + 1; c < n; c++) {
            if (M[r][c] === 1) uf.union(c, r);
        }
    }

    return uf.getCount();
};

class UnionFind {
    constructor(n) {
        this.count = n;
        this.pre = new Array(n).fill(-1); // root结点
    }

    find(a) {
        if (a == undefined) return a;

        let p = a;
        while (this.pre[p] != undefined && this.pre[p] != -1) {
            p = this.pre[p];
        }

        return p;
    }

    union(a, b) {
        const rA = this.find(a);
        const rB = this.find(b);

        if (rA === rB || rA == undefined || rB == undefined) return false;

        this.pre[rA] = rB;
        this.count--;

        return true;
    }

    getCount() {
        return this.count;
        // return this.pre.filter((item, index) => item === index).length;
    }
}
```