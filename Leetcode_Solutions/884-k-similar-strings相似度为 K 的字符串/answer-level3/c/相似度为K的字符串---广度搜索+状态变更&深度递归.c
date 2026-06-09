找到相似度最小的值，也就是A转换到B的最小操作步骤。有点儿类似于状态变更，每个状态就类似一个图节点，记录一个从当前状态切换到另一个状态的所有可能性，然后再广搜这些可能的状态，直到找到搜索的可能性。实际上每个状态都是一个节点。为了避免相同节点反复的搜索。可以通过HASH保存各个节点的执行情况。

字符串的匹配处理过程：优先保证前面的字符匹配，但是调换的位置可能是多个，不一定是最先找到的，因此找到所有可能的转换，存储队列中，直到所有的匹配成功。

```
#define STRBUFLEN   21
typedef struct {
    char buffer[STRBUFLEN];
    int step;
    UT_hash_handle hh;
} BufHashNode_t;

typedef struct {
    char buffer[STRBUFLEN];
    int step;
} BufNode_t;

typedef BufNode_t* Item;

typedef struct {
    int max;
    int cnt;
    int head;
    int tail;
    Item *queue;
} Queue_t;

Item CreateItem(char *buf, int step)
{
    BufNode_t *buffer = (BufNode_t *)malloc(sizeof(BufNode_t));
    memset(buffer, 0, sizeof(BufNode_t));

    strcpy(buffer->buffer, buf);
    buffer->step = step;

    return buffer;
}

BufHashNode_t *CreateHashNode(char *buf, int step)
{
    BufHashNode_t *node = (BufHashNode_t *)malloc(sizeof(BufHashNode_t));
    memset(node, 0, sizeof(BufHashNode_t));

    strcpy(node->buffer, buf);
    node->step = step;

    return node;
}

void DeleteAllHashNode(BufHashNode_t **head)
{
    BufHashNode_t *cur;
    BufHashNode_t *next;

    HASH_ITER(hh, (*head), cur, next) {
        HASH_DEL((*head), cur);
        free(cur);
    }
}

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

int findDiffIndex(char *a, char *b)
{
    char *pa = a;
    char *pb = b;
    size_t len = strlen(a);

    while ((pa < a + len) && (*pa == *pb)) {
        pa++;
        pb++;
    }

    return pa - a;
}

int findNextIndex(char *a, char *b, int index, int next)
{
    char *pa = a + index;
    char *pb = b + next;
    size_t len = strlen(a);

    while (pb < b + len && *pa != *pb) {
        pb++;
    }

    if (pb < b + len) {
        return pb - b;
    }

    return -1;
}

int CheckParam(char *a, char *b)
{
    if (a == NULL || b == NULL) {
        return -1;
    }

    int aLen = strlen(a);
    int bLen = strlen(b);
    if (aLen != bLen) {
        return -1;
    }

    return 0;
}

int kSimilarity(char * A, char * B)
{
    if (CheckParam(A, B)) {
        return 0;
    }

    if (strcmp(A, B) == 0) {
        return 0;
    }

    Queue_t *queue = QueueInit(20480); //队列的深度需要评估，需要比较大
    BufHashNode_t *bufHashs = NULL;

    BufHashNode_t *hashnode = CreateHashNode(A, 0);
    HASH_ADD_STR(bufHashs, buffer, hashnode);
    BufNode_t *node = CreateItem(A, 0);
    QueuePush(queue, node);
    int min = INT_MAX;
    size_t len = strlen(A);

    while (!IsQueueEmpty(queue)) {
        Item item = QueuePop(queue);

        if (strcmp(item->buffer, B) == 0) {
            min = item->step;
            free(item);
            break;
        }

        // 此处野蛮的方法是随意转换两个字符，然后加入到队列中，性能可能不达标
        // 假设前面部分已经一致，先按照规则满足前面部分的
        // 从不同位置之后，找到可能的调换次数
        int index = findDiffIndex(item->buffer, B); //找到当前第一个不同的索引
        int next = index + 1;
        
        while (next < len) {
            next = findNextIndex(B, item->buffer, index, next);
            if (next < 0 || next >= len) {
                break;
            }
            BufNode_t *n = CreateItem(item->buffer, item->step + 1);
            char tmp = item->buffer[index];
            n->buffer[index] = n->buffer[next];
            n->buffer[next] = tmp;
            BufHashNode_t *t = NULL;
            HASH_FIND_STR(bufHashs, n->buffer, t);
            if (t == NULL) {
                QueuePush(queue, n);
                t = CreateHashNode(n->buffer, item->step + 1);
                HASH_ADD_STR(bufHashs, buffer, t);
            }

            next = next + 1;
        }

        free(item);
    }

    QueueDestory(queue);
    DeleteAllHashNode(&bufHashs);

    return min;
}
```

也可以通过深度搜索的方式遍历所有的结果，然后得到最小值。代码比较简单，相比广度搜索需要队列，代码很少。
```
int CheckParam(char *a, char *b)
{
    if (a == NULL || b == NULL) {
        return -1;
    }

    int aLen = strlen(a);
    int bLen = strlen(b);
    if (aLen != bLen) {
        return -1;
    }

    return 0;
}

void ExChange(char *a, int i, int j)
{
    char tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int g_maxStep = INT_MAX;
void DFS(char *a, char *b, int start, int step)
{
    if (step >= g_maxStep) {
        return;
    }

    if (strcmp(a, b) == 0) {
        if (g_maxStep > step) {
            g_maxStep = step;
        }
        return;
    }

    if (a[start] == b[start]) {
        DFS(a, b, start + 1, step); //进行下一个字母的搜索
    } else {
        for (int i = start + 1; i < strlen(a); ++i) {
            if (a[i] == b[start]) { //调换一下继续搜索
                ExChange(a, start, i);
                DFS(a, b, start + 1, step + 1);
                ExChange(a, start, i);
            }
        }
    }
}

int kSimilarity(char * A, char * B)
{
    if (CheckParam(A, B)) {
        return 0;
    }

    if (strcmp(A, B) == 0) {
        return 0;
    }

    g_maxStep = INT_MAX;
    
    DFS(A, B, 0, 0);

    if (g_maxStep == INT_MAX) {
        return 0;
    }

    return g_maxStep;
}

```


