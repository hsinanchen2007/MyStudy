### 解题思路
根据每个细胞周围的活细胞数量更新细胞的状态。因为原数据处理过程中会更新，需要复制下原数据，用于检测细胞周围的个数。
思路很简单。复制一个board_copy,两层for循环检测每个坐标周围的活细胞数量。根据活细胞数量更新board坐标的状态。
创建coordislive函数判断board_copy[i][j]是否是活细胞：坐标有效且存活返回1 ，无效或者是死细胞返回0；
创建livenum判断某个坐标周围活细胞数量：前后左右四个斜角活细胞个数相加，调用八次coordislive即可

#################################
执行用时 :4 ms, 在所有 C 提交中击败了68.38%的用户
内存消耗 :5.5 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
//判断该坐标有效且存活返回1 ，无效或者是死细胞返回0
int coordislive(int** board_copy,int boardSize, int boardColSize,int row,int col)
{
    if((row<0)||(row >= boardSize)||(col <0)||(col >= boardColSize)) //出界 return0
        return 0 ;
    else
        return board_copy[row][col];
}
//判断周围活细胞个数
int livenum(int** board_copy,int boardSize, int* boardColSize,int row,int col)//board_copy[i][j]周围坐标的个数
{
    int ret=0;
    ret = coordislive(board_copy, boardSize, boardColSize[0], row+1, col) + \
          coordislive(board_copy, boardSize, boardColSize[0], row-1, col) + \
          coordislive(board_copy, boardSize, boardColSize[0], row, col+1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row, col-1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row-1, col-1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row+1, col+1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row-1, col+1) + \
          coordislive(board_copy, boardSize, boardColSize[0], row+1, col-1) ;
    return ret ;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    
    //1 复制board
    int** board_copy ; //用于保存原始记录
    board_copy = (int**) malloc(boardSize*sizeof(int*));
    for(int i=0;i < boardSize;i++){
        board_copy[i] = (int*) malloc(boardColSize[i]*sizeof(int*));
        for(int j= 0;j<boardColSize[i];j++){
            board_copy[i][j] = board[i][j];
        }
    } 
    //2 开始更新细胞状态
    for(int i=0;i < boardSize;i++){
        for(int j= 0;j<boardColSize[i];j++){
            int tmp = livenum(board_copy,boardSize, boardColSize,i,j);
            //3 按照活细胞个数更新细胞状态
            if(board_copy[i][j]==1){ //细胞是活的
                if((tmp < 2)||(tmp > 3)) //如果活细胞数少于两个或者大于3个，则该位置活细胞死亡
                    board[i][j] = 0;
            }
            else{
                if(tmp == 3) //正好3个复活
                    board[i][j] = 1;  
            }
        }
    }
    
}
```