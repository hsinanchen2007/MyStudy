### 解题思路
记录数字的位置信息

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool D[9][3][9]={false};//记录数字num 的行,列,块上是否已经出现过
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                int k=(i/3*3+j/3);
                int num=board[i][j]-'0';
                if(D[num-1][0][i]||D[num-1][1][j]||D[num-1][2][k])return false;
                D[num-1][0][i]=1;
                D[num-1][1][j]=1;
                D[num-1][2][k]=1;
            }
        return true;
    }
};
```