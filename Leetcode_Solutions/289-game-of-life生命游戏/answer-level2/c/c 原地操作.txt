原题只利用了0和1来表示细胞状态，故可以利用其它位来表示是否发生状态变化。
而状态变化只考虑周围八个方向的细胞，用十位储存就足够了
```
//更新一个细胞状态
void refreshcell(int** board,int x,int y,int boardSize,int* boardColSize){ 
    int sum=0,left=x,right=x,up=y,down=y;
    if(x>0) left=x-1;if(x<boardSize-1) right=x+1;
    if(y>0) up=y-1;if(y<*boardColSize-1) down=y+1;
    for(int i=left;i<=right;i++){
        for(int j=up;j<=down;j++){
            sum+=board[i][j];
        }
    }
    sum=sum%10; //求余去掉统计周围活细胞数目时加入的状态变化
    if(board[x][y]==1&&!(sum==4||sum==3)) board[x][y]=11;
    if(board[x][y]==0&&sum==3) board[x][y]=10;  //判断是否发生状态变化
}
//遍历每一个细胞并更新其状态
void gameOfLife(int** board, int boardSize, int* boardColSize){
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<*boardColSize;j++){
            refreshcell(board,i,j,boardSize,boardColSize);
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<*boardColSize;j++){
            if(board[i][j]>=10) board[i][j]=board[i][j]%10^1; 
        }
    }
}
```