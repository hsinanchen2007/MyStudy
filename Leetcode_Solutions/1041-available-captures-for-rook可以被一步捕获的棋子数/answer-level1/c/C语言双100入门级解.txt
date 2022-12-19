### 解题思路
主要是理解题意，理解后选择先确定R位置然后四个方向找黑子的思路

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int Rx, Ry, cnt = 0;
    //确定R位置
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == 'R'){
                Rx = i;
                Ry = j;
            }
        }
    }
    //向上找
    for(int i = Rx; i > 0; i--){
        if(board[i][Ry] == 'p'){
            cnt++;
            break;
        }else if(board[i][Ry] == 'B'){
            break;
        }
    }
    //向下找
    for(int i = Rx; i < 8; i++){
        if(board[i][Ry] == 'p'){
            cnt++;
            break;
        }else if(board[i][Ry] == 'B'){
            break;
        }
    }
    //向左找
    for(int j = Ry; j > 0; j--){
        if(board[Rx][j] == 'p'){
            cnt++;
            break;
        }else if(board[Rx][j] == 'B'){
            break;
        }
    }
    //向右找
    for(int j = Ry; j < 8; j++){
        if(board[Rx][j] == 'p'){
            cnt++;
            break;
        }else if(board[Rx][j] == 'B'){
            break;
        }
    }
    return cnt;
}
```