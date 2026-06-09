### 解题思路
注意可能有多个R的情况

### 代码

```c
typedef struct il{
    int x;
    int y;
}node;
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    node sta[64];
    int ft=0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardColSize[i];j++){
            if(board[i][j]=='R') {sta[ft].x=i; sta[ft++].y=j;}
        }
    }
    int ans=0;
    while(ft>0){
        ft--;
        node nowget=sta[ft];
        for(int up=nowget.x-1;up>=0;up--){
            if(board[up][nowget.y]!='.'){
                if(board[up][nowget.y]=='p') ans++;
                break;
            }
        }
        for(int down=nowget.x+1;down<boardSize;down++){
            if(board[down][nowget.y]!='.'){
                if(board[down][nowget.y]=='p') ans++;
                break;
            }
        }
        for(int le=nowget.y-1;le>=0;le--){
            if(board[nowget.x][le]!='.'){
                if(board[nowget.x][le]=='p') ans++;
                break;
            }
        }
        for(int ri=nowget.y+1;ri<boardColSize[nowget.x];ri++){
            if(board[nowget.x][ri]!='.'){
                if(board[nowget.x][ri]=='p') ans++;
                break;
            }
        }
    }
    return ans;
}
```