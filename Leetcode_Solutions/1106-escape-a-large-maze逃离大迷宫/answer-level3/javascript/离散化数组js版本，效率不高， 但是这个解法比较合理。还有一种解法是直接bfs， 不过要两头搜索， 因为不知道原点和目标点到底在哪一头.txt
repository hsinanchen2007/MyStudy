```
/**
 * @param {number[][]} blocked
 * @param {number[]} source
 * @param {number[]} target
 * @return {boolean}
 */
const dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
const limit = 10 ** 6
var isEscapePossible = function(blocked, source, target) {
    if((source[0] === target[0]) && (source[1] === target[1])) return true
    let xs = new Set()
    let ys = new Set()
    for(let b of blocked) {
        for(let pos = -1; pos <= 1; pos++) {
            const indexX = b[0] + pos
            const indexY = b[1] + pos
            if(valid1(indexX)) xs.add(indexX)
            if(valid1(indexY)) ys.add(indexY)
        }
    }

    for(let pos = -1; pos <= 1; pos++) {
        let indexX = source[0] + pos
        let indexY = source[1] + pos
        if(valid1(indexX)) xs.add(indexX)
        if(valid1(indexY)) ys.add(indexY)

        indexX = target[0] + pos
        indexY = target[1] + pos
        if(valid1(indexX)) xs.add(indexX)
        if(valid1(indexY)) ys.add(indexY)
    }
    xs = Array.from(xs)
    ys = Array.from(ys)
    /*
        注意， 必须对x和y的数组都排序， 因为离散化数组的广度优先搜索会飞跃中间的一些点，
        如果不排序， 那么中间的blocked的点就被飞跃过去了起不到作用
    */
    xs.sort((a, b) => a - b)
    ys.sort((a, b) => a - b)
    const srcIndexX = bSearch(xs, source[0])
    const srcIndexY = bSearch(ys, source[1])
    const tarIndexX = bSearch(xs, target[0])
    const tarIndexY = bSearch(ys, target[1])
    //R 不一定等于C
    const R = xs.length
    const C = ys.length
    const grid = new Array(R)
    for(let i = 0; i < R; i++) grid[i] = new Array(C).fill(0)
    for(let b of blocked) {
        const indexX = bSearch(xs, b[0])
        const indexY = bSearch(ys, b[1])
        grid[indexX][indexY] = -1
    }
    grid[tarIndexX][tarIndexY] = 2
    const queue = [[srcIndexX, srcIndexY]]
    while(queue.length) {
        const cur = queue.shift()
        for(let i = 0; i < dir.length; i++) {
            const d = dir[i]
            const fx = cur[0] + d[0]
            const fy = cur[1] + d[1]
            if(!valid2(fx, fy, R, C)) continue
            if(grid[fx][fy] === -1) continue
            if(grid[fx][fy] === 2) return true
            grid[fx][fy] = -1
            queue.push([fx, fy])
        }
    }
    return false
};

function valid1(x) {
    return (x >= 0) && (x < limit)
}

function valid2(x, y, R, C) {
    return (x >= 0) && (x < R) && ( y >= 0) && (y < C)
}

function bSearch(arr, x) {
    let l = 0
    let r = arr.length
    while(l < r) {
        const m= Math.floor((l + r) / 2)
        if(arr[m] > x) {
            r = m
        } else if(arr[m] < x) {
            l = m
        } else return m
    }
}
```
