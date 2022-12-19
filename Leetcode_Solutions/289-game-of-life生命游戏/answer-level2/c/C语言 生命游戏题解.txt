void gameOfLife(int **board, int boardSize, int *boardColSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            // 计算存活个数
            int live = countLife(board, boardSize, boardColSize, i, j);
            // 取地位当前状态
            int now = board[i][j] & 1;

            // 当前存活
            if (now == 1)
            {
                if (live == 2 || live == 3)
                {
                    // 变更状态存活，即高位为1，二进制11为3
                    board[i][j] = 3; // 11
                }
                // 变更状态为死亡，高位为0，数值不发生改变，即为01，无需处理
            }
            if (now == 0)
            {
                if (live == 3)
                {
                    // 变更状态存活，即高位为1，二进制10为2
                    board[i][j] = 2; // 10
                }
                // 变更状态为死亡，高位为0，数值不发生改变，即为00，无需处理
            }
        }
    }

    // 移位只保留高位
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {
            board[i][j] = board[i][j] >> 1;
        }
    }
}

int countLife(int **board, int boardSize, int *boardColSize, int x, int y)
{
    // 八个位置
    int direc[8][8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int a = x + direc[i][0];
        int b = y + direc[i][1];
        if (a >= 0 && a < boardSize && b >= 0 && b < boardColSize[0])
        {
            count += (board[a][b] & 1);
        }
    }
    return count;
}
