```
/**
 * @param {number[][]} grid
 * @param {number[][]} hits
 * @return {number[]}
 */
const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
var hitBricks = function(grid, hits) {
    const R = grid.length
    const C = grid[0].length
    const A = new Array(R)
    for(let i = 0; i < R; i++) A[i] = [...grid[i]]
    for(let x of hits) A[x[0]][x[1]] = 0
    const dsu = new DSU(R * C + 1)
    for(let r = 0; r < R; r++) {
        for(let c = 0; c < C; c++) {
            if(A[r][c] === 0) continue
            const i = r * C + c
            if(r === 0) dsu.union(R * C, i)
            if((r >= 1) && A[r - 1][c]) dsu.union((r - 1) * C + c, i)
            if((c >= 1) && A[r][c - 1]) dsu.union(r * C + (c - 1), i)
        }
    }
    let t = hits.length
    const ans = new Array(t--).fill(0)
    while(t >= 0) {
        const hx = hits[t][0]
        const hy = hits[t][1]
        if(grid[hx][hy] === 0) {
            t--
            continue
        }
        const beforeLink = dsu.linkTop()
        A[hx][hy] = 1
        if(hx === 0) dsu.union(R * C, hx * C + hy)
        for(let i = 0; i < 4; i++) {
            const cx = hx + dirs[i][0]
            const cy = hy + dirs[i][1]
            if((cx >= 0) && (cx < R) && (cy >= 0) && (cy < C) && A[cx][cy]) {
                dsu.union(cx * C + cy, hx * C + hy)
            }
        }
        ans[t--] = Math.max(0, dsu.linkTop() - beforeLink - 1)
    }
    return ans
};

function DSU(n) {
    // 并查集
    this.parent = new Array(n)
    // 提高find性能，平衡各个点到最终parent的距离.这个不要也可以
    this.rank = new Array(n).fill(0)
    // 每个连通集有多少个元素
    this.counts = new Array(n).fill(1)
    for(let i = 0; i < n; i++) this.parent[i] = i
}

DSU.prototype.find = function(x) {
    // 找到最终的父
    if(x !== this.parent[x]) this.parent[x] = this.find(this.parent[x])
    return this.parent[x]
}

DSU.prototype.union = function(x, y) {
    let xr = this.find(x)
    let yr = this.find(y)
    if(xr === yr) return
    if(this.rank[xr] < this.rank[yr]) {
        let temp = xr
        xr = yr
        yr = temp
    }

    if(this.rank[xr] === this.rank[yr]) {
        this.rank[xr]++
    }

    this.parent[yr] = xr

    this.counts[xr] += this.counts[yr]
}

DSU.prototype.count = function(x) {
    return this.counts[this.find(x)]
}

DSU.prototype.linkTop = function() {
    return this.count(this.counts.length - 1) - 1
}

```
