### 解题思路
之前在写遍历题时，DFS和BFS都选择了DFS（感觉相对代码简洁），层次遍历不属于递归，需要用到队列进行迭代，之前只是学习了原理，今日实操，证明还是要先学会理论，逻辑思路清晰了，就容易了。

采用顺序表记录  每一个时间节点，腐蚀苹果的队列，排队进行下一轮腐蚀。利用LENGTH队列长度记录每一轮腐蚀的分界线，再用是否还有好苹果返回-1；缺点是内存消耗好像比较大~可以用链式的试试。

### 代码

```c
typedef struct {
    int x;
    int y;
}Queue;//顺序表，可改为链式结构，减少内存消耗

int orangesRotting(int** grid, int gridSize, int* gridColSize){
Queue *queue=malloc(sizeof(Queue)*100);//BFS队列存储下一步进行感染的橘子
int queue_high=0,queue_low=0;//队头队尾
int Length=0;//层次遍历时，每一层的队列长度
int Xshift[4]={-1,0,1,0};
int Yshift[4]={0,-1,0,1};
int times=0;//迭代时间
for(int i=0;i<gridSize;i++){//找第一批坏橘子
    for(int j=0;j<*gridColSize;j++)
    {
        if (grid[i][j]==2)
        {
            queue[queue_high].x=i;
            queue[queue_high].y=j;
            queue_high++;
            //printf("X=%d     Y=%d    %d\n",i,j,queue_high);
        }
    }
}
Length=queue_high-queue_low;
while(queue_high!=queue_low)//队列非空
{ 
    for (int k=0;k<4;k++)
    {
        int X=queue[queue_low].x+Xshift[k];
        int Y=queue[queue_low].y+Yshift[k];
        //printf("X=%d     Y=%d\n",X,Y);
        if(0<=X&&X<gridSize&&*gridColSize>Y&&Y>=0&&grid[X][Y]==1)
        {
            grid[X][Y]=2;//感染 后需放入队列
            queue[queue_high].x=X;
            queue[queue_high].y=Y;
            queue_high++;
            //printf("X=%d     Y=%d\n",X,Y);
        }
    }
    queue_low++;
    Length--;
    if(Length==0)//遍历完一层
    {
        Length=queue_high-queue_low;
        if(Length!=0) times++;
        //printf("times=%d\n",times);
    }
}

for(int i=0;i<gridSize;i++){//找 好橘子
    for(int j=0;j<*gridColSize;j++)
    {
        if (grid[i][j]==1) return -1;
    }
}
return times;
}
```