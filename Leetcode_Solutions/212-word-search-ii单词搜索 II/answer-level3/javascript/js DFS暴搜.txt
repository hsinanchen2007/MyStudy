js DFS暴搜22行代码
```js
/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(board, words) {
    const row = board.length;
    if(!row) return [];
    const col = board[0].length;
    const dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    function dfs(i, j, num, word, copyBoard) {
        if(i < 0 || i >= row || j < 0 || j >= col || copyBoard[i][j] !== word[num]) return false;
        if(num === word.length - 1) return true;
        copyBoard[i][j] = '*';
        const res = dir.some(a => dfs(i + a[0], j + a[1], num + 1, word, copyBoard));
        copyBoard[i][j] = res ? '*' : word[num];
        return res;
    }
    function isExist(word, copyBoard) {
        for(let i = 0; i < row; i++) {
            for(let j = 0; j < col; j++) {
                if(board[i][j] === word[0])
                    if(dfs(i, j, 0, word, copyBoard)) return true;
            }
        }
        return false;
    }
    return words.filter(i => isExist(i, JSON.parse(JSON.stringify(board))));
};
```
