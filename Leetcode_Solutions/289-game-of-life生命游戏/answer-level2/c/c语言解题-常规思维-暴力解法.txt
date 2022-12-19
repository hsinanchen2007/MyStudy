### 解题思路
此处撰写解题思路

### 代码

```c
//统计活细胞个数
int get_huo_shu(int **board, int all_hang, int all_lie,int m,int n){
    //要判断的元素的m为行，n为列
    //数组总的行：all_hang，总的列 all_lie
    //八个方向的判断。
    int count=0;
       //1
        if( (m-1)>=0 && (n-1)>=0 ){
            if(board[m-1][n-1] ==1){
                count++;
            }
        }
        //2
        if((m-1)>=0){
            if(board[m-1][n]==1){
                count++;
            }
        }
        //3
        if( (m-1)>=0 && (n+1)<=all_lie){
            if(board[m-1][n+1] ==1){
                count++;
            }
        }

        //4
        if((n-1)>=0){
            if(board[m][n-1] ==1){
                count++;
            }
        }
        //5
        if((n+1)<=all_lie){
            if(board[m][n+1] ==1){
                count++;
            }
        }
        //6
        if((m+1)<=all_hang && (n-1)>=0 ){
            if(board[m+1][n-1] ==1){
                count++;
            }
        }
        //7
        if((m+1)<=all_hang ){
            if(board[m+1][n] ==1){
                count++;
            }
        }
        //8
        if((m+1)<=all_hang  && (n+1)<=all_lie){
            if(board[m+1][n+1] ==1){
                count++;
            }
        }
        
    
    printf("m=%d,n=%d,count=%d\n",m,n,count);
    return count;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int new_row = boardSize ;
    int new_col = *boardColSize;
    int new_board[new_row+1][new_col+1];
    memset(new_board,0,sizeof(new_board));
    int m=0,n=0;
    //把每个位置的结果备份
    for(m=0;m<new_row ; m++){
        for(n=0;n<new_col ;n++){
            int a=get_huo_shu(board,new_row-1,new_col-1,m,n);
            new_board[m][n]=a;
        }
    }
    //根据每个位置的结果做判断
    for(m=0;m<new_row;m++){
         for(n=0;n<new_col ;n++){
             if(board[m][n]==1){
                 if(new_board[m][n]<2){
                   board[m][n]=0;  
                 }else if(new_board[m][n]==2 || new_board[m][n]==3){
                    board[m][n]=1; 
                 }else if(new_board[m][n]>3){
                     board[m][n]=0; 
                 }
             }else{
                 if(new_board[m][n]==3){
                     board[m][n]=1; 
                 }
             }
             
         }

    }
}
```