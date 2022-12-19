### 解题思路
1,申明三个布尔数组表明行，列，还有9宫格来标识数字是否被使用过，并且初始化
2,回溯法，
    1)控制变量的设定，选定行 row 列 col 作为回溯法的控制变量，不同的row和col标识回溯函数在不同的层
    2)边界定位，当 row=9 col=9 时说明进行到了最后一个数字则返回成功
    3)填充条件，当(row,col)位置有数字时，则直接调用下一个(row, col + 1)
        当(row,col)位置为空时，1-9 循环判断是否可以填入，则填入数字，回溯调用下一个(row, col + 1)
    4)回退条件，及回退措施，
        回退条件：1-9无数可填
        回退措施：将刚填的 board[row][col]='.',并且将 三个布尔数组恢复原值，让上一层能够回退回去进行填写下一个数


### 代码

```c
//1,申明三个布尔数组表明行，列，还有9宫格来标识数字是否被使用过，并且初始化
//2,回溯法，
//1)控制变量的设定，选定行 row 列 col 作为回溯法的控制变量，不同的row和col标识回溯函数在不同的层
//2)边界定位，当 row=9 col=9 时说明进行到了最后一个数字则返回成功
//3)填充条件，当(row,col)位置有数字时，则直接调用下一个(row, col + 1)
//当(row,col)位置为空时，1-9 循环判断是否可以填入，则填入数字，回溯调用下一个(row, col + 1)
//4)回退条件，及回退措施，
//回退条件：1-9无数可填
//回退措施：将刚填的 board[row][col]='.',并且将 三个布尔数组恢复原值，让上一层能够回退回去进行填写下一个数


bool traceBackSudoku(char** board, char** rowUsed, char** colUsed, char** spaceUsed, int row, int col){
    int     i       = 0;

    //3,边界条件
    if (col == 9)
    {
        col = 0;
        row += 1;
        if (row == 9)
        {
            return true;
        } 
    }

    //4,填充数字
    if (board[row][col] == '.')
    {
        for (i = 1; i <= 9; i++)
        {
//printf("i=%d, row=%d, col=%d %d-%d-%d\n", i, row, col, rowUsed[row][i - 1], colUsed[col][i - 1], spaceUsed[(row / 3) * 3 + (col / 3)][i - 1]);
            if ((0 == rowUsed[row][i - 1]) && 
                (0 == colUsed[col][i - 1]) && 
                (0 == spaceUsed[(row / 3) * 3 + (col / 3)][i - 1]))
            {
                board[row][col] = i + '0';
                rowUsed[row][i - 1] = 1;
                colUsed[col][i - 1] = 1;
                spaceUsed[(row / 3) * 3 + (col / 3)][i - 1] = 1;

                if (true == traceBackSudoku(board, rowUsed, colUsed, spaceUsed, row, col + 1))
                {
                    return true;
                }
                else
                {
                    //5,回退措施
                    board[row][col] = '.';
                    rowUsed[row][i - 1] = 0;
                    colUsed[col][i - 1] = 0;
                    spaceUsed[(row / 3) * 3 + (col / 3)][i - 1] = 0;
                }
            }
        }
    }
    else
    {
        return traceBackSudoku(board, rowUsed, colUsed, spaceUsed, row, col + 1);
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){

    int     i                   = 0;
    int     j                   = 0;
    char**  pRowUsed            = (char**)malloc(sizeof(char*) * 9);
    char**  pColUsed            = (char**)malloc(sizeof(char*) * 9);
    char**  pSpaUsed            = (char**)malloc(sizeof(char*) * 9);

    //1,初始化
    for (i = 0; i < 9; i++)
    {
        pRowUsed[i] = (char*)malloc(sizeof(char) * 9);
        memset(pRowUsed[i], 0x00, sizeof(char) * 9);
        pColUsed[i] = (char*)malloc(sizeof(char) * 9);
        memset(pColUsed[i], 0x00, sizeof(char) * 9);
        pSpaUsed[i] = (char*)malloc(sizeof(char) * 9);
        memset(pSpaUsed[i], 0x00, sizeof(char) * 9);
    }

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if ((board[i][j] >= '1') && (board[i][j] <= '9'))
            {
                pRowUsed[i][board[i][j] - '1'] = 1;
                pColUsed[j][board[i][j] - '1'] = 1;
                pSpaUsed[(i / 3) * 3 + (j / 3)][board[i][j] - '1'] = 1;
            }
        }
    }

    //2,调用回溯函数
    traceBackSudoku(board, pRowUsed, pColUsed, pSpaUsed, 0, 0);

    return;
}
```