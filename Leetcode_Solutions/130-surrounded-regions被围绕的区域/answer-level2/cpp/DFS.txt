先把不能变成X的O找出来（这样的O必定是从边界开始的，做个深度优先遍历就可以了），然后遍历矩阵做修改
```
class Solution {
public:
    void helper(vector<vector<char>>& board,int i, int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()){
            if(board[i][j]!='O')return;
            else board[i][j]='*';//做标记
            helper(board,i+1,j);
            helper(board,i-1,j);
            helper(board,i,j+1);
            helper(board,i,j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)return;
//横向扫描
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){
                helper(board,0,i);
            }
            if(board[board.size()-1][i]=='O'){
                helper(board,board.size()-1,i);
            }
        }
//竖着扫描
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                helper(board,i,0);
            }
            if(board[i][board[0].size()-1]=='O'){
                helper(board,i,board[0].size()-1);
            }
        }
//做修改
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='*')board[i][j]='O';//恢复不能变X的O
            }
        }
    }
};
```
