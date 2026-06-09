思路：
step1: 统计X和O的个数，X的个数应该等于O的个数或者比O的个数多1，否则返回false
step2: 分别判断对于X，O的棋面
如果两者均胜，这是不可能的，返回false
如果两者均没胜出，这是可能的，返回true
如果其中有一个人胜出，首先判断行走步数是否合理，不合理返回false
其次，判断是否存在为该人为第一次胜出的可能，即回退一部，无法区分胜负，如果可以返回true, 否则返回false
```
    bool judge(vector<string> &board, char c){
        for(int i=0; i<3; i++){
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]==c) return true;
            if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[2][i]==c) return true;
        }
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]==c) return true;
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]==c) return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int m = board.size();
        int n = board[0].length();
        int countO=0, countX=0;
        for(int i=0; i<m; i++){
            for(auto val : board[i]){
                if(val=='O') countO++;
                else if(val=='X') countX++;
            }
        }
        if(countX-countO!=1 && countX-countO!=0) return false;
        
        bool flag_X = judge(board, 'X');
        bool flag_O = judge(board, 'O');
        if(flag_X==false && flag_O==false) return true;
        else if(flag_X==true && flag_O==true) return false;
        else if(flag_X==true){
            if(countO==countX) return false;
            // 删去一个X可使得棋局无法区分胜负
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(board[i][j]=='X'){
                        board[i][j] = ' ';
                        if(judge(board, 'X')==false) return true;
                        board[i][j] = 'X';
                    }
                }
            }
            return false;
        }else if(flag_O==true){
            if(countO<countX) return false;
            // 删去一个O可使得棋局无法区分胜负
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(board[i][j]=='O'){
                        board[i][j] = ' ';
                        if(judge(board, 'O')==false) return true;
                        board[i][j] = 'O';
                    }
                }
            }
            return false;
        }
        return false;
    }
```