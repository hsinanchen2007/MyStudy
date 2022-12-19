### 解题思路
此处撰写解题思路
常规BFS
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//定义节点
typedef struct node{
    int x;
    int color;
    struct node * next;
}node;


//定义队列（保存队首和队尾指针）
typedef struct queue_link{
    node * front;
    node * rear;
}que;

//初始化队列
que * InitQueue()
{
    que * q = (que*)malloc(sizeof(que));
    q->front = q->rear = NULL;
    return q;
}


//判断队列是否为空
int EmptyQueue(que * q)
{
   return q->front == NULL;
}

//入队
void InsertQueue(que *q, int nx, int col)
{
    node * n = (node *)malloc(sizeof(node));
    if(n == NULL)//内存分配失败
        return ;
		
	n->x = nx;
    n->color = col;
	
    n->next = NULL;//尾插法，插入元素指向空
    if(q->rear == NULL)
    {
        q->front = n;
        q->rear = n;
    }
    else{
       q->rear->next = n;//让n成为当前的尾部节点下一节点
        q->rear= n;//尾部指针指向n
    }
}
 
 
//出队(删除队首元素)
void DeleteQueue(que *q)
{
    node * n = q->front;
    if(q->front == NULL)//判断队列是否为空
        return ;
    if(q->front == q->rear)//是否只有一个元素
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else{
        q->front = q->front->next;
        free(n);
    }
}

#define  MAX_INDEX   100
#define  MAX_STEP    10000
#define  RED    0
#define  BLUE   1
int  red_map[MAX_INDEX][MAX_INDEX] = {{0}}; /* 记录每个节点可以达到next节点的集合 */
int  red_count[MAX_INDEX] = {0}; /* 记录每个节点可以达到next节点的集合个数  */
int  blue_map[MAX_INDEX][MAX_INDEX] = {{0}};
int  blue_count[MAX_INDEX] = {0};
int  visit[MAX_INDEX][MAX_INDEX][2] = {{{0}}};

void  Init_global_data()
{
    int i, j;
    for (i = 0; i < MAX_INDEX; i++) {
        for(j = 0; j < MAX_INDEX; j++) {
            red_map[i][j] = 0;
            blue_map[i][j] = 0;
            visit[i][j][RED] = 0;
            visit[i][j][BLUE] = 0;
        }
        red_count[i] = 0;
        blue_count[i] = 0;
    }
    return;
}

int* shortestAlternatingPaths(int n, int** red_edges, int red_edgesSize, int* red_edgesColSize, int** blue_edges, int blue_edgesSize, int* blue_edgesColSize, int* returnSize){
    int i, j;
    int* res = NULL;
    int step = 0; /* 当前走的步数 */
    que * q;
    node * now = NULL;
    int now_index;
    int now_col;
    int local_quesize = 0;
    int que_size = 0;
    int cur = 0;
    int next = 0;

    res = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        res[i] = MAX_STEP;
    }

    (void)Init_global_data();

    for (i = 0; i < red_edgesSize; i++) {
        red_map[red_edges[i][0]][red_count[red_edges[i][0]]] = red_edges[i][1];
        red_count[red_edges[i][0]]++;
    }

    for (i = 0; i < blue_edgesSize; i++) {
        blue_map[blue_edges[i][0]][blue_count[blue_edges[i][0]]] = blue_edges[i][1];
        blue_count[blue_edges[i][0]]++;
    }

    q = InitQueue();
    InsertQueue(q, 0, RED); //存放起点的索引
    InsertQueue(q, 0, BLUE); // red和blue都可以作为起点
    local_quesize = 2;


    while (!EmptyQueue(q)) {
        que_size = 0; /* 清0 */
        while (local_quesize > 0) {
            now = q->front; //取出队首
            now_index = now->x;
            now_col = now->color;
            DeleteQueue(q); //出队首元素
            cur = now_index;

            /* 当前走的是blue，那下一步要遍历red */
            if (now_col == BLUE) {
                /* 遍历red_map[now_index][i]，访问过的跳过 */
                for (i = 0; i < red_count[cur]; i++) {
                    next = red_map[cur][i]; /* 下一个节点 */
                    if (visit[cur][next][RED] == 0) {
                        /* 如果当前线段没有访问过，则计算next节点历史上存的步数和当前步数取最小值 */
                        res[next] = (res[next] < (step + 1)) ? res[next] : (step + 1);
                        visit[cur][next][RED] = 1;
                        InsertQueue(q, next, RED);
                        que_size++; /* 记录当前一次while循环入队了多少个点 */
                    }
                }
            } else if (now_col == RED) {
                /* 当前走的是red，那下一步要遍历blue */
                for (i = 0; i < blue_count[cur]; i++) {
                    next = blue_map[cur][i]; /* 下一个节点 */
                    if (visit[cur][next][BLUE] == 0) {
                        res[next] = (res[next] < (step + 1)) ? res[next] : (step + 1);
                        visit[cur][next][BLUE] = 1;
                        InsertQueue(q, next, BLUE);
                        que_size++; /* 记录当前一次while循环入队了多少个点 */
                    }
                }
            }

            local_quesize--;
        }
        local_quesize = que_size; /* 退出内层while循环后将local_quesize赋值，记录当前队列中有多少个节点待走 */
        if(que_size > 0) {
            step++; /* 当前一次遍历完队列如果有点访问到，则步数加1 */
        }
    }

    res[0] = 0; /* 起始点赋值 */
    for (i = 1; i < n; i++) {
        if (res[i] == MAX_STEP) {
            res[i] = -1;
        }
    }

    free(q);
    *returnSize = n;
    return res;
}








```