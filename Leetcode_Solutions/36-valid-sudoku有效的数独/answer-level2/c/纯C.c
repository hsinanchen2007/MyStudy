### 解题思路
纯C

### 代码

```c
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    if (NULL == board || 0 == boardSize || 0 == *boardColSize)
    {
        return false;
    }

    bool* pbUsed = (bool*)malloc(9 * sizeof(bool));

    int row = 0;
    int col = 0;
    int num = 0;
    int box = 0;

    // each row
    for (row = 0; row <= 8; row++)
    {
        memset(pbUsed, false, 9);

        for (col = 0; col <= 8; col++)
        {
            if (board[row][col] != '.')
            {
                num = board[row][col] - '1';
                
                if (pbUsed[num] == true)
                {
                    return false;
                }
                else
                {
                    pbUsed[num] = true;
                }
            }
        }
    }

    // each col
    for (col = 0; col <= 8; col++)
    {
        memset(pbUsed, false, 9);

        for (row = 0; row <= 8; row++)
        {
            if (board[row][col] != '.')
            {
                num = board[row][col] - '1';

                if (pbUsed[num] == true)
                {
                    return false;
                }
                else
                {
                    pbUsed[num] = true;
                }
            }
        }
    }

    // each 3x3 box
    for (box = 0; box <= 8; box++)
    {
        memset(pbUsed, false, 9);

        for (row = 0; row <= 2; row++)
        {
            for (col = 0; col <= 2; col++)
            {
                if (board[row + 3 * (box / 3)][col + 3 * (box % 3)] != '.')
                {
                    num = board[row + 3 * (box / 3)][col + 3 * (box % 3)] - '1';

                    if (pbUsed[num] == true)
                    {
                        return false;
                    }
                    else
                    {
                        pbUsed[num] = true;
                    }
                }
            }
        }
    }

    return true;
}
```