### 解题思路
找到R
从上下左右去寻找p

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i,j,x,y,z=0;
    for(i=0;i<boardSize;i++){
        for(j=0;j<*boardColSize;j++){
            if(board[i][j]=='R'){
                x=i;
                y=j;
            }
        }
    }

    for(i=x-1;i>=0;i--){
        if(board[i][y]=='p'){
            z++;
            break;
        }
        if(board[i][y]=='B'){
            break;
        }
    }
    for(i=x+1;i<8;i++){
        if(board[i][y]=='B'){
            break;
        }
        if(board[i][y]=='p'){
            z++;
            break;
        }
    }
    for(j=y-1;j>=0;j--){
        if(board[x][j]=='B'){
            break;
        }
        if(board[x][j]=='p'){
            z++;
            break;
        }
    }
    for(j=y+1;j<8;j++){
        if(board[x][j]=='B'){
            break;
        }
        if(board[x][j]=='p'){
            z++;
            break;
        }
    }
    return z;

}
```