### 解题思路
这是一道官方解答中的所说的“模拟题”，也就是模拟車能有的路线。
关键在定义的`int dx[4]`和`int dy[4]`，使用它们来表示方向：一组拥有同样下标的dx[i]和dy[i]代表一个方向。然后有：
```
    int tx=x+step*dx[direction];
    int ty=y+step*dy[direction];
```


### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i,j;
    int func(char** board,int x,int y);
    for(i=0;i<boardSize;i++)
        for(j=0;j<boardColSize[i];j++){
            if(board[i][j]=='R'){
                return func(board,i,j);
            }
        }
    return 0;
}

int func(char** board,int x,int y){
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int step,direction;
    int count=0;
    for(direction=0;direction<4;direction++){
        for(step=0;;step++){
            int tx=x+step*dx[direction];
            int ty=y+step*dy[direction];
            //找到'B'或'p'立即中断
            if(tx<0||tx>=8||ty<0||ty>=8||board[tx][ty]=='B') break;
            if(board[tx][ty]=='p'){
                count++;
                break;
            } 
        }
    }
    return count;
}
```