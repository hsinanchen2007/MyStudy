
#### 代码
```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<bool> flags(rows*cols,false);
        bool condition = false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                condition = (condition||isPath(board,flags,word,i,j,0,rows,cols));
            }
        }
        return condition;
    }
    bool isPath(vector<vector<char>>&matrix,vector<bool>flags,
                string& word,int i,int j,int t,int rows,int cols){
        if(i<0 || i>=rows || j<0 || j>=cols) //越界点判断
            return false;
        if(matrix[i][j]==word[t] && flags[i*cols+j]==false){
            flags[i*cols+j] = true;
            if((t+1)==word.size()) //word遍历结束了
                return true;
            bool condition = isPath(matrix,flags,word,i+1,j,t+1,rows,cols)||
                             isPath(matrix,flags,word,i-1,j,t+1,rows,cols)||
                             isPath(matrix,flags,word,i,j+1,t+1,rows,cols)||
                             isPath(matrix,flags,word,i,j-1,t+1,rows,cols);
            if(condition == false) //不相等的话重置状态为false
                flags[i*cols+j] = false;
            return condition;
        }
        else return false; //不相等
    }
};
```
