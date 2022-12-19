如果没人获胜，X的跟O一样或者X多一个。
如果X获胜，那么X比O多一个。
如果O获胜，那么X跟O一样多。
行或列的胜利者只能有一个。
（胜利者可以同时兼任行和列的胜利者，行或列与一条对角线也可以兼容，但行、列、对角线不能同时出现胜利者。
然而由于落子数的限制，这些不必考虑。）

```
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cx=0;
        int co=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='X'){
                    cx++;
                }
                else if(board[i][j]=='O'){
                    co++;
                }
            }
        }
        if((cx<co)||(cx>co+1))return false;
        if(cx<3)return true;
        int rwin=0,cwin=0;
        char winner=' ';
        for(int i=0;i<3;i++){
            char c=board[i][0];
            bool flag=true;
            if(c!=' '){
                for(int j:{1,2}){
                    if(board[i][j]!=c){
                        flag=false;
                    }
                }
                if(flag){
                    winner=c;
                    rwin++;
                }
            }
        }
        if(rwin>1)return false;
        for(int j=0;j<3;j++){
            char c=board[0][j];
            bool flag=true;
            if(c!=' '){
                for(int i:{1,2}){
                    if(board[i][j]!=c){
                        flag=false;
                    }
                }
                if(flag){
                    winner=c;
                    cwin++;
                }
            }
        }
        if(cwin>1)return false;
        {
            int i=0;
            while((i<3)&&(board[i][i]==board[1][1]))i++;
            if(i==3){winner=board[1][1];}
            i=0;
            while((i<3)&&(board[i][2-i]==board[1][1]))i++;
            if(i==3){winner=board[1][1];}
        }
        if(winner=='X'){
            if(cx==co)return false;
        }
        if(winner=='O'){
            if(cx!=co)return false;
        }
        return true;
    }
};
```
