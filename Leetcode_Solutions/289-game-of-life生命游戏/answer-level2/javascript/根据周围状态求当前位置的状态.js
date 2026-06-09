### 解题思路
1. 获取每个细胞周围的状态和；
2. 同事更新需要深度复制源数组；
3. 根据规则来更新细胞状态。

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {

    let copyBoard = [];
    board.forEach((item) => {
        copyBoard.push(Array.from(item));
    })
    for (let i= 0; i < board.length; i++) {
        for (let j = 0; j < board[i].length; j++) {

            let sum = calculate(copyBoard, i, j);

            if (i === 1 && j===0) {
                console.log(sum);
            }

            if (sum < 2){
                board[i][j] = 0;
                continue;
            }

            if (sum === 3 && board[i][j] === 0) {
                board[i][j] = 1;
                continue;
            }

            if (sum >= 2 && sum <= 3 && board[i][j] === 1) {
                board[i][j] = 1;
                continue;
            }

            if (sum > 3) {
                board[i][j] = 0;
                continue;
            }
        }
    }

    return board;
};

var calculate = function(board, i, j) {
    let sum = 0;
    sum += ((i-1)>=0 && (j-1) >=0) ? board[i-1][j-1] : 0;
    sum += (i-1)>=0 ? board[i-1][j] : 0;
    sum += ((i-1)>=0 && (j+1) < board[i].length) ? board[i-1][j+1] : 0;
    sum += (j+1) < board[i].length ? board[i][j+1] : 0;
    sum += ((i+1) < board.length && (j+1)<board[i].length) ? board[i+1][j+1] : 0;
    sum += (i+1) < board.length ? board[i+1][j] : 0;
    sum += ((i+1) < board.length && (j-1) >= 0) ? board[i+1][j-1] : 0;
    sum += (j-1) >= 0 ? board[i][j-1] : 0;

    return sum;
}
```