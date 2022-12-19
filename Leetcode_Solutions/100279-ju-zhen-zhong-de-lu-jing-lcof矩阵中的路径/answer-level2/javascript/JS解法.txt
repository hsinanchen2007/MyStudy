### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */

var exist = function(board, word) {
    let row = board.length,
        col = board[0].length;
    let flag = [];
    if (word.length === 0) return true;
    if (board.length === 0) return false;
    for(let i=0; i<row; i++){
        for(let j=0; j<col; j++){
            if(judge(board, i, j, row, col, flag, word, 0)){
                return true
            }
        }
    }
    return false
};

const judge = (board, i, j, row, col, flag, word, k) => {
    let index = i*col + j;
    if(i<0 || j<0 || i>=row || j>=col || board[i][j]!==word[k] || flag[index] == true){
        return false
    }
    if(k === word.length-1){
        return true
    }
    flag[index] = true;
    if(judge(board, i-1, j, row, col, flag, word, k+1)||
       judge(board, i+1, j, row, col, flag, word, k+1)||
       judge(board, i, j-1, row, col, flag, word, k+1)||
       judge(board, i, j+1, row, col, flag, word, k+1)){
       return true
    }
    flag[index] = false;
    return false
}

```