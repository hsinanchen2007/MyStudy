DFS17行解决战斗
```js
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const dir = [[-1, 0],[1, 0],[0, -1],[0, 1]];
    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[0].length; j++) {
            if(board[i][j] === word[0]) {
                if(isExistDFS(i, j, 0)) return true;
            }
        }
    }
    function isExistDFS(i, j, num) {
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] !== word[num]) return false;
        if(num === word.length - 1) return true;
        board[i][j] = null;
        const res = dir.some(([offsetX, offsetY]) => isExistDFS(i + offsetX, j + offsetY, num + 1))
        board[i][j] = word[num];
        return res;
    }
    return false;
};
```
