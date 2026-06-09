### 解题思路
此处撰写解题思路

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int x,y;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<*boardColSize;j++){
            if(board[i][j]=='R'){
                x=i;
                y=j;
            }
        }
    }
    int count=0;
    for(int j=y;j<*boardColSize;j++){
        if(board[x][j]=='.')
            continue;
        else if(board[x][j]=='B'){
            break;
        }
        else if(board[x][j]=='p'){
            count++;
            break;
        }
    }
    
    for(int j=y;j>=0;j--){
        if(board[x][j]=='.')
            continue;
        else if(board[x][j]=='B'){
            break;
        }
        else if(board[x][j]=='p'){
            count++;
            break;
        }
    }
    
     for(int i=x;i>=0;i--){
        if(board[i][y]=='.')
            continue;
        else if(board[i][y]=='B'){
            break;
        }
        else if(board[i][y]=='p'){
            count++;
            break;
        }
    }
    
         for(int i=x;i<boardSize;i++){
        if(board[i][y]=='.')
            continue;
        else if(board[i][y]=='B'){
            break;
        }
        else if(board[i][y]=='p'){
            count++;
            break;
        }
    }
    return count;
    
    
    
    
    
}
```