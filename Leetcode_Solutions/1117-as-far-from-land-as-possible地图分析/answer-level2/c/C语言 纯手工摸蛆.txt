### 解题思路
能通过就不错了。。用辅助队列进行广度优先搜索，其实核心思路跟二叉树的层次遍历一样的。
对我一个外行，发现深度优先搜索和广度优先搜索很值得熟练应用。

### 代码

```c
#define MAX(a,b) ((a>b) ? a : b)
#define MIN(a,b) ((a<b) ? a : b)
#define MAXSIZE 10

typedef struct{
    int x[MAXSIZE];
    int y[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

SeqQueue* createSeqQueue();
int QueueLength(SeqQueue* obj);
bool QueueEmpty(SeqQueue* obj);
bool QueueFull(SeqQueue* obj);
void EnQueue(SeqQueue* obj, int i, int j);
void DeQueue(SeqQueue* obj);
void PrintQueue(SeqQueue* obj);

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int i, j, k, max = -1, distance, count;

    for(i=0; i<gridSize; i++)
    {
        for(j=0; j<*gridColSize; j++)
        {
            //对每一个海洋进行广度优先搜索
            if(grid[i][j] == 0){
                //距离初始化
                distance = -1;

                //初始化队列和访问状态数组
                SeqQueue* Q = createSeqQueue();
                bool visited[100][100] = {false};

                //存入当前海洋并开始记录状态和计数
                EnQueue(Q, i, j);
                visited[i][j] = true;
                count = 1;

                //广度优先搜索
                while(!QueueEmpty(Q)){
                    //当距离更远一步的区域存在时，距离加1，记录队尾
                    //PrintQueue(Q);
                    distance++;
                    k = Q->rear;
                    int m, n; //临时记录弹出的队头坐标
                    bool flag = false; //是否找到最近陆地的标志

                    //一次将所有相同距离的区域全部遍历
                    while(Q->front != k){
                        //弹出队头海洋
                        m = Q->x[Q->front];
                        n = Q->y[Q->front];
                        DeQueue(Q);

                        //每次弹出一个海洋，就马上存入上、下、左、右四块区域
                        //如果是陆地，则中断双层while循环
                        //如果是海洋，则入队，并设为已访问状态
                        if(m>0 && !visited[m-1][n]){
                            if(grid[m-1][n] == 1){
                                distance++;
                                flag = true;
                                break; //中断内层while循环
                            }
                            else{
                                EnQueue(Q,m-1,n);
                                visited[m-1][n] = true;
                            }
                        }

                        if(m<gridSize-1 && !visited[m+1][n]){
                            if(grid[m+1][n] == 1){
                                distance++;
                                flag = true;
                                break;
                            }
                            else{
                                EnQueue(Q,m+1,n);
                                visited[m+1][n] = true;
                            }
                        }

                        if(n>0 && !visited[m][n-1]){
                            if(grid[m][n-1] == 1){
                                distance++;
                                flag = true;
                                break;
                            }
                            else{
                                EnQueue(Q,m,n-1);
                                visited[m][n-1] = true;
                            }
                        }

                        if(n<*gridColSize-1 && !visited[m][n+1]){
                            if(grid[m][n+1] == 1){
                                distance++;
                                flag = true;
                                break;
                            }
                            else{
                                EnQueue(Q,m,n+1);
                                visited[m][n+1] = true;
                            }
                        }
                    }
                    
                    //如果找到最近陆地，则中断外层while循环
                    if(flag)
                        break;
                    
                    //计数已经遍历的区域，如果全部找完，则表明全部为0，返回-1；
                    count += QueueLength(Q); 
                    if(count == gridSize*(*gridColSize))
                        return -1;
                }
                //保存已经搜索过的海洋的距离最大值
                max = MAX(max, distance);
                free(Q); //释放队列内存
            }
        }
    }
    return max;
}

//定义循环队列并初始化
SeqQueue* createSeqQueue(){
    int i;
    SeqQueue* obj;
    obj = (SeqQueue *)malloc(sizeof(SeqQueue));
    obj->front = 0;
    obj->rear = 0;
    return obj;
}

//队列长度
int QueueLength(SeqQueue* obj){
    return (obj->rear - obj->front + MAXSIZE)%MAXSIZE;
}

//队列是否为空
bool QueueEmpty(SeqQueue* obj){
    return obj->front == obj->rear;
}

//队列是否为满
bool QueueFull(SeqQueue* obj){
    return (obj->rear+1)%MAXSIZE == obj->front;
}

//入队
void EnQueue(SeqQueue* obj, int i, int j){
    if( (obj->rear+1)%MAXSIZE != obj->front ){
        obj->x[obj->rear] = i;
        obj->y[obj->rear] = j;
        obj->rear = (obj->rear+1)%MAXSIZE;
    }
}

//出队
void DeQueue(SeqQueue* obj){
    if(obj->front != obj->rear)
        obj->front = (obj->front+1)%MAXSIZE;
}

//遍历队列
void PrintQueue(SeqQueue* obj){
    int i, k;
    if(!QueueEmpty(obj)){
        for(i=0; i<QueueLength(obj); i++){
            k = (i+obj->front)%MAXSIZE;
            printf("[%d,%d] ", obj->x[k], obj->y[k]);
        }
    }
    printf("\n");
}

```