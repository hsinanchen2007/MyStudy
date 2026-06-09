
1、先遍历一次，把每个细胞周围的状态都更新到当前细胞，保存在十位。比如当前细胞是1，周围有3个细胞，更新成31
2、遍历每个细胞，把十位取出来（周围细胞总个数），和个位（当前细胞状态）计算一下，得到下一轮的状态

```
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function (board) {
    if (board.length === 0) {
        return [];
    }

    let m = board.length;
    let n = board[0].length;

    // 遍历一次，记录周围的状态到当前细胞
    let i = 0
    while (i < m) {
        let j = 0
        while (j < n) {
            let count = getAllVal(i, j);
            board[i][j] += (10 * count);
            j++
        }
        i++
    }

    // 遍历一次，刷新当前细胞状态
    i = 0
    while (i < m) {
        let j = 0
        while (j < n) {
            board[i][j] = calcNext(i, j);
            j++;
        }
        i++;
    }

    return board;

    function getAllVal(i, j) {
        return getVal(i - 1, j - 1) + getVal(i - 1, j) + getVal(i - 1, j + 1) + getVal(i, j - 1) + getVal(i, j + 1) +
            getVal(i + 1, j - 1) + getVal(i + 1, j) + getVal(i + 1, j + 1)
    }

    function getVal(i, j) {
        if (board[i] && board[i][j]) {
            return board[i][j] % 10
        } else {
            return 0;
        }
    }

    function calcNext(i, j) {
        // 当前细胞状态
        let statu = board[i][j] % 10;
        // 周围细胞个数
        let count = Math.floor(board[i][j] / 10);
        let next;

        if (statu === 1) {
            if (count < 2 || count > 3) {
                next = 0;
            } else {
                next = 1;
            }
        } else {
            if (count === 3) {
                next = 1;
            } else {
                next = 0;
            }
        }

        return next;
    }

};
```
