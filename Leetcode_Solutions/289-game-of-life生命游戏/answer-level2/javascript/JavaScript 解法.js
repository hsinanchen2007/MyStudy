```
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
let gameOfLife = function(board) {
    let boardBak = clone(board);
    for(let i=0; i<board.length; i++) {
        let row = board[i];
        for(let j=0; j<row.length; j++) {
            row[j] = isSurvive(i, j, boardBak) ? 1 : 0;
        }
    }
};

let isSurvive = (x, y, board) => {
    let res;
    let num = aroundSurviveNum(x, y, board);
    switch(true) {
        case board[x][y] && (num==2||num==3):
            res = true;
            break;
        case !board[x][y] && num==3:
            res = true;
            break;
        default:
            res = false;
            break;
    }
    return res;
};

let aroundSurviveNum = (x, y, board) => {
    let res=0;
    for(let i=x-1; i<=x+1; i++) {
        for(let j=y-1; j<=y+1; j++) {
            if(i<0 || j<0 || i>=board.length || j>=board[0].length || (x==i&&y==j)) {
                continue;
            }
            if(board[i][j]){
                res++;
            }
        }
    }
    return res;
};

let clone = (val) => {
    return JSON.parse(JSON.stringify(val));
};
```