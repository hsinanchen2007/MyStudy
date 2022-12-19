### 解题思路
主要是三步
1：遍历一遍找出所有原始烂橘子，把这些烂橘子放入队列，这些烂橘子的腐烂时间（rottime）记为t=0
2：循环，只要队列不为空，取出一个烂橘子，把这个烂橘子四周的好橘子变成烂橘子，在图中标记变为2+t+1，
   新感染的烂橘子放入队列，腐烂时间记为t+1
3：清理，遍历地图，发现还有好橘子（grid[][]==1）就直接返回-1，否则就比较每个烂橘子(grid[][]>2)的
   腐烂时间（t=grid[][]-2）,找出最大值即为答案
坑：int gridSize, int* gridColSize 模板里面给的这两个参数给我整懵逼了，不知道干啥的，尝试输出这
   两个值，发现都是3，地图的行列大小？但是谁是行谁是列？为啥有一个还是指针？？？琢磨了一下colsize应该
   是列的长度吧，总不能是列的数量吧，数量怎么能叫size呢。不管，先写程序，写完程序测试样例过了，长宽都
   是3，没毛病，提交，报错：heap overflow，最后输入[[0,2]],到这我才知道，行列整反了，行列一换就通过了。
   我寻思这个size的意思就离谱儿！
改进：自己写的队列，虽然可以熟悉下队列的实现，但是实战中没有特别要求还是用库函数比较好，也不知道这个c里
   面能不能用c++的queue函数，还是要学会用库函数。其他的，看看其他题解看看有没有小妙招，比如怎么找到不可能
   腐烂的橘子。还有内存消耗才击败12%。。。。

### 代码

```c
//int test=2;
typedef struct MYQUEUE_NODE{
    int x;
    int y;
    int rotTime;
    struct MYQUEUE_NODE *next;
}MyQueueNode;

MyQueueNode *front,*rear;

void mq_insert(int,int,int);
MyQueueNode *mq_delete(void);
bool mq_is_empty(void);

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    //printf("%d %d\n",gridSize,*gridColSize);
    int ans=0;
    int rowSize=*gridColSize;
    int colSize=gridSize;
  //  grid[0][0]=0;
 //   grid[0][1]=2;
  //  int rowSize=2;
  //  int colSize=1;
    for(int i=0;i<colSize;i++)
    {
        for(int j=0;j<rowSize;j++)
        {
           // printf("%d ",grid[i][j]);
           if(grid[i][j]==2) //找到原始烂橘子放入队列，rottime=0
           {
               mq_insert(i,j,0);
           }
        }
        //printf("\n");
    }
    MyQueueNode *rotOrange;
    int i,j,t;
    while(!mq_is_empty())
    {
        rotOrange=mq_delete(); //取出烂橘子
        i=rotOrange->x;
        j=rotOrange->y;
        t=rotOrange->rotTime;
        //printf("out:%d %d %d\n",i,j,t);
        //向四周传染
        if(i>0)//up
        {
            if(grid[i-1][j]==1)
            {
                grid[i-1][j]=2+t+1;
                mq_insert(i-1,j,t+1);
            }
        }
        if(i+1<colSize)//down
        {
            if(grid[i+1][j]==1)
            {
                grid[i+1][j]=2+t+1;
                mq_insert(i+1,j,t+1);
            }
        }
        if(j>0)//left
        {
            if(grid[i][j-1]==1)
            {
                grid[i][j-1]=2+t+1;
                mq_insert(i,j-1,t+1);
            }
        }
        if(j+1<rowSize)//right
        {
            if(grid[i][j+1]==1)
            {
                grid[i][j+1]=2+t+1;
                mq_insert(i,j+1,t+1);
            }            
        }
    }

    //清理所有橘子
    for(int i=0;i<colSize;i++)
    {
        for(int j=0;j<rowSize;j++)
        {
            if(grid[i][j]==1)
            {
                return -1;
            }
            else if(grid[i][j]>2)
            {
                ans=ans>(grid[i][j]-2)?ans:(grid[i][j]-2);
            }
        }
    }

    return ans;
     /*
    printf("%dxxxxxxx",test);
    return 0;
   */
}

void mq_insert(int i,int j,int rt)
{
   // printf("in:%d %d %d\n",i,j,rt);
    MyQueueNode *new_node;
    new_node=(MyQueueNode *)malloc(sizeof(MyQueueNode));
    new_node->x=i;
    new_node->y=j;
    new_node->rotTime=rt;
    new_node->next=NULL; //因为是加到尾巴所以next一定是NULL
    //printf("%d %d %d\n",new_node->x,new_node->y,new_node->rotTime);
    if(rear==NULL)
    {
        front=rear=new_node;
    }
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
}

MyQueueNode *mq_delete(void)
{
    MyQueueNode *tmp;
    tmp=front;
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    return tmp;
}

bool mq_is_empty(void)
{
    if(front==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```