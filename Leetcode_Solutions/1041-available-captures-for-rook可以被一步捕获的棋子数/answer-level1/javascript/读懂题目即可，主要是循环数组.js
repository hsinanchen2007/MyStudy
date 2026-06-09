```
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    // 遍历数组board找到车（R）的位置，如果没找到就记录false
    let Ri = 0,Rj = 0, haveR = false, contp = 0;
    for(let i = 0; i< 8; i++) {
        for(let j = 0; j< 8; j++) {
            if(board[i][j] === 'R'){
                Ri = i;
                Rj = j;
                haveR = true;
                break;
            }
        }
    }
    // 遍历之后没有发现车（R）就return 0
    if(!haveR) {
        return 0;
    }
    // 如果找到有车（R）的话，去遍历循环四个方向有没有p（注意，遇到有B的话就break，找到一个p之后也break）
    for(let Rl = Ri - 1; Rl >= 0; Rl--){
        if(board[Rl][Rj] === 'B') {
            break;
        }
        if(board[Rl][Rj] === 'p') {
            contp += 1;
            break;
        }
    }
    for(let Rr = Ri + 1; Rr <= 7; Rr++){
        if(board[Rr][Rj] === 'B') {
            break;
        }
        if(board[Rr][Rj] === 'p') {
            contp += 1;
            break;
        }
    }
    for(let Rt = Rj - 1; Rt >= 0; Rt--){
        if(board[Ri][Rt] === 'B') {
            break;
        }
        if(board[Ri][Rt] === 'p') {
            contp += 1;
            break;
        }
    }
    for(let Rb = Rj + 1; Rb <= 7; Rb++){
        if(board[Ri][Rb] === 'B') {
            break;
        }
        if(board[Ri][Rb] === 'p') {
            contp += 1;
            break;
        }
    }
    return contp;
};
```
