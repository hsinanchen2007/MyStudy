### 解题思路
先定R，然后左右上下寻找


### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    if(boardSize==0) return 0;
    int i,j,log=0;
    for(i=0;i<boardSize;i++){                     //定R
        for(j=0;j<boardColSize[i];j++){
            if(board[i][j]=='R'){
               log=1;
               break; 
            }
        }
        if(log) break;
    }
    if(!log) return 0;
    int l=j,r=i,count=0;
        while(--l>=0){                             //左
            if(board[i][l]=='.') continue;
            if(board[i][l]=='B') break;
            if(board[i][l]=='p') {
            count++;break;
            }
        }
    l=j;
    while(++l<boardColSize[i]){                     //右
        if(board[i][l]=='.') continue;
        if(board[i][l]=='B') break;
        if(board[i][l]=='p') {
            count++;break;
        }
    }
        while(--r>=0){                              //上
            if(board[r][j]=='.') continue;
            if(board[r][j]=='B') break;
            if(board[r][j]=='p') {
            count++;break;
            }
        }
    r=i;
    while(++r<boardSize){                           //下
        if(board[r][j]=='.') continue;
        if(board[r][j]=='B') break;
        if(board[r][j]=='p') {
            count++;break;
        }
    }   
    return count;
}
```