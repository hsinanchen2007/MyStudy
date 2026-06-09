### 解题思路
此处撰写解题思路

采用自我广播方式记录细胞更新状态
创建一个board_c数组用来记录细胞周围八个格子的活细胞数

开始时遍历每个活细胞向周围八个格子（边缘的小于八个）广播，让它们加一  （遍历一次 复杂度o（m×n））
再遍历每个活细胞对应的board_c数组，按照规则更新                      （遍历第二次  复杂度o（m×n））

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){

    //防止输入为一维或者空时定义出错 每一个维度要多申请一个位置
    int board_c[boardSize+1][*boardColSize+1];
    memset(board_c,0,sizeof(board_c));
    
   
    //用来记录i，j是否在左右、上下边界
    int x_1flag=0,x1flag=0,y_1flag=0,y1flag=0;
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            //有活细胞加一 没有活细胞就不用操作
            if(board[i][j])
            {
            x_1flag=(j==0)?0:1;
            x1flag=(j==*boardColSize-1)?0:1;
            y_1flag=(i==0)?0:1;
            y1flag=(i==boardSize-1)?0:1;
            
            if(x_1flag) 
            {
                board_c[i][j-1]+=1;
                if(y1flag)
                    board_c[i+1][j-1]+=1;
                if(y_1flag)
                    board_c[i-1][j-1]+=1;
                    
            }
            if(x1flag)
            {
                board_c[i][j+1]+=1;
                if(y1flag)
                    board_c[i+1][j+1]+=1;
                if(y_1flag)
                    board_c[i-1][j+1]+=1;
                
            }
            if(y1flag)
                    board_c[i+1][j]+=1;
            if(y_1flag)
                    board_c[i-1][j]+=1;
                
            }
            
        }
    }
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            if(board_c[i][j]==3)
                board[i][j]=1;
            else if(board_c[i][j]<2 || board_c[i][j]>3)
                board[i][j]=0;
        }
        
    }


}
```