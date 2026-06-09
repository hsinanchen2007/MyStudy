
![image.png](https://pic.leetcode-cn.com/e3c058989e5c172b54724135f4362065721f4e57fcc737a775574d1cd25e904c-image.png)



```c
#define PRIORITY_SIZE 100005
#define PRIORITY_MAX_DATA 0x7fffffff
#define PRIORITY_MIN_DATA -PRIORITY_MAX_DATA

/* return 0 – 成功 */
#define memset_s(dest, destMax, c, count) memset(dest, c, count)

typedef struct PriorityQueueNode_t {
    int val;
} PriorityQueueNode;

typedef struct PriorityQueue_t {
    int size;
    bool isLargestPriorityQueue;
    PriorityQueueNode arr[PRIORITY_SIZE];
} PriorityQueue;

static inline bool PriorityQueueInnerCmp(PriorityQueue* queue,
    PriorityQueueNode* node1, PriorityQueueNode* node2)
{
    if (queue->isLargestPriorityQueue) {
        return node1->val < node2->val;
    } else {
        return node1->val > node2->val;
    }
}

static inline void PriorityQueueInit(PriorityQueue* queue, bool isLargestPriorityQueue)
{
    if (!queue) {
        return ;
    }
    (void)memset_s(queue, sizeof(PriorityQueue), 0, sizeof(PriorityQueue));
    queue->isLargestPriorityQueue = isLargestPriorityQueue;
    if (isLargestPriorityQueue) {
        queue->arr[0].val = PRIORITY_MAX_DATA;
    } else {
        queue->arr[0].val = PRIORITY_MIN_DATA;
    }
}

static inline int PriorityQueueGetSize(PriorityQueue* queue)
{
    if (!queue) {
        return -1;
    }
    return queue->size;
}

static inline bool PriorityQueueIsEmpty(PriorityQueue* queue)
{
    if (!queue) {
        return true;
    }
    return queue->size == 0;
}

static inline bool PriorityQueueIsFull(PriorityQueue* queue)
{
    if (!queue) {
        return true;
    }
    return queue->size == PRIORITY_SIZE - 1;
}

static inline void PriorityQueuePush(PriorityQueue* queue, PriorityQueueNode* node)
{
    if (!queue || !node || PriorityQueueIsFull(queue)) {
        return ;
    }
    int i;
    /* 插入节点时, 与父节点比较 
       如果是最大优先队列, 则父节点比子节点小, 父节点下沉
       如果是最小优先队列, 则父节点比子节点大, 父节点下沉
    */
    for (i = ++queue->size;
        PriorityQueueInnerCmp(queue, &queue->arr[i / 2], node); i /= 2) {
        queue->arr[i] = queue->arr[i / 2];
    }
    queue->arr[i] = *node;
}

static inline PriorityQueueNode PriorityQueuePop(PriorityQueue* queue)
{
    if (!queue || PriorityQueueIsEmpty(queue)) {
        exit(1);
    }

    int i, child;
    PriorityQueueNode element, lastElement;

    element = queue->arr[1];
    lastElement = queue->arr[queue->size--];

    /* 调整堆序 */
    for (i = 1; i * 2 <= queue->size; i = child) {
        child = i * 2;
        if (child != queue->size 
            && PriorityQueueInnerCmp(queue, &queue->arr[child], &queue->arr[child + 1])) {
            ++child;
        }

        if (PriorityQueueInnerCmp(queue, &lastElement, &queue->arr[child])) {
            queue->arr[i] = queue->arr[child];
        } else {
            break;
        }
    }
    queue->arr[i] = lastElement;
    return element;
}

static inline PriorityQueueNode PriorityQueueTop(PriorityQueue* queue)
{
    if (!queue || PriorityQueueIsEmpty(queue)) {
        exit(1);
    }
    return queue->arr[1];
}

const int MOD = 1e9 + 7;
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

#define SIZE 100005
typedef struct {
    long long speed;
    long long efficiency;
} Node;

Node arr[SIZE];
PriorityQueue g_queue;

int Cmp(const void* a, const void* b)
{
    return ((Node*)b)->efficiency - ((Node*)a)->efficiency;
}

int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k) {
    if (n == 0 || speed == NULL || speedSize == 0 || efficiency == NULL || efficiencySize == 0) {
        return 0;
    }

    int i;
    for (i = 0; i < n; ++i) {
        arr[i].speed = speed[i];
        arr[i].efficiency = efficiency[i];
    }
    qsort(arr, n, sizeof(Node), Cmp);
    PriorityQueueInit(&g_queue, false);

    long long ret = 0;
    long long speedSum = 0;
    PriorityQueueNode node;
    for (i = 0; i < n; ++i) {
        if (PriorityQueueGetSize(&g_queue) >= k) {
            if (PriorityQueueTop(&g_queue).val >= arr[i].speed) {
                continue;
            }
            speedSum -= PriorityQueuePop(&g_queue).val;
        }
        node.val = arr[i].speed;
        speedSum += node.val;
        PriorityQueuePush(&g_queue, &node);
        ret = MAX(ret, speedSum * arr[i].efficiency);
    }

    return ret % MOD;
}

```