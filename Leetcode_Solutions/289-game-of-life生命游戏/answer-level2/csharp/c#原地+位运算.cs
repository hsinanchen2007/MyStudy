### 解题思路
此处撰写解题思路
用位运算

### 代码

```csharp
public class Solution {
    public void GameOfLife(int[][] board) {
        if(board.Length == 0 || board[0].Length == 0)
        {
            return;
        }

        for(int i = 0; i < board.Length; i++)
        {
            for(int j = 0; j < board[i].Length; j++)
            {
                int y = i;
                int x = j;

                int oldVal = GetGrid(board, x, y);
                int newVal = oldVal;

                int c = 0;
                c += GetGrid(board, x - 1, y - 1);
                c += GetGrid(board, x - 1, y);
                c += GetGrid(board, x - 1, y + 1);

                c += GetGrid(board, x, y - 1);
                c += GetGrid(board, x, y + 1);

                c += GetGrid(board, x + 1, y - 1);
                c += GetGrid(board, x + 1, y);
                c += GetGrid(board, x + 1, y + 1);

                if(c < 2)
                {
                    newVal = 0;
                }
                else if(c <= 3)
                {
                    if(c == 3)
                    {
                        newVal = 1;
                    }
                }
                else
                {
                    newVal = 0;
                }

                newVal = newVal << 1;

                SetGrid(board, x, y, newVal | oldVal);
            }
        }

        for(int i = 0; i < board.Length; i++)
        {
            for(int j = 0; j < board[i].Length; j++)
            {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
    
    public int GetGrid(int[][] board, int x, int y)
    {
        if(y < 0 || y >= board.Length || x < 0 || x >= board[0].Length)
        {
            return 0;
        }

        return board[y][x] & 1;
    }

    public int SetGrid(int[][] board, int x, int y, int v)
    {
        if(y < 0 || y >= board.Length || x < 0 || x >= board[0].Length)
        {
            return 0;
        }

        return board[y][x] = v;
    }
}
```