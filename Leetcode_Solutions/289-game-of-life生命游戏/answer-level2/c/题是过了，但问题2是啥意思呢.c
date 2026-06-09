1. 你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
2. 本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
问题1问题不大，甚至可以用高字节位放新数组。实际数组里只放了bool值，增加几个状态就够用了.难得的双百操作
执行用时：0 ms
内存消耗：5.6 MB
问题2没看懂，边界满了会有啥问题呢？


int get_status(int** board, int i, int j, int row, int col)
{
    if(i < 0 || i >=row ||  j < 0 || j >=col)
    {
        return 0;
    }
    return board[i][j];
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int row = boardSize;
    int col = *boardColSize;
    int i, j, k;
    int count = 0;
    int status;
    int move[8][2] = {  {-1,-1},  {-1,0}, {-1,1},
                        {0, -1},          { 0,1},
                        {1, -1},  { 1,0}, { 1,1}};

    for (i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            count = 0;
            //遍历附近8个累加活细胞
            for(k = 0; k < 8; k++)
            {
                status = get_status(board, i + move[k][0], j + move[k][1], row, col);
                if(status == 1 || status == -1)
                {
                    count++;
                }
            }

            //rule不用更新状态
            //rule 1, 3 :  1=>0 as status(-1)
            if(board[i][j] == 1 && (count < 2 || count > 3))
            {
                board[i][j] = -1;
            }
            //rule 4 :  0=>1 as status(2)
            if(board[i][j] == 0 && count == 3)
            {
                board[i][j] = 2;
            }
        }
    }

    for (i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(board[i][j] > 0)
            {
                board[i][j] = 1;
            }
            else 
            {
                board[i][j] = 0;
            }
        }
    }

}