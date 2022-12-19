**思路**
首先最容易想到的是对于每一个1进行BFS,但是这样就会增加无用的遍历次数
所以提出一个优化方案
即不对1而对0进行多源BFS,逆向遍历相当于在1处存储信息，可以减少无用遍历次数
具体参考代码如下
```
typedef struct
{
    int x;
    int y;
}pair;  //坐标结构体

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int row=matrixSize;
    int col=*matrixColSize;
    int i,j;
    
    int dirc[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//方向字典
    
    int front=0,rear=0;
    pair *Q=(pair *)malloc(sizeof(pair)*row*col+1);
    int **res=(int **)malloc(sizeof(int *)*row);
    for(i=0;i<row;i++)
    {
        res[i]=(int *)malloc(sizeof(int)*col);
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(matrix[i][j]==0)
            {
                res[i][j]=0;
                Q[rear].x=i;
                Q[rear++].y=j;
            }
            else
            {
                res[i][j]=INT_MAX;//通过广度优先搜索改变其值
            }
        }
    }
    while(front!=rear)
    {
        pair cur;
        cur.x=Q[front].x;
        cur.y=Q[front++].y;//出队
        pair now;
        for(i=0;i<4;i++)
        {
            now.x=cur.x+dirc[i][0];
            now.y=cur.y+dirc[i][1];
            if(now.x>=0&&now.x<row&&now.y>=0&&now.y<col)
            {
                if(res[now.x][now.y]>res[cur.x][cur.y]+1)
                {
                    res[now.x][now.y]=res[cur.x][cur.y]+1;
                    Q[rear].x=now.x;
                    Q[rear++].y=now.y;//有符合的1入队，之后这个1出队相当于再以这个1进行BFS
                } 
            }
        }
        
    }
    *returnSize=row;
    *returnColumnSizes=matrixColSize;
    return res;
}
```
