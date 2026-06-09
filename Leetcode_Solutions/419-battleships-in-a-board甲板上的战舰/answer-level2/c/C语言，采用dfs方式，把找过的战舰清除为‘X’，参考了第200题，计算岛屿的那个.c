执行用时 :4 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7.8 MB, 在所有 C 提交中击败了14.29%的用户

采用dfs方式，把找过的战舰清除为‘X’，参考了第200题，计算岛屿的那个

具体代码：

void dfs(char** board, int boardSize, int boardColSize, int x, int y) 
{
    board[x][y] = '.';
    if ((x + 1 < boardSize) && board[x+1][y] == 'X') dfs(board, boardSize, boardColSize, x+1, y);
    if ((y + 1 < boardColSize) && board[x][y+1] == 'X') dfs(board, boardSize, boardColSize, x, y+1);
}

int countBattleships(char** board, int boardSize, int* boardColSize){
    int count = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            if (board[i][j] == 'X') {
                dfs(board, boardSize, *boardColSize, i, j);
                count++;
            }
        }
    }
    return count;
}