```C
bool tiankong(char **,char **,int,int,int);
bool isend(char **);

bool validTicTacToe(char ** board, int boardSize){
    char ** res = malloc(sizeof(char*) * boardSize);  //自己模拟下棋过程的棋盘
    for(int i=0;i<boardSize;i++) {  //初始化为全空
        res[i] = malloc(sizeof(char) * boardSize);
        memset(res[i],' ',boardSize);
    }
    int countx = 0, counto = 0;
    for(int i=0;i<boardSize;i++){   //统计X和O的数量
        for(int j = 0; j < boardSize; j++){
            if(board[i][j] == 'X')
                countx++;
            if(board[i][j] == 'O')
                counto++;
        }
    }
    if(countx < counto) //初步判断去掉一些情况
        return false;
    return tiankong(res,board,counto,countx,0);
}

bool tiankong(char **res, char **board, int counto, int countx, int k){  //递归函数，k用来标记当前下X还是O
    if(counto == 0 && countx == 0)
        return true;
    if(isend(res) == true)
        return false;
    if(k % 2 == 0){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X' && res[i][j] == ' '){ //如果目标棋盘有，自己的棋盘还没有就下
                    res[i][j] = 'X';
                    if(tiankong(res, board, counto, countx-1, k+1))   //接下来的情况不能递归下去了就回溯
                        return true;
                    res[i][j] = ' ';
                }
            }
        }
    }
    else if(k % 2 == 1){
        for(int i = 0; i < 3; i++){
            for(int j = 0;j < 3; j++){
                if(board[i][j] == 'O' && res[i][j] == ' '){
                    res[i][j] = 'O';
                    if(tiankong(res, board, counto-1, countx, k+1))
                        return true;
                    res[i][j] = ' ';
                }
            }
        }
    }
    return false;
}

bool isend(char ** board){ //判断是否结束
    if(board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != ' ')
        return true;
    if(board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != ' ')
        return true;
    if(board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ')
        return true;
    if(board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' ')
        return true;
    if(board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' ')
        return true;
    if(board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' ')
        return true;
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
        return true;
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[1][1]!=' ')
        return true;
    return false;
}
```
