```
/**
普通的 广度优先搜索，有两个关键点：1.不能有相互调用导致栈溢出；2.广度优先搜索得到的结果是错误的，需要搜索多次才行
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var updateMatrix = function(matrix) {
    const ans = new Array(matrix.length)
    for(let i = 0;i < matrix.length;i++) ans[i] = new Array(matrix[0].length).fill(-1)
    // 第一次广度优先搜搜
    for(let i = 0;i < matrix.length;i++) {
        for(let j = 0;j < matrix[0].length;j++) bfs(i, j, matrix, ans)
    }
    // 第二次纠正广度优先搜索没有搜索到的数据
    for(let i = 0;i < matrix.length;i++) {
        for(let j = 0;j < matrix[0].length;j++) bfs2(i, j, matrix, ans)
    }
    // 第三次，第二次没有完全纠正，那就再来一次
     for(let i = 0;i < matrix.length;i++) {
        for(let j = 0;j < matrix[0].length;j++) bfs2(i, j, matrix, ans)
    }
    return ans
};

function bfs(i, j, matrix, ans) {
    // if(i < 0 || i > matrix.length || j < 0 || j > matrix.length) return 0
    //console.log('每一项:', i, j, matrix[i][j], ans[i][j], ans)
    if(ans[i][j] > -1) return ans[i][j]
    if(matrix[i][j] === 0) {
        ans[i][j] = 0
        return 0
    }

    let temp1 = Infinity
    let temp2 = Infinity
    let temp3 = Infinity
    let temp4 = Infinity

    ans[i][j] = -2

    const top = i - 1
    if((top > -1) && (ans[top][j] !== -2)) temp1 = bfs(top, j, matrix, ans)

    const left = j -1
    if((left > -1) && (ans[i][left] !== -2)) temp4 = bfs(i, left, matrix ,ans)

    const right = j + 1
    if((right < matrix[0].length) && (ans[i][right] !== -2)) temp2 = bfs(i, right, matrix, ans)

    const bottom = i + 1
    if((bottom < matrix.length) && (ans[bottom][j] !== -2)) temp3 = bfs(bottom, j, matrix, ans)

    ans[i][j] = 1 + Math.min(temp1, temp2, temp3, temp4)
    return ans[i][j]
}
function bfs2(i, j, matrix, ans) {
    if(ans[i][j] === 0) return
    let temp1 = Infinity
    let temp2 = Infinity
    let temp3 = Infinity
    let temp4 = Infinity

    const top = i - 1
    if (top > -1) temp1 = ans[top][j]

    const left = j - 1
    if (left > -1) temp4 = ans[i][left]

    const right = j + 1
    if (right < matrix[0].length) temp2 = ans[i][right]

    const bottom = i + 1
    if (bottom < matrix.length) temp3 = ans[bottom][j]
    ans[i][j] = 1 + Math.min(temp1, temp2, temp3, temp4)
}
```
