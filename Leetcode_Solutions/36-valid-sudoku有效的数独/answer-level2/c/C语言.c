```
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i,j,m,n;
    int nums[10]={0};
    for (i=0;i<9;i=i+3){
        for (j=0;j<9;j=j+3){
            memset(nums,0,sizeof(int)*10);
            for (m=0;m<3;m++){
                for (n=0;n<3;n++){
                    if(board[i+m][j+n]!='.')//统计九格中数字出现的次数
                        if (++nums[board[i+m][j+n]-'0']==2)
                            return false;
                }
            }
        }
    }
    for (j=0;j<*boardColSize;j++){
        memset(nums,0,sizeof(int)*10);
        for (i=0;i<boardSize;i++){//统计每一列的数字
            if(board[i][j]!='.')
                if (++nums[board[i][j]-'0']==2)
                    return false;
        }
    }
    for (i=0;i<boardSize;i++){
        memset(nums,0,sizeof(int)*10);
        for (j=0;j<*boardColSize;j++){//统计每一行的数字
            if(board[i][j]!='.')
                if (++nums[board[i][j]-'0']==2)
                    return false;
        }
    }
    return true;
}
```
