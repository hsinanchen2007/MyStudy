该题首先相当的方法是通过BFS进行广搜，但是由于BFS的处理太分散，可能导致时间特别长，既然这样就相当了是否可以从目标反向搜，然后从起始地方正向搜索。

两个方向分别记录下当前已经访问过的节点，每次遍历完成之后，确认当前两个方向是否存在交接面，如果出现交接面，此时出现的碰撞点肯定是最短的搜索路劲。

正向搜索过程中记录下上一个节点，然后发现搜索过程中也记录上一个节点。然后在碰撞后对于正向搜索采用栈的方式把经过的节点全部获取出来，对反向搜索直接遍历过程依次经历过的节点，最终获取到最终的路径，该方法的搜索距离是最短的，相比其他方法更加的直观。


类似于从两个原点画圆，相交的位置就可以作为碰撞点。BFS采用了队列
```
typedef int Item;

typedef struct {
    Item *queue;
    int head;
    int rear;
    int max;
    int cnt;
} Queue_t;

Queue_t *QueueInit(int max)
{
    Queue_t *queue = (Queue_t *)malloc(sizeof(Queue_t));
    if (queue == NULL) {
        return NULL;
    }

    memset(queue, 0, sizeof(Queue_t));
    queue->max = max;
    queue->cnt = 0;
    queue->queue = (Item *)malloc(sizeof(Item) * max);
    if (queue->queue == NULL) {
        free(queue);
        return NULL;
    }

    (void)memset(queue->queue, 0, sizeof(Item) * max);
    return queue;
}

void QueuePush(Queue_t *queue, Item item)
{
    if (queue->cnt == queue->max) {
        return;
    }

    if (queue->head > 0 && queue->rear >= queue->max) {
        for (int i = queue->head; i < queue->rear; ++i) {
            queue->queue[i - queue->head] = queue->queue[i];
        }

        queue->rear -= queue->head;
        queue->head = 0;
    }

    queue->queue[queue->rear++] = item;
    queue->cnt++;
}

void QueuePop(Queue_t *queue)
{
    if (queue->head == queue->rear) {
        return;
    }

    queue->head++;
    queue->cnt--;
}

int IsQueueEmpty(Queue_t *queue)
{
    if (queue->head == queue->rear) {
        return 1;
    }

    return 0;
}

Item QueueTop(Queue_t *queue)
{
    return queue->queue[queue->head];
}

void QueueDestory(Queue_t *queue)
{
    free(queue->queue);
    free(queue);
}

int QueueSize(Queue_t *queue)
{
    return queue->cnt;
}

int CheckParam(char *beginWord, char *endWord, char **wordList, int wordListSize, int *returnSize) 
{
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize <=0 || returnSize == NULL) {
        *returnSize = 0;
        return -1;
    }

    if (strlen(beginWord) != strlen(endWord)) {
        *returnSize = 0;
        return -1;
    }

    for (int i = 0; i < wordListSize; ++i) {
        if (strcmp(endWord, wordList[i]) == 0) {
            return i;
        }
    }

    *returnSize = 0;
    return -1;
}

int NeiberCmp(const char *a, const char *b)
{
    if (strlen(a) != strlen(b)) {
        return 0;
    }

    char *ptr1 = (char *)a;
    char *ptr2 = (char *)b;
    int cnt = 0;

    while (ptr1 != a + strlen(a)) {
        if (*ptr1 != *ptr2) {
            cnt++;
        }
        ptr1++;
        ptr2++;
    }

    if (cnt == 1) {
        return 1;
    }

    return 0;
}

int *findAdjChars(char **wordList, int wordListSize, char *marks, char *word, int *adjSize)
{
    int *adjust = (int *)malloc(sizeof(int) * 1024);
    memset(adjust, 0, sizeof(int) * 1024);
    size_t len = strlen(word);
    int cnt = 0;

    for (int i = 0; i < wordListSize; ++i) {
        if (strlen(wordList[i]) != len) {
            continue;
        }

        if (marks[i] == 0 && NeiberCmp(word, wordList[i])) {
            adjust[cnt++] = i;
        }
    }

    *adjSize = cnt;
    if (cnt > 0) {
        return adjust;
    }

    free(adjust);
    return NULL;
}

int IsConnected(char *mark1, char *mark2, int len)
{
    for (int i = 0; i < len; ++i) {
        if (mark1[i] > 0 && mark2[i] == mark1[i]) {
            return i;
        }
    }

    return -1;
}

void ProcessAdj(int *startList, int len, char *mark, int *parent, int start, Queue_t *queue)
{
    for (int i = 0; i < len; ++i) {
        parent[startList[i]] = start;
        mark[startList[i]] = 1;
        QueuePush(queue, startList[i]);
    }
}

char **ParentProcess(int *startParent, int *endParent, int start, int end, char *beginWord, char **wordList, int wordListSize, int *returnSize)
{
    char **ret = (char **)malloc(sizeof(char *) * 1024);
    int stack[1024] = {0};
    int top = 0;

    int i = start;
    while (i != wordListSize) {
        stack[top++] = i;
        i = startParent[i];
    }

    stack[top++] = i;

    ret[0] = beginWord;
    for (int i = top - 1; i >= 0; --i) {
        if (stack[i] == wordListSize) {
            ret[top - 1 - i] = beginWord;
            continue;
        }
        ret[top - 1 - i] = wordList[stack[i]];
    }

    i = endParent[start];
    while (i != end) {
        ret[top++] = wordList[i];
        i = endParent[i];
    }

    ret[top++] = wordList[i];

    *returnSize = top;
    return ret;
}

char **findLadders(char *beginWord, char *endWord, char **wordList, int wordListSize, int *returnSize) 
{
    int ret = CheckParam(beginWord, endWord, wordList, wordListSize, returnSize);
    if (ret == -1) {
        return NULL;
    }

    char *result = (char *)malloc(strlen(beginWord) + 1);
    strcpy(result, beginWord);

    if (NeiberCmp(beginWord, endWord)) {
        char **ret = (char **)malloc(2 * sizeof(char *));
        ret[0] = result;
        ret[1] = endWord;

        *returnSize = 2;
        return ret;
    }

    char *startMark = (char *)malloc(sizeof(char) * wordListSize);
    char *endMark = (char *)malloc(sizeof(char) * wordListSize);
    memset(startMark, 0, sizeof(char) * wordListSize);
    memset(endMark, 0, sizeof(char) * wordListSize);
    int *startParent = (int *)malloc(sizeof(int) * wordListSize);
    int *endParent = (int *)malloc(sizeof(int) * wordListSize);
    for (int i = 0; i < wordListSize; ++i) {
        startParent[i] = i;
        endParent[i] = i;
    }

    Queue_t *inputPQ = QueueInit(1024);
    Queue_t *endPQ = QueueInit(1024);
    QueuePush(inputPQ, wordListSize);
    QueuePush(endPQ, ret);

    int connect = -1;
    while (!IsQueueEmpty(inputPQ) && ! IsQueueEmpty(endPQ)) {
        int endIndx = QueueTop(endPQ);
        QueuePop(endPQ);
        endMark[endIndx] = 1;
        int endAdjust;
        int *endList = findAdjChars(wordList, wordListSize, endMark, wordList[endIndx], &endAdjust);
        ProcessAdj(endList, endAdjust, endMark, endParent, endIndx, endPQ);
        int startIndx = QueueTop(inputPQ);
        QueuePop(inputPQ);
        char *ptr;
        if (startIndx == wordListSize) {
            ptr = result;
        } else {
            ptr = wordList[startIndx];
        }
        int startAdjust;
        int *startList = findAdjChars(wordList, wordListSize, startMark, ptr, &startAdjust);
        ProcessAdj(startList, startAdjust, startMark, startParent, startIndx, inputPQ);

        connect = IsConnected(startMark, endMark, wordListSize);
        if (connect >= 0) {
            break;
        }
    }

    if (connect >= 0) {
        return ParentProcess(startParent, endParent, connect, ret, beginWord, wordList, wordListSize, returnSize);
    }

ERROR:
    free(result);
    free(startMark);
    free(endMark);
    free(startParent);
    free(endParent);

    *returnSize = 0;
    return NULL;
}
```

