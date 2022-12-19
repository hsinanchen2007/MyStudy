没有做优化
```
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        lalala(board,0,0);
    }

    bool lalala(vector<vector<char>>& board,int x,int y){
        if(x==8&&y==8&&board[x][y]!='.'){
            return true;
        }
        if(board[x][y]!='.'){
            y=x==8?y+1:y;
            x=x==8?0:x+1;
            return lalala(board,x,y);
        }
        for(int i=1;i<=9;++i){
            board[x][y]='0'+i;
            if(passCol(board,x,y)&&passRow(board,x,y)&&passBlock(board,x,y)){
                if(x==8&&y==8){
                    return true;
                }
                int temp_y=x==8?y+1:y;
                int temp_x=x==8?0:x+1;
                if(lalala(board,temp_x,temp_y)){
                    return true;
                }
            }
            board[x][y]='.';
        }
        return false;
    }

    bool passRow(vector<vector<char>>& board,int x,int y){
        vector<int> v(9,0);
        for(int i=0;i<9;++i){
            if(board[x][i]!='.'){
                ++v[board[x][i]-'1'];
                if(v[board[x][i]-'1']>1)
                    return false;
            }
        }
        return true;
    }

    bool passCol(vector<vector<char>>& board,int x,int y){
        vector<int> v(9,0);
        for(int i=0;i<9;++i){
            if(board[i][y]!='.'){
                ++v[board[i][y]-'1'];
                if(v[board[i][y]-'1']>1)
                    return false;
            }
        }
        return true;
    }

    bool passBlock(vector<vector<char>>& board,int x,int y){
        x=x-x%3,y=y-y%3;
        vector<int> v(9,0);
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if(board[x+i][y+j]!='.'){
                    ++v[board[x+i][y+j]-'1'];
                    if(v[board[x+i][y+j]-'1']>1)
                        return false;
                }
            }
        }
        return true;
    }
};
```
