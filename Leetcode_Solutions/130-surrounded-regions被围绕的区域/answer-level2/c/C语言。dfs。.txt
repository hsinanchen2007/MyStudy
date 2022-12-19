```
/**
 * 从边界找到所有字符'O'，并以该位置出发，找到所有'O'的连通区域，标记为'-'，
 * 剩下的'O'就是被包围的, 遍历矩阵，将剩余的'O'改为'X'，并将'-'复原为'O'。
 */
void _solve(char** board, int boardSize, int* boardColSize, int i, int j){
	if(i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || board[i][j] != 'O'){
		return ;
	}
	
	board[i][j] = '-';
	_solve(board, boardSize, boardColSize, i - 1, j);
	_solve(board, boardSize, boardColSize, i + 1, j);
	_solve(board, boardSize, boardColSize, i, j - 1);
	_solve(board, boardSize, boardColSize, i, j + 1);
}

void solve(char** board, int boardSize, int* boardColSize){
    if(0 == boardSize){
        return ;
    }
    
    int i, j;
    for(i = 0; i < boardSize; i++){
        for(j = 0; j < boardColSize[i]; j++){
            if(i == 0 || i == boardSize - 1 || j == 0 || j == boardColSize[i] - 1){
                _solve(board, boardSize, boardColSize, i, j);
            }
	}
    }
	
    for(i = 0; i < boardSize; i++){
	    for(j = 0; j < boardColSize[i]; j++){
		    if(board[i][j] == 'O'){
			    board[i][j] = 'X';
		    }else if(board[i][j] == '-'){
			    board[i][j] = 'O';
		    }
	    }
    }
}
```
