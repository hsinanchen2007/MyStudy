```csharp
public void GameOfLife(int[][] board) {
    //遍历第一遍查状态
    for(int i = 0; i < board.Length; i++)
    {
        for(int j = 0; j < board[i].Length; j++)
        {
            if(board[i][j] != 1 && board[i][j] != 0) continue;
            int count = CountAlive(board, i, j);
            if(board[i][j] == 1 && (count < 2 || count > 3))
            {
                board[i][j] = 3;//当前存活，即将死亡
            }
            else if(board[i][j] == 0 && count == 3)
            {
                board[i][j] = 4;//当前死亡，即将复活
            }
        }
    }

    //遍历第二遍改状态
    for(int i = 0; i < board.Length; i++)
    {
        for(int j = 0; j < board[i].Length; j++)
        {
            if(board[i][j] == 3)
            {
                board[i][j] = 0;
            }
            else if(board[i][j] == 4)
            {
                board[i][j] = 1;
            }
        }
    }
}

public int CountAlive(int[][] board, int x, int y)
{
    //查坐标x,y周围活细胞数
    int aliveCount = 0;
    if(x > 0 && (board[x - 1][y] == 1 || board[x - 1][y] == 3))
    {
        aliveCount++;
    }
    if(x > 0 && y > 0 && (board[x - 1][y - 1] == 1 || board[x - 1][y - 1] == 3))
    {
        aliveCount++;
    }
    if(x > 0 && y + 1 < board[x - 1].Length 
        && (board[x - 1][y + 1] == 1 || board[x - 1][y + 1] == 3))
    {
        aliveCount++;
    }
    if(x + 1 < board.Length && (board[x + 1][y] == 1 || board[x + 1][y] == 3))
    {
        aliveCount++;
        if(aliveCount > 3) //活细胞数大于3就不用再查了，提高效率
        {
            return aliveCount;
        }
    }
    if(x + 1 < board.Length && y > 0 
        && (board[x + 1][y - 1] == 1 || board[x + 1][y - 1] == 3))
    {
        aliveCount++;
        if(aliveCount > 3)
        {
            return aliveCount;
        }
    }
    if(x + 1 < board.Length && y + 1 < board[x + 1].Length 
        && (board[x + 1][y + 1] == 1 || board[x + 1][y + 1] == 3))
    {
        aliveCount++;
        if(aliveCount > 3)
        {
            return aliveCount;
        }
    }
    if(y > 0 && (board[x][y - 1] == 1 || board[x][y - 1] == 3))
    {
        aliveCount++;
        if(aliveCount > 3)
        {
            return aliveCount;
        }
    }
    if(y + 1 < board[x].Length && (board[x][y + 1] == 1 || board[x][y + 1] == 3))
    {
        aliveCount++;
    }
    return aliveCount;
}
```