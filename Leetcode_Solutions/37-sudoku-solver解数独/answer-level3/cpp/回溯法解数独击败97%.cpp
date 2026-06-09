### 解题思路
用数组保存填写的状态，在填写时，除非到最后一个空的时候return true，否则1-9依次尝试。

### 代码

```cpp
class Solution {
public:
    int findThreeIndex(int i, int j)
    {
        if(i >= 0 && i <= 2)
        {
            if(j >= 0 && j <= 2) return 0;
            else if(j >= 3 && j <= 5) return 1;
            else return 2;
        }
        else if(i >= 3 && i <= 5)
        {
            if(j >= 0 && j <= 2) return 3;
            else if(j >= 3 && j <= 5) return 4;
            else return 5;
        }
        else
        {
            if(j >= 0 && j <= 2) return 6;
            else if(j >= 3 && j <= 5) return 7;
            else return 8;
        }
    }

    bool solveFunc(int i, int j, int lastI, int lastJ, bool state[][9], bool row[][9], bool column[][9], bool three[][9], int list[][9])
    {
        for(int k = 0; k < 9; k++)
        {
            if(row[i][k] == false && column[j][k] == false && three[findThreeIndex(i,j)][k] == false)
            {
                row[i][k] = true;
                column[j][k] = true;
                three[findThreeIndex(i,j)][k] = true;
                list[i][j] = k+1;
                if(i == lastI && j == lastJ) //若填到了最后一个
                    return true;
                int tmpI = i;
                int tmpJ = j;
                do
                {
                    if(tmpJ != 8)
                        tmpJ++;
                    else
                    {
                        tmpI++;
                        tmpJ = 0;
                    }
                } while (state[tmpI][tmpJ] == true);
                if(solveFunc(tmpI, tmpJ, lastI, lastJ, state, row, column, three, list))
                    return true;
                else
                {
                    list[i][j] = 0;
                    row[i][k] = false;
                    column[j][k] = false;
                    three[findThreeIndex(i,j)][k] = false;
                    continue;
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        //主函数
        int list[9][9] = {0};
        bool state[9][9];
        bool row[9][9];
        bool column[9][9];
        bool three[9][9];
        int lastI = 0;
        int lastJ = 0;
        for(int i = 0; i<9; i++)
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    list[i][j] = (int)(board[i][j] - '0');
                    state[i][j] = true;
                }
                else
                {
                    lastI = i;
                    lastJ = j;
                    state[i][j] = false;
                }
                row[i][j] = false;
                column[i][j] = false;
                three[i][j] = false;
            }
        for(int i = 0; i<9; i++)
            for(int j = 0; j<9; j++)
            {
                if(list[i][j] != 0)
                {
                    row[i][list[i][j]-1] = true;
                    column[j][list[i][j]-1] = true;
                    three[findThreeIndex(i,j)][list[i][j]-1] = true;
                }
            }
        int i = 0;
        int j = 0;
        while(state[i][j] == true)
        {
            if(j != 8)
                j++;
            else if(i != 8)
            {
                i++;
                j = 0;
            }
        }
        solveFunc(i, j, lastI, lastJ, state, row, column, three, list);
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                board[i][j] = (char)('0' + list[i][j]);
            }
        }
    }
};
```