简单的方法应该是逆向考虑该问题，从边界上为'O'的字符着手考虑。
```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
            return ;
        }
        vector<vector<bool>> log(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]=='O'&&log[i][j]==false){
                    if(lalala(board,log,i,j)){
                        update(board,i,j);
                    }
                }
            }
        }
        return;
    }

    bool lalala(const vector<vector<char>>& board,vector<vector<bool>>& log,int i,int j){
        //cout<<i<<" "<<j<<endl;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()){
            return false;
        }
        if(board[i][j]=='X'){
            return true;
        }
        if(board[i][j]=='O'&&log[i][j]==false){
            log[i][j]=true;
            bool flag1,flag2,flag3,flag4;
            flag1=lalala(board,log,i+1,j);
            flag2=lalala(board,log,i-1,j);
            flag3=lalala(board,log,i,j+1);
            flag4=lalala(board,log,i,j-1);
            return flag1&&flag2&&flag3&&flag4;
        }
        return true;
    }

    void update(vector<vector<char>>& board,int i,int j){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()){
            return;
        }
        if(board[i][j]=='X'){
            return;
        }
        board[i][j]='X';
        update(board,i+1,j);
        update(board,i-1,j);
        update(board,i,j+1);
        update(board,i,j-1);
    }
};
```
