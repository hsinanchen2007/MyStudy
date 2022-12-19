### 解题思路
此处撰写解题思路

### 代码

```c
bool dfs(char** board, int boardSize, int* boardColSize, char * word, int **used, int x, int y, int pos, int len){
    if(x<0||x>=boardSize||y<0||y>=*boardColSize){
        return false;
    }
    if(board[x][y]!=word[pos]||used[x][y]==1){
        return false;
    }
    if(pos+1==len){
        return true;
    }
    used[x][y]=1;
    bool flag=false;
    flag=dfs(board, boardSize, boardColSize, word, used, x, y+1, pos+1, len);
    if(flag){
        return true;
    }
    flag=dfs(board, boardSize, boardColSize, word, used, x, y-1, pos+1, len);
    if(flag){
        return true;
    }
    flag=dfs(board, boardSize, boardColSize, word, used, x-1, y, pos+1, len);
    if(flag){
        return true;
    }
    flag=dfs(board, boardSize, boardColSize, word, used, x+1, y, pos+1, len);
    if(flag){
        return true;
    }
    used[x][y]=0;
    
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if(board==NULL||boardSize==0){
        return false;
    }

    int len=strlen(word);
    int **used=(int **)malloc(sizeof(int *)*boardSize);
    int i;
    for(i=0;i<boardSize;i++){
        used[i]=(int *)malloc(sizeof(int)* *boardColSize);
    }
    for(i=0;i<boardSize;i++){
        memset(used[i],0,sizeof(int)* *boardColSize);
    }
    bool flag=false;
    for(i=0;i<boardSize;i++){
        int j;
        for(j=0;j<*boardColSize;j++){
            flag=dfs(board, boardSize, boardColSize, word, used, i, j, 0, len);
            if(flag){
                return true;
            }
        }
    }
    for(i=0;i<boardSize;i++){
        free(used[i]);
    }
    free(used);
    return false;
}

```