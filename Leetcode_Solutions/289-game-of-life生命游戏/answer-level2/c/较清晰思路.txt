void gameOfLife(int** board, int boardSize, int* boardColSize){
    int** cell = (int**)malloc(sizeof(int*)*boardSize);
    for(int i = 0;i<boardSize;i++){
        cell[i] = (int*)malloc(sizeof(int)*(*boardColSize));
        for(int j = 0;j<(*boardColSize);j++){
            cell[i][j] = 0;
        }
    }
//这里cell指代的是每个细胞周围的活细胞数量
int dis[8][2] = {{0,1},{0,-1},{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1}};
    int len = (*boardColSize);
    for(int i = 0;i<boardSize;i++){
        for(int j = 0;j<len;j++){
            if(board[i][j]==1){
                for(int k = 0;k<8;k++){
                    int x = i+dis[k][1];
                    int y = j + dis[k][0];
                    if(x<0||x>=boardSize||y<0||y>=len){
                        continue;
                    }
                    cell[x][y]++;
                }
            }
        }
    }
//每遇到一个活细胞就更新每个细胞周围的活细胞数量
    for(int i = 0;i<boardSize;i++){
        for(int j = 0;j<len;j++){
            if((cell[i][j]>3||cell[i][j]<2)&&board[i][j]==1){
                board[i][j]=0;
            }
            else if(board[i][j]==0&&cell[i][j]==3){
                board[i][j] = 1;
            }
        }
    }
//简单的遍历cell数组，按题设条件变更board
}
