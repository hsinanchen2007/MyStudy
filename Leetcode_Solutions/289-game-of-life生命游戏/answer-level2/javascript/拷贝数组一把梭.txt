
思路差不多，但获取邻居那里使用数组过滤，不用多行if-else判断了。
```js
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
const getNeighbors = (arr, i, j) => {
    let neighbors = []
    let i1 = arr[i-1] || []
    let i2 = arr[i+1] || []
    neighbors.push(
        i1[j-1],i1[j],i1[j+1],
        arr[i][j-1],arr[i][j+1],
        i2[j-1],i2[j],i2[j+1]
    )
    neighbors = neighbors.filter(e => e !== undefined)
    return neighbors.length ? neighbors.reduce((acc,cur) => acc+cur) : 0
}
var gameOfLife = function(board) {
    if(!board.length) return
    let [m,n] = [board.length, board[0].length];
    let data = [...board.map(r => r.slice())]
    for(let i=0;i<m;i++) {
        for(let j=0;j<n;j++) {
            let state = data[i][j]
            let live = getNeighbors(data, i, j)
            state === 1 && (live<2 || live>3) && (state = 0)
            state === 0 && live === 3 && (state = 1)
            board[i][j] = state
        }
    }
};
```