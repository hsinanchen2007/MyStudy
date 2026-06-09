### 解题思路
参考热门题解

### 代码

```c
//使用bfs算法得到陆地到海洋的最远距离
//遍历的层数就是所求的值

int maxDistance(int** grid, int gridSize, int* gridColSize){
    
//创建队列
int  queue [gridSize*gridSize][2];
//将所有的陆地放入队列

//top tail记录队列队首和队尾
int top=-1;
int tail =-1 ;
for(int i=0; i < gridSize ;i++)
{
    for(int  j =0 ;j < gridSize;j++ )
    {

            if(grid[i][j]== 1){
                 tail++;
                queue[tail][0] = i;//记录左边x
                queue[tail][1] =j;//记录坐标y
               

            } 
    }
}
if(tail ==gridSize*gridSize-1 ) return -1;

//bfs遍历直到所有的节点都不为0
//即所有的节点都被访问

int distance =0;
//记录方向
int dx[4]={-1,+1,0,0};
int dy[4]={0,0,-1,+1};
int tmp_tail =tail;
while(top<tail){
    distance++;
    while(top<tmp_tail){
        top++;//队首出队queue[top]
       //查看队首节点周围是否未被访问过的海洋，即为0的节点
        for(int i =0 ; i< 4;i++)
        {
            //超出边界或者已经访问的节点就不再访问
            if(queue[top][0]+dx[i]>=0&&queue[top][1]+dy[i]>=0&&queue[top][0]+dx[i]<gridSize&&queue[top][1]+dy[i]<gridSize&&grid[ queue[top][0]+dx[i] ][ queue[top][1]+dy[i] ]==0){
                
                grid[ queue[top][0]+dx[i] ][ queue[top][1]+dy[i] ]=distance;//标记被访问
                tail++;
                queue[tail][0] = queue[top][0]+dx[i];
                queue[tail][1]=queue[top][1]+dy[i];

            }

        }

    }
   
    tmp_tail=tail;
}

return distance-1;
}
```