### 解题思路
纯考corner contidon的典范~
![image.png](https://pic.leetcode-cn.com/ff5fcdf9815694c2ac8f1a392a285669ccb442fb65dff6ace91f4669cc6779fa-image.png)


### 代码

```c
bool validTicTacToe(char ** board, int boardSize){
    int i = 0;
    int j = 0;
    int countO = 0;
    int countX = 0;
    int countlineX = 0;
    int countlineO = 0;

    //printf("%d\n",boardSize);

    if(boardSize != 3) {
        return false;
    }

    for(i = 0; i < boardSize; i++) {
        if(strlen(board[i]) != 3) {
            return false;
        }
    }
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == 'X') {
                countX++;
            }
            if(board[i][j] == 'O') {
                countO++;
            }
            if(board[i][j] != ' ' && board[i][j] != 'X' && board[i][j] != 'O') {
                //printf("evil\n");
                return false;
            }
        }
    }

    //printf("countX = %d, countO = %d\n", countX, countO);

    if(((countX - countO) != 0) && ((countX - countO) != 1)) {
        return false;
    }

    if(countX > 5 || countO > 4) {
        return false;
    }

    for(i = 0; i < 3; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'X')) {
            countlineX++;
        }        
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'O')) {
            countlineO++;
        }                
    }
    for(j = 0; j < 3; j++) {
        if((board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == 'X')) {
            countlineX++;
        }  
        if((board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == 'O')) {
            countlineO++;
        }                
    }        
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'X')) {
        countlineX++;
    }

    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O')) {
        countlineO++;
    }    
    if((board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X')) {
        countlineX++;
    }
    if((board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O')) {
        countlineO++;
    }

    //printf("countlineX = %d, countlineO = %d\n",countlineX, countlineO);
    if(countlineX > 0 && countlineO > 0) {
        return false;
    }

    if(countlineO > 1) {
        return false;
    }

    if(countO == 4 && countlineO == 1 && countX == 5) {
        return false;
    }


    //printf("countline = %d\n",countline);
    if(countlineX > 1 && countX != 5) {
        return false;
    }

    if(countlineX == 1 && countX == countO ){
    //if(countlineX == 1 && countX == 4 && countO > 3) {
        return false;
    }

    return true;
}
```