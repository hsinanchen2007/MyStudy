该题不是简单的图处理，因为允许多次访问，但是求最短路径问题，首先想到的是BFS，既然是从任意点出发，因此可以在待处理的队列中增加所有节点起始的访问节点。然后根据队列的顺序通过不断的搜索最终找到最短的距离。但是怎么确认从当前节点到达的某个节点之后所有的节点都访问了呢？在每一轮搜索的过程中增加以下对应的访问节点列表即可。由于设备数量是一定的，那么可以通过对应的bit标识对应的设备，如果已经访问则设置1<<bit。

```
typedef struct {
    int vetex;
    int nums; //标识覆盖的位置(bit标识)
    int step;
} Vetex_t;

typedef Vetex_t* Item;

typedef struct {
    int max;
    int cnt;
    int head;
    int tail;
    Item *queue;
} Queue_t;

Queue_t *QueueInit(int max)
{
    Queue_t *queue = (Queue_t *)malloc(sizeof(Queue_t));
    queue->queue = (Item *)malloc(sizeof(Item) * max);
    memset(queue->queue, 0, sizeof(sizeof(Item) * max));
    queue->max = max;
    queue->tail = 0;
    queue->head = 0;
    queue->cnt  = 0;

    return queue;
}

void QueuePush(Queue_t *queue, Item item)
{
    if (queue->cnt == queue->max) {
        return;
    }

    if (queue->tail == queue->max) {
        for (int i = queue->head; i < queue->tail; ++i) {
            queue->queue[i - queue->head] = queue->queue[i];
        }
        
        queue->tail -= queue->head;
        queue->head = 0;
    }

    queue->queue[queue->tail++] = item;
    queue->cnt++;
}

Item QueuePop(Queue_t *queue)
{
    queue->cnt--;
    return queue->queue[queue->head++];
}

int IsQueueEmpty(Queue_t *queue)
{
    return queue->cnt == 0;
}

void QueueDestory(Queue_t *queue)
{
    while (!IsQueueEmpty(queue)) {
        free(QueuePop(queue));
    }

    free(queue->queue);
    free(queue);
}

Item CreateItem(int vex, int nums, int step)
{
    Item node = (Item)malloc(sizeof(Vetex_t));
    memset(node, 0, sizeof(Vetex_t));
    node->vetex = vex;
    node->nums = nums;
    node->step = step;

    return node;
}

int CheckParam(int** graph, int graphSize, int* graphColSize)
{
    if (graph == NULL || graphSize <= 0 || graphColSize == NULL) {
        return -1;
    }

    for (int i = 0; i < graphSize; ++i) {
        if (graphColSize[i] <= 0) {
            return -1;
        }
    }

    return 0;
}

int isAllCover(Item item, int graphSize)
{
    for (int v = 0; v < graphSize; ++v) {
        if ((item->nums & (1 << v)) == 0) {
            return 0;
        }
    }

    return 1;
}

int shortestPathLength(int** graph, int graphSize, int* graphColSize)
{
    if (CheckParam(graph, graphSize, graphColSize)) {
        return 0;
    }

    Queue_t *queue = QueueInit(40280);
    int maxStep = INT_MAX;

    for (int v = 0; v < graphSize; ++v) {
        QueuePush(queue, CreateItem(v, 1 << v, 0));
    }

    while (!IsQueueEmpty(queue)) {
        Item item = QueuePop(queue);
       
        if (item->step > maxStep) { //这种是防止无意义的搜索， 之前已经有满足要求的节点
            continue;
        } else if (isAllCover(item, graphSize)) { //满足条件的所有节点，记录下来
            if (maxStep > item->step) {
                maxStep = item->step;
            }
            continue;
        }

        for (int edge = 0; edge < graphColSize[item->vetex]; ++edge) { //遍历所有的连接节点
            int to = graph[item->vetex][edge];
            QueuePush(queue, CreateItem(to, (item->nums) | (1 << to), item->step + 1)); //修改待访问的节点列表和已经完成的路劲数。
        }

        free(item);
    }

    QueueDestory(queue);

    return maxStep;
}
```

以上是基本的代码框架，在小规模的情况下可以找到，但是当节点较多的情况下会出现超时的情况，同时队列的要求比较高，因为是无裁剪的入队列，一次入4个，出队列才1个，造成大量的堆积。同时实际上有很多的重复。比如存在0-1只有一条边的情况下，访问1之后，还需要访问0，到达0之后，如果不裁剪，还会走到1，因此造成无效操作很多，耗时很大。最好的方法是记录下已经访问的节点情况。实际上在某个节点判断是否访问了所有的节点肯定需要一个记录，由于BFS对应多条路径，同时是多点同时出发，只是单一的mark肯定无法标记，那么可以考虑的方法是增加一个状态： mark[v][访问节点的情况]，记录访问到节点v，访问节点的情况是当前已经访问过得设备列表。因此mark[v][old | 1<<bit] = 1，就是bit对应的节点备访问到，如果已经被访问的情况下就不要再访问。这样就能实现裁剪，提高效率。
```
typedef struct {
    int vetex;
    int nums; //标识覆盖的位置(bit标识)
    int step;
} Vetex_t;

typedef Vetex_t* Item;

typedef struct {
    int max;
    int cnt;
    int head;
    int tail;
    Item *queue;
} Queue_t;

Queue_t *QueueInit(int max)
{
    Queue_t *queue = (Queue_t *)malloc(sizeof(Queue_t));
    queue->queue = (Item *)malloc(sizeof(Item) * max);
    memset(queue->queue, 0, sizeof(sizeof(Item) * max));
    queue->max = max;
    queue->tail = 0;
    queue->head = 0;
    queue->cnt  = 0;

    return queue;
}

void QueuePush(Queue_t *queue, Item item)
{
    if (queue->cnt == queue->max) {
        return;
    }

    if (queue->tail == queue->max) {
        for (int i = queue->head; i < queue->tail; ++i) {
            queue->queue[i - queue->head] = queue->queue[i];
        }
        
        queue->tail -= queue->head;
        queue->head = 0;
    }

    queue->queue[queue->tail++] = item;
    queue->cnt++;
}

Item QueuePop(Queue_t *queue)
{
    queue->cnt--;
    return queue->queue[queue->head++];
}

int IsQueueEmpty(Queue_t *queue)
{
    return queue->cnt == 0;
}

void QueueDestory(Queue_t *queue)
{
    while (!IsQueueEmpty(queue)) {
        free(QueuePop(queue));
    }

    free(queue->queue);
    free(queue);
}

Item CreateItem(int vex, int nums, int step)
{
    Item node = (Item)malloc(sizeof(Vetex_t));
    memset(node, 0, sizeof(Vetex_t));
    node->vetex = vex;
    node->nums = nums;
    node->step = step;

    return node;
}

int CheckParam(int** graph, int graphSize, int* graphColSize)
{
    if (graph == NULL || graphSize <= 0 || graphColSize == NULL) {
        return -1;
    }

    for (int i = 0; i < graphSize; ++i) {
        if (graphColSize[i] <= 0) {
            return -1;
        }
    }

    return 0;
}

int isAllCover(Item item, int graphSize)
{
    return item->nums == ((1 << graphSize) -1);
}

int shortestPathLength(int** graph, int graphSize, int* graphColSize)
{
    if (CheckParam(graph, graphSize, graphColSize)) {
        return 0;
    }

    Queue_t *queue = QueueInit(4096);
    int maxStep = INT_MAX;

    int  **mark = (int **)malloc(sizeof(int *) *graphSize); //增加对mark[v][访问列表的]保存，避免反复递归访问
    for (int i = 0; i < graphSize; ++i) {
        mark[i] = (int *)malloc(sizeof(int) * pow(2, graphSize));
        memset(mark[i], 0, sizeof(int) * pow(2, graphSize));
    }

    for (int v = 0; v < graphSize; ++v) {
        QueuePush(queue, CreateItem(v, 1 << v, 0));
        mark[v][1 << v] = 1;
    }

    while (!IsQueueEmpty(queue)) {
        Item item = QueuePop(queue);
       
        if (item->step > maxStep) { //这种是防止无意义的搜索， 之前已经有满足要求的节点
            continue;
        } else if (isAllCover(item, graphSize)) { //最先访问到的肯定是最短的路劲
            maxStep = item->step;
            free(item);
            break;
        }

        for (int edge = 0; edge < graphColSize[item->vetex]; ++edge) { //遍历所有的连接节点
            int to = graph[item->vetex][edge];
            
            if (mark[to][(item->nums) | (1 << to)] == 1) { //到to的访问之前已经访问过，无需再访问
                continue;
            }
            
            QueuePush(queue, CreateItem(to, (item->nums) | (1 << to), item->step + 1));
            mark[to][(item->nums) | (1 << to)] = 1;
        }

        free(item);
    }

    QueueDestory(queue);

    return maxStep;
}
```


