
int sumOfLife(int** board, int i, int j, int row, int col)
{
    int sum = 0;

    //printf("board=%d,i=%d,j=%d,row=%d,col=%d\n",board[i][j],i,j,row,col);
    if ((i-1>=0) && (j-1>=0)) { // 左上角
        sum = sum + board[i-1][j-1];
    }

    if ((i-1>=0) && (j>=0)) { // 上
        sum = sum + board[i-1][j];
    }

    if ((i-1>=0) && (j+1<col)) { // 右上角
        sum = sum + board[i-1][j+1];
    }

    if ((i>=0) && (j-1>=0)) { // 左
        sum = sum + board[i][j-1];
    }

    if ((i>=0) && (j+1<col)) { // 右
        sum = sum + board[i][j+1];
    }


    if ((i+1<row) && (j-1>=0)) { // 左下角
        sum = sum + board[i+1][j-1];
    }

    if ((i+1<row) && (j<col)) { // 下
        sum = sum + board[i+1][j];
    }

    if ((i+1<row) && (j+1<col)) { // 右下角
        sum = sum + board[i+1][j+1];
    }

    return sum;
}

void gameOfLife(int** board, int boardSize, int* boardColSize)
{    
    int i;
    int j;
    int sum=0;
    int** outboard = (int*)malloc((sizeof(int*))*boardSize); // 为二维数组分配boardSize行

    for(i = 0; i < boardSize; i++) {
        *(outboard + i)=(int *)malloc((*boardColSize) * (sizeof(int))); // 为每列分配* boardColSize个大小空间 
    }

    for (i=0; i<boardSize; i++) {
        for (j=0; j<*boardColSize; j++) {
            outboard[i][j]=board[i][j];
        }
    }

    for (i=0; i<boardSize; i++) {
        for (j=0; j<*boardColSize; j++) {

            sum = sumOfLife(outboard,i,j,boardSize,*boardColSize);

            if (outboard[i][j]==1) {
                if (sum < 2) {
                    board[i][j] = 0; 
                }

                if (sum == 2 || sum == 3 ) {
                    board[i][j] = 1; 
                }

                if (sum > 3 ) {
                    board[i][j] = 0; 
                }
            } else {
                if (sum == 3 ) {
                    board[i][j] = 1; 
                }
            }
        }
    }

    // 释放动态开辟的空间 
    for (i = 0; i < boardSize; ++i) { 
        free(outboard[i]); 
    } 
    free(outboard); 
}