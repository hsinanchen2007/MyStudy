### 解题思路
1、判断end是否在worklist中，不在直接返回0
2、BFS获取最短路径
![image.png](https://pic.leetcode-cn.com/0b5a713e975634cce949984ca71fa85a9d6101aa2dee72d4d785270352300c55-image.png)

### 代码

```c
#define MAX_NUMS 10000
typedef struct Queue_ {
    int arr[MAX_NUMS];
    int front;
    int rear;
} Queue;

void QueueInit(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

bool Full(Queue *queue)
{
    if ((queue->rear + 1) % MAX_NUMS == queue->front) {
        return true;
    }
    return false;
}

bool Empty(Queue *queue)
{
    return queue->front == queue->rear;
}

void QueuePush(Queue *queue, int node)
{
    if (!Full(queue)) {
        queue->arr[queue->rear] = node;
        queue->rear = (queue->rear + 1) % MAX_NUMS;
    }
}

void QueuePop(Queue *queue)
{
    if (!Empty(queue)) {
        queue->front = (queue->front + 1) % MAX_NUMS;
    }
}

void QueueClear(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int QueueTop(Queue *queue)
{
    return queue->arr[queue->front];
}

static bool IsOneCharDiff(const char *wordOne, const char *wordTow, int wordLen)
{
    int diff = 0;
    for (int i = 0; i < wordLen; i++) {
        if (wordOne[i] != wordTow[i]) {
            diff++;
        }
    }

    if (diff != 1) {
        return false;
    }
    return true;
}

static bool IsEndWordInTree(char *endWord, char **wordList, int wordListSize)
{
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(endWord, wordList[i]) == 0) {
            return true;
        }
    }

    return false;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
    if ((beginWord == NULL) || (endWord == NULL) || (!IsEndWordInTree(endWord, wordList, wordListSize))) {
        return 0;
    }

    int flag[wordListSize];
    memset(flag, 0, sizeof(flag));
    printf("flag len = %d\n", sizeof(flag));
    Queue queue = {0};
    QueueInit(&queue);

    int level[wordListSize];
    for (int i = 0; i < wordListSize; i++) {
        level[i] = 1;
    }
    QueuePush(&queue, -1);
    while (!Empty(&queue))
    {
        char *tmp = NULL;
        int topIndex = QueueTop(&queue);
        tmp = topIndex  == -1 ? beginWord : wordList[topIndex];
        if (strcmp(tmp, endWord) == 0) {
            return topIndex  == -1 ? 1 : (level[topIndex] + 1);
        }
        for (int i = 0; i < wordListSize; i++) {
            if (flag[i] != 0) {
                continue;
            }
            if (IsOneCharDiff(tmp, wordList[i], strlen(tmp))) {                
                QueuePush(&queue, i);
                level[i] = (topIndex  == -1) ? 1 : (level[topIndex] + 1);
                flag[i] = 1;
            }
        }
        QueuePop(&queue);
    }
    return 0;
}
```