### 解题思路
此处撰写解题思路

### 代码

```c
void DFS(char**board,int i,int j,int boardSize,int colsize){
    if(i>=0&&i<boardSize&&j>=0&&j<colsize&&board[i][j]=='O')
    board[i][j]='#';
    else 
    return;
    DFS(board,i,j+1,boardSize,colsize);
    DFS(board,i+1,j,boardSize,colsize);
    DFS(board,i,j-1,boardSize,colsize);
    DFS(board,i-1,j,boardSize,colsize);  
}
void solve(char** board, int boardSize, int* boardColSize){
int i,j;
int colsize=boardColSize[0];
if (board==NULL||boardSize==0||boardColSize==NULL){
        return;
}
for(i=0;i<boardSize;i++){
    for(j=0;j<colsize;j++){
    if((i==0||j==0||i==boardSize-1||j==colsize-1)&&board[i][j]=='O')
    DFS(board,i,j,boardSize,colsize);
    
    }
}
for(i=0;i<boardSize;i++){
    for(j=0;j<colsize;j++){
        if(board[i][j]=='#')
        board[i][j]='O';
        else if(board[i][j]=='O')
        board[i][j]='X';
    }
}
}
```