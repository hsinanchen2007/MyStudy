### 解题思路
BFS+队列+访问矩阵。

从（0,0）坐标开始，广度搜索原则是距离原点距离相同的点。
符合条件就入队，且记录访问状态，累加每一次队列的长度。
每弹出一个点，就判断其下面的点和右边的点，若满足和小于k，且没有访问过，则入队。
一直到队列为空停止。

还可以用其他方法搜索，比如一列一列或一行一行地进行。

### 代码

```c
#define MAXSIZE 100

typedef struct{
    int i;
    int j;
}Position;

typedef struct{
    Position* data[MAXSIZE*MAXSIZE];
    int front;
    int rear;
}SeqQueue;

Position* createPosition(int i, int j);
int sum(Position* p);
SeqQueue* createSeqQueue();
int QueueLength(SeqQueue* obj);
bool QueueEmpty(SeqQueue* obj);
bool QueueFull(SeqQueue* obj);
void EnQueue(SeqQueue* obj, Position* p);
Position* DeQueue(SeqQueue* obj);

int movingCount(int m, int n, int k){
    bool visit[MAXSIZE][MAXSIZE] = {false}; //访问状态
    int l, count=0;

    SeqQueue* S = createSeqQueue(); //建立队列
    Position* p = createPosition(0,0); 
    EnQueue(S, p); //首先入队原点
    visit[p->i][p->j] = true;

    while(!QueueEmpty(S)){
        count += QueueLength(S); //同一距离点的队列计算个数累加

        l = S->rear; //记录同一距离点的队尾
        //将同一距离的点全部出队
        while(S->front != l){
            Position* pt = DeQueue(S); //临时记录出队队头

            //判断队头下面的点是否满足条件，满足则入队
            if(pt->i+1 < m && !visit[pt->i+1][pt->j]){
                Position* pd = createPosition(pt->i+1, pt->j);
                if(sum(pd) <= k){
                    EnQueue(S, pd);
                    visit[pd->i][pd->j] = true;
                }
            }
            
            //判断队头右面的点是否满足条件，满足则入队
            if(pt->j+1 < n && !visit[pt->i][pt->j+1]){
                Position* pr = createPosition(pt->i, pt->j+1);
                if(sum(pr) <= k){
                    EnQueue(S, pr);
                    visit[pr->i][pr->j] = true;
                }
            }
        }
    }

    return count;
}

//产生位置
Position* createPosition(int i, int j){
    Position* p;
    p = (Position *)malloc(sizeof(Position));
    p->i = i;
    p->j = j;
    return p;
}

//计算行坐标和列坐标的数位之和
int sum(Position* p){
    int i = p->i;
    int j = p->j;
    return (i/10) + (i%10) + (j/10) + (j%10);
}

//定义循环队列并初始化
SeqQueue* createSeqQueue(){
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
void EnQueue(SeqQueue* obj, Position* p){
    if( (obj->rear+1)%MAXSIZE != obj->front ){
        obj->data[obj->rear] = p;
        obj->rear = (obj->rear+1)%MAXSIZE;
    }
}

//出队
Position* DeQueue(SeqQueue* obj){
    if(obj->front != obj->rear){
        int k = obj->front;
        obj->front = (obj->front+1)%MAXSIZE;
        return obj->data[k];
    }
    return NULL;
}

```