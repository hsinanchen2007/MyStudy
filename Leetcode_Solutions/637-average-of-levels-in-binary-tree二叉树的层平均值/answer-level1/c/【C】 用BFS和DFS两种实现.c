# 1. BFS - 层序遍历(LevelOrderTraversal)
- **思路**：C语言可以通过利用编写队列(struct _queue)结构来实现层序遍历。直观地完成题目交给的任务：逐层统计元素值、元素数量，最后计算并构建答案数组。相对于普通的层序遍历，需要额外做的是记录当前节点的层序号，用于后续统计时区分层数。
- **代码构成**：
① 自定义结构：队列的元素，包含一个节点指针和层序号 ~`QElem` 、 队列结构，包含队列和队列大小、上界、头尾指针(int) ~ `*Queue`。
② 函数接口块 ~ `averageOfLevels()` 。
③ 层序遍历，构建一个层序存放每个节点指针和层序号的队列 ~`levelorderTraversal()` 。
③ 队列的基本操作 入队/出队 ~ `Enqueue/Dequeue()` 、 得到队首元素的层序号 ~ ` GetFrontNum()` 、判断队列是否为空 ~ `isEmpty()`。
- **注意**：
① 在遍历中，需要把当前队首节点出队，再把该节点的左右子节点入队到队尾，从而实现层序。故使用了一个`helper`作为出入队辅助队列，而队列`q`是构建的一个层序队列。
② 代码实现中，选择了先构建一个层序存放每个节点指针和层序号的队列，然后再通过这个队列来统计每层的总和与节点个数，进而计算该层平均值。其实可以更直接地在层序遍历过程中就把每层节点和与节点个数统计出来，但是为了代码思路更加模块化和直观，这里没有做这样的优化。有好的结构设计欢迎各位优化指正！
③ 考虑边界用例可能使得运算溢出，所以`sum`使用了`long`类型。
- **代码**

```
#define MAXSIZE 10000

typedef struct _qelement{
    struct TreeNode *root;
    int levelNum;
} QElem;

typedef struct _queue{
    QElem queue[ MAXSIZE ];
    int front, rear, size, maxsize;
} *Queue;

int Enqueue( struct TreeNode *root, int levelNum, Queue q ); 
// return the levelNum(int) of the node successfully enqueued, return 0 for error/null
struct TreeNode* Dequeue( Queue q );
int GetFrontNum( Queue q );
int isEmpty( Queue q );

double* averageOfLevels(struct TreeNode* root, int* returnSize){

    void levelorderTraversal( struct TreeNode *root, Queue q, int *levelSize );

    // initialize a queue for traversaling
    Queue q = ( Queue ) malloc( sizeof( struct _queue ) );
    q->front = q->rear = 0;
    q->maxsize = MAXSIZE;
    q->size = 0;

    // build the queue
    *returnSize = 1;
    levelorderTraversal( root, q, returnSize );
        
    // build the ret array by the queue
    double *ret = ( int* ) malloc( sizeof( double ) * *returnSize );
    int i;
    for( i = 0; i < *returnSize; i++ ){
        long sum = 0;
        int n = 0;
        while( GetFrontNum( q ) == i + 1 ){
            sum += Dequeue( q )->val;
            n++;
        }
        ret[ i ] = sum / (double)n;
    }

    // return 
    free( q );
    return ret;
}

void levelorderTraversal( struct TreeNode *root, Queue q, int *levelSize )
{
    // create a helper queue
    Queue helper = ( Queue ) malloc( sizeof( struct _queue ) );
    helper->front = helper->rear = 0;
    helper->maxsize = MAXSIZE;
    helper->size = 0;

    // build the queue for traversaling
    Enqueue( root, 1, helper );
    while( !isEmpty( helper ) ){
        int levelNum = GetFrontNum( helper );
        struct TreeNode *tmp = Dequeue( helper );
        Enqueue( tmp, levelNum, q );
        int flg1 = 0, flg2 = 0;
        flg1 = Enqueue( tmp->left, levelNum + 1, helper );
        flg2 = Enqueue( tmp->right, levelNum + 1, helper );
        if( flg1 || flg2 )
            *levelSize = levelNum + 1;
    }

    // return 
    free( helper );
}

int Enqueue( struct TreeNode *root, int levelNum, Queue q )
// return the levelNum(int) of the node successfully enqueued, return 0 for error/null
{
    if( !root )
        return 0;
    
    q->queue[ q->rear ].root = root;
    q->queue[ q->rear ].levelNum = levelNum;
    q->size++;
    q->rear = ( ++q->rear ) % q->maxsize;
    return levelNum;
}

struct TreeNode* Dequeue( Queue q )
{
    struct TreeNode *FrontCell = q->queue[ q->front ].root;
    q->front = ( ++q->front ) % q->maxsize;
    q->size--;
    return FrontCell;
} 

int GetFrontNum( Queue q )
{
    return q->queue[ q->front ].levelNum;
}

int isEmpty( Queue q )
{
    return ( q->size == 0 );
}
```

# 2. DFS - 递归
- **思路**：
分层无序遍历（记录）每层的元素时，使用层序遍历BFS相对直观、且使用队列不需要占用过多的程序段内存（入栈），但是代码量相对较大。
因为只是单纯的记录每层和以及节点个数，这时可以考虑用DFS遍历，用入栈深度来代表当前层高度，每次递归把当前节点元素值直接计入层值和，可以减少代码量，缺点是递归使运行效率变低，执行起来比BFS慢。
- **代码构成**：
① 函数接口块 ~ `averageOfLevels()` 。
② DFS ~ `dfs()` 。
- **注意**：
① dfs的接口（传参）：当前节点 `root`、 当前递归深度 `curLevel`、 并更新整棵树的深度 `*levelSize`、 记录每层总和以及每层节点数的数组 `long sumTable[], int cntTable[]`。
- **代码**

```
#define MAXSIZE 10000

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    
    void dfs( struct TreeNode *root, int curLevel, int *levelSize, long sumTable[], int cntTable[] );

    //  build tables
    long sumTable[ MAXSIZE ] = { 0 };
    int cntTable[ MAXSIZE ]  = { 0 };
    *returnSize = 1;
    dfs( root, 1, returnSize, sumTable, cntTable );

    // calculate ret avg table
    double *ret = ( double* ) malloc( sizeof( double ) * *returnSize );
    int i;
    for ( i = 0; i < *returnSize; i++ )
        ret[ i ] = sumTable[ i ] / ( double )cntTable[ i ];

    // return
    return ret; 
}

void dfs( struct TreeNode *root, int curLevel, int *levelSize, long sumTable[], int cntTable[] )
{
    if( !root )
        return ;
    
    sumTable[ curLevel - 1 ] += root->val;
    cntTable[ curLevel - 1 ]++;
    if( *levelSize < curLevel )
        *levelSize = curLevel;

    dfs( root->left, curLevel + 1, levelSize, sumTable, cntTable );
    dfs( root->right, curLevel + 1, levelSize, sumTable, cntTable );
}
```



最后比较一下两种算法效率：
**BFS:**
![bfs.png](https://pic.leetcode-cn.com/86020cf1209341128aab38241e2c3039de461b354a36353f570db67f6f9196fb-bfs.png)


**DFS:**
![dfscal.png](https://pic.leetcode-cn.com/88cd20d9a566e414d192409e2b7b8066c4a75e070e8e7895525a3228e99c3eaa-dfscal.png)


还请各位大佬优化指正！