### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    int numRookCaptures(vector<vector<char>>& board) {
        int row,col;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(board[i][j]=='R'){
                    row = i;
                    col = j;
                    break;
                }
        int count = 0;
        //up
        for(int k=row;k>=0;k--)
            if(board[k][col]=='B')
                break;
            else if(board[k][col]=='p'){
                count++;
                break;
            }
        //down
        for(int k=row;k<8;k++)
            if(board[k][col]=='B')
                break;
            else if(board[k][col]=='p'){
                count++;
                break;
            }
        //right
        for(int k=col;k<8;k++)
            if(board[row][k]=='B')
                break;
            else if(board[row][k]=='p'){
                count++;
                break;
            }
        //left
        for(int k=col;k>=0;k--)
            if(board[row][k]=='B')
                break;
            else if(board[row][k]=='p'){
                count++;
                break;
            }
        return count;
    }
};
```