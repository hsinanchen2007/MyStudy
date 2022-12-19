```
typedef struct {
    int floor;
    int index;
    double probability;
}QueueNode;

int g_front;
int g_tail;
QueueNode *g_queue;

int InitQueue(int queueSize)
{
    g_front = 0;
    g_tail = 0;
    g_queue = (QueueNode *)malloc(sizeof(QueueNode) * queueSize);
    if (g_queue == NULL) {
        return -1;
    }
    (void)memset(g_queue, 0, sizeof(QueueNode) * queueSize);

    return 0;
}

void DestroyQueue()
{
    if (g_queue != NULL) {
        free(g_queue);
        g_queue = NULL;
    }
}

int GetQueueSize()
{
    return g_tail - g_front;
}

void EnQueue(int floor, int input, double probability)
{
    g_queue[g_tail].floor = floor;
    g_queue[g_tail].index = input;
    g_queue[g_tail].probability = probability;
    g_tail++;
}

void DeQueue(QueueNode *queueNode)
{
    queueNode->floor  = g_queue[g_front].floor;
    queueNode->index  = g_queue[g_front].index;
    queueNode->probability  = g_queue[g_front].probability;
    g_front++;
}


void InitTree(int n, int** edges, int edgesSize, int *childNum, int *tree)
{
    int first;
    int second;
    int temp;

    for (int i = 0; i < edgesSize; i++) {
        first = edges[i][0];
        second = edges[i][1];

        /* 这里交换，是解决无向树的问题，保障左边小，不会存在双向的问题 */
        if (first > second) {
            temp = first;
            first = second;
            second = temp;
        }

        *(tree + n * first  + childNum[first]) = second;
        childNum[first] += 1;
    }
}

double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target){
    if (edgesSize == 0) {
        return 1;
    }

    double probability;
    double temp;
    int ret;
    QueueNode queueNode;
    ret = InitQueue(n);
    if (ret != 0) {
        return 0;
    }

    int childNum[n + 1];
    int tree[n + 1][n];
    (void)memset(childNum, 0, sizeof(childNum));
    (void)memset(tree, 0, sizeof(int) * (n + 1)  * n);
    (void)memset(&queueNode, 0, sizeof(queueNode));

    InitTree(n , edges, edgesSize, childNum, (int *)tree);

    EnQueue(1, 1, 1);

    temp = 1;

    while (GetQueueSize() != 0) {
        DeQueue(&queueNode);
        /* 如果跳的步数跳完了还没有到target，直接返回 */
        if (queueNode.floor - 1 > t) {
            DestroyQueue();
            return 0;
        }

        if (queueNode.index == target) {
            /* 如果该节点下面还有节点，t还有步数 */
            if (childNum[target] != 0 && queueNode.floor - 1 < t) {
                DestroyQueue();
                return 0;
            }

            DestroyQueue();
            return queueNode.probability;
        }

        if (childNum[queueNode.index] == 0) {
            continue;
        }

        temp = (double)((double)1 / (double)childNum[queueNode.index]) * queueNode.probability;

        for (int i = 0; i < childNum[queueNode.index]; i++) {
            EnQueue(queueNode.floor + 1, tree[queueNode.index][i], temp);
        }
    }
    
    DestroyQueue();
    return 0;
}
```
