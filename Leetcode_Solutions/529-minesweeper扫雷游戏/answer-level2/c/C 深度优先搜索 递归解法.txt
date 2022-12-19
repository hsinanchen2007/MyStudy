思路：
1、click为雷直接赋值并返回；
2、当前点周边有雷，则统计++后修改当前点并返回；
3、当前点为'E',递归调用Dfs；

```
typedef struct Point{
     int rowIdx;
     int colIdx;
 }Point;

#define DIRECTION_NUM (8)
#define DIMENSION (2)

int DirVal[DIRECTION_NUM][DIMENSION] = {{-1,0},{1,0},{0,-1},{0,1},{1,-1},{1,1},{-1,1},{-1,-1}};

int Judge(char** board, int rowSize, int colSize, Point p) {
    struct Point curP;
    struct Point nextP;
    int sum = 0;
    curP.rowIdx = p.rowIdx;
    curP.colIdx = p.colIdx;

    for (int i = 0; i < DIRECTION_NUM; i++) {
        nextP.rowIdx = curP.rowIdx + DirVal[i][0];
        nextP.colIdx = curP.colIdx + DirVal[i][1];

        if ((0 <= nextP.rowIdx) && (rowSize > nextP.rowIdx) && (0 <= nextP.colIdx) && (colSize > nextP.colIdx)) {
            if ('M' == board[nextP.rowIdx][nextP.colIdx]) {
                sum++;
            }
        }
    }
    return sum;
}

void Dfs(char** board, int rowSize, int colSize, Point p) {
    int sum = Judge(board, rowSize, colSize, p);
    struct Point curP;
    struct Point nextP;

    curP.rowIdx = p.rowIdx;
    curP.colIdx = p.colIdx;

    if (0 < sum) {
        board[curP.rowIdx][curP.colIdx] = sum + '0';
    } else {
        board[curP.rowIdx][curP.colIdx] = 'B';
        for (int i = 0; i < DIRECTION_NUM; i++) {
            nextP.rowIdx = curP.rowIdx + DirVal[i][0];
            nextP.colIdx = curP.colIdx + DirVal[i][1];

            if ((0 <= nextP.rowIdx) && (rowSize > nextP.rowIdx) && (0 <= nextP.colIdx) && (colSize > nextP.colIdx) && ('E' == board[nextP.rowIdx][nextP.colIdx])) {
                Dfs(board, rowSize, colSize, nextP);
            }
        }
    } 
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    int ret = 0;

    if ((0 == boardSize) || (0 == boardColSize) || (0 == *boardColSize) || (0 == returnSize) || (0 == *returnColumnSizes) || 
       (0 == click) || (0 == clickSize)) {
        return 0;
    }

    *returnSize = boardSize;
    *returnColumnSizes = boardColSize;

    if ('M' == board[click[0]][click[1]]) {
        board[click[0]][click[1]] = 'X';
        return board;
    }
    struct Point p;
    p.rowIdx = click[0];
    p.colIdx = click[1];

    Dfs(board, boardSize, *boardColSize, p);

    return board;   

}
```
