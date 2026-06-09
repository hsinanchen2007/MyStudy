C语言 BFS 实现，常规思路
1、本地用了一个链表来实现C语言的队列，遇到需要队列的题型，都直接上模板
2、字典中查找差1的单词时，一次性找出所有的，放到二维数组中，每个都入队列
3、具体查找字典时，对相差大于1个字符的，跳到下一个单词比较，节省时间
4、代码如下，前面这一段都是队列的模板，关键实现在后面2个函数

```

typedef struct LinkNode {
    char *linkValue;
    struct LinkNode *next;
} LinkSt;

typedef struct QueueSt {
    LinkSt *head;
    LinkSt *tail;
} LinkQueue;

LinkQueue *g_queue = NULL;

void InitQueue(LinkSt *newNode)
{
    if (g_queue == NULL) {
        g_queue = malloc(sizeof(LinkQueue));
        if (g_queue == NULL) {
            printf("Malloc is NULL\n");
            return;
        }

        g_queue->head = newNode;
        g_queue->tail = newNode;
    }
}

void DeinitQueue()
{
    if (g_queue == NULL) {
        return;
    }

    while (g_queue->head != NULL) {
        LinkSt *curr = g_queue->head;
        g_queue->head = g_queue->head->next;
        free(curr);        
    }

    free(g_queue);
    g_queue = NULL;    
}

int QueueIsEmpty()
{
    if (g_queue == NULL) {
        return 1;
    }

    return g_queue->head == NULL;
}

void PushQueue(char *node)
{
    LinkSt *newNode = (LinkSt *)malloc(sizeof(LinkSt));
    if (newNode == NULL) {
        printf("Malloc is NULL");
        return;
    }

    newNode->linkValue = node;
    newNode->next = NULL;

    if (QueueIsEmpty()) {
        InitQueue(newNode);
    } else {
        g_queue->tail->next = newNode;
        g_queue->tail = newNode;
    }
}

void PopQueue()
{
    if (!QueueIsEmpty()) {
        LinkSt *res = g_queue->head;
        g_queue->head = g_queue->head->next;
        free(res);

        if (g_queue->head == NULL) {
            g_queue->tail = NULL;
            free(g_queue);
            g_queue = NULL;
        }
    }
}

LinkSt* GetTopQueue()
{
    if (QueueIsEmpty()) {
        return NULL;
    } else {
        return g_queue->head;
    }
}

int QueueSize()
{
    if (QueueIsEmpty()) {
        return 0;
    }

    int count = 0;
    LinkSt *p = g_queue->head;
    while (p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

#define NUM 8000
int g_visit[NUM] = {0};
char *g_res[NUM];

void FindNext(char **dict, int dictSize, char *curr, int *size)
{
    int cnt = 0;

    for (int i = 0; i < dictSize; i++) {
        if (g_visit[i] != 0) {
            continue;
        }

        char *dst = dict[i];
        char *src = curr;
        int diff = 0;
        while (*src != '\0') {
            if (diff > 1) {
                break;
            }
            if (*src != *dst) {
                diff++;
            }
            src++;
            dst++;
        }
        
        if (diff == 1) {
            g_visit[i] = 1;
            g_res[cnt++] = dict[i];
        }
    }

    *size = cnt;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize){
    if ((beginWord == NULL) || (endWord == NULL) || (wordListSize == 0)) {
        return 0;
    }

    int minLength = 0;
    int i;
    memset(g_visit, 0,  sizeof(g_visit));
    PushQueue(beginWord);

    while (!QueueIsEmpty()) {
        minLength++;
        int len = QueueSize();

        for (i = 0; i < len; i++) {
            char *curr = GetTopQueue()->linkValue;
            PopQueue();

            if (strcmp(curr, endWord) == 0) {
                DeinitQueue();
                return minLength;
            } else {
                int resSize = 0;
                FindNext(wordList, wordListSize, curr, &resSize);

                for (int j = 0; j < resSize; j++) {
                    PushQueue(g_res[j]);
                }
            }
        }
    }

    DeinitQueue();
    return 0;
}
```
