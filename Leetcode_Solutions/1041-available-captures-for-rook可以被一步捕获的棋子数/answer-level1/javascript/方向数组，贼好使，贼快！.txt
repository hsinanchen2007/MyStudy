这道题挺简单的，就是要注意同一方向吃了一个卒子以后要跳出循环，不允许再吃了。话不多说，上代码~~
```
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
     let res = 0;
    let directions = [[1, 0], [0, 1], [-1, 0], [0, -1]];
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            if (board[i][j] === "R") {
                for (let k = 0; k < 4; k++) {
                    let curr = directions[k];
                    let step = 1;
                    while (true) {
                        let x = i + curr[0] * step;
                        let y = j + curr[1] * step;
                        if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] === "B") break;
                        if (board[x][y] === "p") {
                            res += 1;
                            break;
                        }
                        step++;
                    }
                }
                break;
            }
        }
    }
    return res;
};
```
