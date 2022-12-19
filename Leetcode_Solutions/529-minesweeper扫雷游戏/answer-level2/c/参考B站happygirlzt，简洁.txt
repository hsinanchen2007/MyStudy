### 解题思路
参考B站happygirlzt，简洁
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){

    *returnSize = boardSize;
    *returnColumnSizes =  boardColSize;
    int dirs[][2] = {{-1, -1},{-1,0},{-1,1},
                {0,-1},{0,1},
                {1,-1},{1,0},{1,1}};
  
    int r = click[0];
    int c = click[1];
    int h = boardSize;
    int w = boardColSize[0];
    
    
    if(board[r][c] == 'M'){
        board[r][c] = 'X';
        return board;
    }
    
    char nums = 0;
    for(int i=0;i<8;i++){
        int newRows = r+dirs[i][0];
        int newCols = c+dirs[i][1];
        if(newRows>=0 && newCols >=0 && newRows < h && newCols < w){
            if(board[newRows][newCols] == 'M'){
                nums ++;
            }
        }
    }
    if(nums > 0){
        board[r][c] = nums + '0';
        return board;
    }
    
    board[r][c] = 'B';
    
    for(int i=0;i<8;i++){
        int newRows = r+dirs[i][0];
        int newCols = c+dirs[i][1];
        if(newRows>=0 && newCols >=0 && newRows < h && newCols < w){
            if(board[newRows][newCols] == 'E'){
                int newClick[2] = {newRows, newCols};
                board = updateBoard(board, boardSize, boardColSize, newClick, 2, 
                                    returnSize, returnColumnSizes );
            }
        }
    }
    return board;
}
```