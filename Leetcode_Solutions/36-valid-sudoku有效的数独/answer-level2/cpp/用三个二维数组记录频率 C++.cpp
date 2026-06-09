### 解题思路
遍历一遍数独数组，使用三个二维数组分别记录行、列、子数独的数字。

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10]={0};
        int column[9][10]={0};
        int sbox[9][10]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                int value=board[i][j]-'0';
                if(row[i][value]) return false;
                if(column[j][value]) return false;
                int k = i/3*3+j/3;
                if(sbox[k][value]) return false;
                row[i][value]++;
                column[j][value]++;
                sbox[k][value]++;
            }
        }
        return true;
    }
};
```