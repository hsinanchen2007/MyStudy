```js
var solve = function(board) {
    const row = board.length;
    if(!row) return [];
	const col = board[0].length;
	for(let i = 0; i < row; i++) {
		dfs(board, i, 0);
		dfs(board, i, col - 1);
	}
	for(let i = 0; i < col; i++) {
		dfs(board, 0, i);
		dfs(board, row - 1, i);
	}
	for(let i = 0; i < row; i++) {
		for(let j = 0; j < col; j++) {
			if(board[i][j] === 'O') {
				board[i][j] = 'X';
			}
			else if(board[i][j] === '1') {
				board[i][j] = 'O';
			}
		}
	}
	function dfs(board, i, j) {
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] === '1') return;
		if(board[i][j] === 'O') {
            board[i][j] = '1';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
	}
};
```
