### 解题思路
这道题其实很简单，相信大家思路应该都是有的，最简单的一种就是从白色的“车”开始，分四个方向遍历。
1.找到白“车”的位置并保存。
2.以白“车”为基点向东、西、南、北四个方便遍历：若遍历到黑“卒”，加1并退出；若遍历到白“象”，直接退出。
这里我用了一个switch函数，定义了一个状态变量status用来指示四种遍历方向。
思路很简单，代码给大家做一个参考吧。

### 代码

```c
typedef struct{
    int x;
    int y;
}state;
void MoveCheck(char** board,int line,int col,state Rock,int status,int *sum){
    int i;
    switch(status)
    {
        case 0: //向东
            for(i=Rock.y+1;i<col;i++){
                if(board[Rock.x][i]=='.')
                    continue;
                else if(board[Rock.x][i]=='p'){
                    (*sum)++;
                    break;
                }
                else if(board[Rock.x][i]=='B')
                    break;
            }
            break;
        case 1: //向南
            for(i=Rock.x+1;i<line;i++){
                if(board[i][Rock.y]=='.')
                    continue;
                else if(board[i][Rock.y]=='p'){
                    (*sum)++;
                    break;
                }
                else if(board[i][Rock.y]=='B')
                    break;
            }
            break;
        case 2: //向西
            for(i=Rock.y-1;i>=0;i--){
                if(board[Rock.x][i]=='.')
                    continue;
                else if(board[Rock.x][i]=='p'){
                    (*sum)++;
                    break;
                }
                else if(board[Rock.x][i]=='B')
                    break;
            }
            break;
        case 3: //向北
            for(i=Rock.x-1;i>=0;i--){
                if(board[i][Rock.y]=='.')
                    continue;
                else if(board[i][Rock.y]=='p'){
                    (*sum)++;
                    break;
                }
                else if(board[i][Rock.y]=='B')
                    break;
            }
            break;
    }
}
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int line=boardSize,col=*boardColSize;
    int i,j;
    state Rock;
    for(i=0;i<line;i++)
        for(j=0;j<col;j++)
            if(board[i][j]=='R'){
                Rock.x=i;
                Rock.y=j;
                break；
            }
    int sum=0,status;
    for(status=0;status<=3;status++){
        MoveCheck(board,line,col,Rock,status,&sum);
    }
    return sum;
}
```