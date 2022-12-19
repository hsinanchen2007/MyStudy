刚开始忘了加回溯子函数的终止条件，返回了最原始的board。。。
```
bool backtrack(int row,int column,char **board,int**hashrow,int **hashcol,int **subboard);
void inithash(char **board,int**hashrow,int **hashcol,int **subboard);
bool isok(int i,int row,int column,int**hashrow,int **hashcolcol,int **subboard);
void freshhash(int i, int row, int column, int**hashrow,int **hashcolcol,int **subboard);

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int row=0,column=0;
    int **hashrow=(int **)malloc(9*sizeof(int*));           //行哈希表
    for(int i=0;i<9;i++){
        hashrow[i]=(int *)calloc(10,sizeof(int));
    }
    int **hashcol=(int **)malloc(sizeof(int *)*9);          //列哈希表
    for(int i=0;i<9;i++){
        hashcol[i]=(int *)calloc(10,sizeof(int));
    }
    int **subboard=(int **)malloc(sizeof(int*)*9);          //子块哈希表
    for(int i=0;i<9;i++){
        subboard[i]=(int *)calloc(10,sizeof(int));        
    }
    inithash(board,hashrow,hashcol,subboard);                //哈希表初始化
    backtrack(0,0,board,hashrow,hashcol,subboard);   
}
bool backtrack(int row,int column,char **board,int**hashrow,int **hashcol, int **subboard){
    if(row==9){                 //8*8位置的已完成，跳到了下一个
        return true;
    }
    else{
        while(board[row][column]!='.'){     //找空着的格子
            if(row==8&&column==8){          //最后一个非空 直接返回
                return true;               
            }
            else if(column==8){
                row++;
                column=0;
            }
            else{
                column++;
            }
        }
        for(int i=1;i<=9;i++){
            if(isok(i,row,column,hashrow,hashcol,subboard)){
                board[row][column]=(char)(i+'0');             
                if(column==8){
                    //下面不能将row+1之后再传入子函数，因为那样就改变本函数中row的值了
                    if(backtrack(row+1,0,board,hashrow,hashcol,subboard)){
                        return true;
                    }
                }
                else{
                    if(backtrack(row,column+1,board,hashrow,hashcol,subboard)){
                        return true;
                    }
                }
                //改回已经改掉的哈希表
                freshhash(i,row,column,hashrow,hashcol,subboard);
                //改回已经改掉的表盘
                board[row][column]='.';   //这里不重置的话最后返回到上衣循环一个‘9’就出错了                    
            }                                                
        }
    }
    return false;    //最后一定要有这个返回false值
}

void inithash(char **board,int**hashrow,int **hashcol, int **subboard){
    int row, column;
    for(row=0;row<9;row++){
        for(column=0;column<9;column++){
            if(board[row][column]!='.'){
                hashrow[row][board[row][column]-'0']=1;
                hashcol[column][board[row][column]-'0']=1;
                subboard[(row/3)*3+column/3][board[row][column]-'0']=1;
            }
        }
    }
}
bool isok(int i,int row,int column,int**hashrow,int **hashcol,int **subboard){
    if(hashrow[row][i]==1||hashcol[column][i]==1||subboard[row/3*3+column/3][i]==1){
        return false;
    }
    else{
        //别忘了下面更新hash表
        hashrow[row][i]=1;                 
        hashcol[column][i]=1;
        subboard[row/3*3+column/3][i]=1;
        return true;
    }
}
void freshhash(int i, int row, int column, int**hashrow,int **hashcol,int **subboard){
    hashrow[row][i]=0;                 
    hashcol[column][i]=0;
    subboard[row/3*3+column/3][i]=0;
}
```
![image.png](https://pic.leetcode-cn.com/982856a9bf4d86d7cc851941b82fab2bf868e4950cea4b3607edbd8de8171f97-image.png)
