```
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int row=0,col=0;
        for(int i=0;i<board.size();++i){
            int flag=0;
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]=='R'){
                    row=i;
                    col=j;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        int res=0;
        for(int i=0;i<4;++i){
            int posr=row,posc=col;
            while(1){
                posr=posr+dir[i][0];
                posc=posc+dir[i][1];
                if(posr<0 || posr==board.size() || posc<0 ||posc== board[0].size()||board[posr][posc]=='B') break;
                else if(board[posr][posc]=='p'){
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};
```
