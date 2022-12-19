```js
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    const dir = [[0, -1], [0, 1], [-1, -1], [-1, 0], [-1, 1], [1, -1], [1, 0], [1, 1]];
    const res = [];
    let liveNum;
    for(let i = 0; i < board.length; i++) {
        res[i] = [];
        for(let j = 0; j < board[0].length; j++) {
            liveNum = dir.reduce((t, [offsetX, offsetY]) => {
                const [x, y] = [offsetX + i, offsetY + j];
                if (x >= 0 && x < board.length && y >=0 && y < board[0].length)
                    t += board[x][y];
                return t;
            }, 0)
            if (liveNum === 3) res[i][j] = 1;
            else if (liveNum === 2) res[i][j] = board[i][j];
            else res[i][j] = 0;
        }
    }
    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[0].length; j++) {
            board[i][j] = res[i][j];
        }
    }
    return board;
};
```
