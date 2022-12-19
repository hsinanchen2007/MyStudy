```
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    let list = JSON.parse(JSON.stringify(board))
     // i 
    for(let i=0; i<list.length; i++) {
         // j 
        for(let j=0; j<list[i].length; j++) {
            let alive = 0
            // 上
            if(i>0 && list[i-1][j] === 1) {
                alive++
            }
            // 左
            if(j>0 && list[i][j-1] === 1) {
                alive++
            }
            // 左上
            if(i>0 && j>0 && list[i-1][j-1] === 1) {
                alive++
            }
             // 下
            if(i<list.length-1 && list[i+1][j] === 1) {
                alive++
            }
             // 右
            if(j<list[i].length-1 && list[i][j+1] === 1) {
                alive++
            }
             // 右下
            if(i<list.length-1 && j<list[i].length-1 && list[i+1][j+1] === 1) {
                alive++
            }
             // 左下
            if(j>0 && i<list.length-1 && list[i+1][j-1] === 1) {
                alive++
            }
             // 右上
            if(i>0 && j<list[i].length-1 && list[i-1][j+1] === 1) {
                alive++
            }
            if(list[i][j]===1 && (alive<2 || alive > 3)) {
                board[i][j] = 0 
            }
            if(list[i][j] === 0 && alive === 3) {
                board[i][j] = 1
            }
        }
    }
    return board
};
```
