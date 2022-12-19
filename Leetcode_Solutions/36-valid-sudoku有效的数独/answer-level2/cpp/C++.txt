分为三部分判断，该元素所在行是否冲突，该元素所在列是否冲突，该元素所在字框是否冲突

```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<81; i++)
            if(!checkOnePos(board, i))
                return false;
        
        return true;
    }
    bool checkOnePos(vector<vector<char>>& board, int pos)
    {
        
        int row = pos/9, col = pos%9;
        if(board[row][col] == '.') return true;
        
        for(int i=0; i<9;i++)
        {if(i == col) continue;
            if(board[row][i] == board[row][col]) return false;}
        
        for(int j=0; j<9;j++)
        {   if(j == row) continue;
            if(board[j][col] == board[row][col]) return false;}
        
        int boxR = row/3, boxC=col/3;
        for(int i=3*boxR; i<3*boxR+3; i++)
            for(int j=3*boxC; j<3*boxC+3; j++)
            {   if(i==row && j==col) continue;
                if(board[i][j] == board[row][col]) return false;}
        
        return true;

    }
};
```
