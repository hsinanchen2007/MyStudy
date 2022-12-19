### 解题思路
用三个Hash Table存各行各列以及九个宫格的0~9字符出现次数，
如果发现Hash表中某个位置的数字大于1，则返回false；
HashBox[(i/3)*3+(j/3)][board[i][j]-'0']中，
(i/3)*3+(j/3)是根据行列关系计算得出的，第i行第j列的一个元素处于哪个宫格（宫格下标是0~8）。

时间复杂度：由于只遍历一次board，因此是O(n^2).


### 代码

```c
bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int HashRow[9][10];
    int HashCol[9][10];
    int HashBox[9][10];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<10;j++)
        {
            HashRow[i][j]=0;
            HashCol[i][j]=0;
            HashBox[i][j]=0;
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                HashRow[i][board[i][j]-'0']++;
                HashCol[j][board[i][j]-'0']++;
                HashBox[(i/3)*3+(j/3)][board[i][j]-'0']++;
                bool b1=HashRow[i][board[i][j]-'0']>1;
                bool b2=HashCol[j][board[i][j]-'0']>1;
                bool b3=HashBox[(i/3)*3+(j/3)][board[i][j]-'0']>1;
                if(b1||b2||b3) return false;
            }
        }
    }
    /* for(int i=0;i<9;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("Row[%d][%d]=%d ",i,j,HashRow[i][j]);
            printf("Col[%d][%d]=%d ",i,j,HashCol[i][j]);
            printf("Box[%d][%d]=%d ",i,j,HashBox[i][j]);
        }
    }*/
    return true;
}
```