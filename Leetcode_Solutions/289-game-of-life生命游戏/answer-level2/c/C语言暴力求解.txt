### 解题思路
此处撰写解题思路
靠边元素的周边元素为0，把[i,j]位置周边8个位置的元素列出来后相加求和，然后根据当前元素的值和周边元素和的值进行判断
### 代码

```c

int fun(int** board ,int i ,int j, int boardSize,int boardColSize)
{
     if((i>=0 &&i<boardSize)&&(j>=0 &&j<boardColSize))
         return board[i][j];
     else return 0;
}




void gameOfLife(int** board, int boardSize, int* boardColSize)
{
    int **temp;    
    int i, j;   
    int sum = 0;
    int col = *boardColSize;
    temp = (int**)malloc(sizeof(int*)*boardSize);//为二维数组分配3行   
    for (i = 0; i < boardSize; ++i)
    {//为每列分配4个大小空间        
        temp[i] = (int*)malloc(sizeof(int)*(*boardColSize));  
    }  
    //printf("boardSize= %d ,*boardColSize = %d",boardSize,*boardColSize)  ;
    //初始化    
    for (i = 0; i < boardSize; ++i)
    {        
        for (j = 0; j < *boardColSize; ++j)
        {           
             temp[i][j] = 0;      
        }    
    }
    for(i= 0;i<boardSize;i++)
    {
        for(j = 0 ;j < *boardColSize; ++j)
        {
              sum = fun(board,i-1,j,boardSize,col)
                   +fun(board,i-1,j-1,boardSize,col)
                   +fun(board,i-1,j+1,boardSize,col)
                   +fun(board,i,j-1,boardSize,col)
                   +fun(board,i,j+1,boardSize,col)
                   +fun(board,i+1,j,boardSize,col)
                   +fun(board,i+1,j-1,boardSize,col)
                   +fun(board,i+1,j+1,boardSize,col);
                   //printf("i= %d,j=%d,sum=%d ",i,j,sum);
              if(board[i][j] ==0)
              {
                  if(sum==3)
                  {
                      temp[i][j] = 1;
                  }      
              }
              else
              {
                  if(sum==2 || sum==3)
                  {
                      temp[i][j] = 1;
                  }
                  else
                  {
                      temp[i][j] = 0;
                  }
              }
        }
    }
    for (i = 0; i < boardSize; ++i)
    {        
        for (j = 0; j < *boardColSize; ++j)
        {           
            board[i][j] = temp[i][j] ;      
        }    
    }




}
```