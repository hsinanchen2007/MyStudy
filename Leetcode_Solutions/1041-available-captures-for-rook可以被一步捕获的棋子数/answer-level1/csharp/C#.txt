### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int NumRookCaptures(char[][] board) {
            int res =0;
            if (board.Length == 0) return res;

            for (int i = 0; i < board.Length; i++)
            {
                for (int j = 0; j < board[i].Length; j++)
                {
                    if (board[i][j] == 'R')
                    {
                        int left = j;
                        while (left > 0)
                        {
                            left--;
                            if (board[i][left] == 'B')
                            {
                                break;
                            }
                            else if(board[i][left] == 'p') {
                                res++;
                                break;
                            }
                        }
                        int right = j;
                        while (right < board[i].Length-1)
                        {
                            right++;
                            if (board[i][right] == 'B')
                            {
                                break;
                            }
                            else if (board[i][right] == 'p')
                            {
                                res++;
                                break;
                            }
                        }
                        int up = i;
                        while (up > 0)
                        {
                            up--;
                            if (board[up][j] == 'B')
                            {
                                break;
                            }
                            else if (board[up][j] == 'p')
                            {
                                res++;
                                break;
                            }
                        }
                        int down = i;
                        while (down < board.Length-1)
                        {
                            down++;
                            if (board[down][j] == 'B')
                            {
                                break;
                            }
                            else if (board[down][j] == 'p')
                            {
                                res++;
                                break;
                            }
                        }
                        return res;
                    }
                }
            }


            return res;
    }
}

```