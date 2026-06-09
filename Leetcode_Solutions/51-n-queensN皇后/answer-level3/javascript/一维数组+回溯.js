var solveNQueens = function(n) {
    let queen = []; // 用于存储 当前的棋盘信息
    let queens = []; // 用于 存储所有 满足 条件 的 棋盘信息
    putQueen(0, n,queen,queens);
    console.log(queens);

    return queens;
};

var check = (row, col,queen) => {
    for (let i = 0; i < row; i++) {
        if (queen[i] === col) {
            return false;
        } else if (Math.abs(row - i) === Math.abs(col - queen[i])) {
            return false;
        }
    }
    return true;// 在循环内部 没有因为同列或 同斜线 而而退出函数吗，则 可以放置 皇后
};
var save = (queen,queens) => {
    const length = queen.length;
    let cur = [];
    for (let i = 0; i < length; i++) {
        let str = "";
        for (let j = 0; j < length; j++) {
            if (j === queen[i]) {
                str += "Q";
            } else {
                str += ".";
            }
        }
        cur.push(str);
    }
    queens.push(cur);
};

var putQueen = (row, n,queen,queens) => {
    for (let col = 0; col < n; col++) {
        if (check(row, col,queen)) {
            queen[row] = col;
            if (row === n - 1) {
                save(queen,queens);
                queen[row] = -1;
                return;
            }
            putQueen(row + 1, n,queen,queens);
            queen[row] = -1; // 若不能放 皇后，退出函数，回溯到 上一行
        }
    }
};

solveNQueens(4);
