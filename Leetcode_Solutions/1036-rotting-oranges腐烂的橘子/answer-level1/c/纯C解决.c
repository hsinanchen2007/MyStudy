### 解题思路
这道题我个人觉得不应该给easy吧，没有hard也给个medium吧.....

这道题就是说坏橘子的四个方向如果存在好橘子那么就会被感染，那么我们可以想到递归，对每一个坏橘子的四周进行感染操作。每一次对网格中的所有的坏橘子四周的橘子同时进行感染。

这道题的难点就是在于如何保证同时进行感染，语言是一个个橘子进行操作，那么我们可以把所有坏橘看成一个大整体，然后再去感染其他橘子，于是如何把坏橘子看成整体就成了关键。我这里想到了利用栈，其实队列也可以，先后顺序无所谓。

我把坏橘子统一入感染栈，把坏橘子四周的橘子入待感染栈。

这里需要注意一下这一轮感染栈会是下一轮的待感染栈，对于栈进行重复利用。

1. 对于递归我们常常需要剪枝，这里的剪枝就是坏橘子能够感染的橘子已经没有了，但是还存在好句子就结束。这也算是结束条件吧。

### 代码

```c
#define MaxSize 100
void countMin(int** grid, int gridSize, int* gridColSize,int *stack_x,int *stack_y,int *stack_X,int *stack_Y,int top,int Top,int *count,int *orange)
{
    if(top==-1)//空栈
    return;
    int flag=0;
    int dir_y[4]={-1,0,0,1};//方向数组
    int dir_x[4]={0,-1,1,0};
    int i,j;
    int new_x,new_y;
    int pos_x,pos_y;
    for(top;top>=0;top--)
    {   
 
        pos_x=stack_x[top];
        pos_y=stack_y[top];
        for(j=0;j<4;j++)
        {
            new_x=pos_x+dir_x[j];
            new_y=pos_y+dir_y[j];
            if((new_x>=0&&new_x<gridSize)&&(new_y>=0&&new_y<*gridColSize))//在网格之内
                if(grid[new_x][new_y]==1)//可感染的入栈
                {
                //    printf("22222\n");
                    (*orange)--;
                    grid[new_x][new_y]=2;
                    flag=1;
                    stack_X[++Top]=new_x;
                    stack_Y[Top]=new_y;
                }
        }
        
    }
    if(flag==1)//若存在可感染的情况才能够加时间
    (*count)++;
    countMin(grid,gridSize,gridColSize,stack_X,stack_Y,stack_x,stack_y,Top,top,count,orange);
}
int orangesRotting(int** grid, int gridSize, int* gridColSize){//先行后列
int stack_x[MaxSize];//感染栈
int stack_y[MaxSize];
int stack_X[MaxSize];//待感染栈
int stack_Y[MaxSize];
int top=-1;
int Top=-1;
int count=0;
int orange=0;
int i,j;
    for(i=0;i<gridSize;i++)//行遍历
        for(j=0;j<*gridColSize;j++)//列遍历
        {
            if(grid[i][j]==2){//坏橘子入栈
            stack_x[++top]=i;
            stack_y[top]=j;
        }
        else if(grid[i][j]==1)
            orange++;
        }
    countMin(grid,gridSize,gridColSize,stack_x,stack_y,stack_X,stack_Y,top,Top,&count,&orange);
    if(orange==0)
    return count;
    return -1;
}
```