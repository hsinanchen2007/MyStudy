### 解题思路
1、BFS找到距离为K的朋友，注意：距离不为K的朋友包括自身都需要去掉
2、朋友看过的视频入Hash
3、Hash排序，先频率，再字符
4、输出结果

### 代码

```c
#define MAXSIZE_QL1 10000
#define MAXSIZE_VIDSTRLEN 100
#define DEBUG 

typedef struct {
    int data[MAXSIZE_QL1];
    int head; /* 头指针 */
    int tail; /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
} QueueL1;

int QueueL1GetVIndex(int index)
{
    return (index + MAXSIZE_QL1) % MAXSIZE_QL1;
}

void QueueL1Init(QueueL1 *queue) 
{
    (void)memset(queue->data, 0, sizeof(int) * MAXSIZE_QL1);
    queue->head = 0;
    queue->tail = 0;
    return;
}

int QueueL1GetLen(QueueL1 *queue) 
{
    return QueueL1GetVIndex(queue->tail - queue->head);
}

int QueueL1IsEmpty(QueueL1 *queue) 
{
    return (queue->head == queue->tail) ? (1) : (0) ;
}

void QueueL1Push(QueueL1 *queue, int *node) 
{
    if (QueueL1GetVIndex(queue->tail + 1) == queue->head) {
        DEBUG("QueueL1Push fail!\n");
        return;
    }
    (void)memcpy(&(queue->data[queue->tail]), node, sizeof(int));
    queue->tail = (queue->tail + 1) % MAXSIZE_QL1;
}

void QueueL1Pop(QueueL1 *queue, int *node) 
{
    if (queue->head == queue->tail) {
        DEBUG("QueueL1Pop fail!\n");
        return;
    }
    *node = queue->data[queue->tail - 1];
    queue->tail = (MAXSIZE_QL1 + queue->tail - 1) % MAXSIZE_QL1;
}

void QueueL1PopFront(QueueL1 *queue, int *node) 
{
    if (queue->head == queue->tail) {
        DEBUG("QueueL1PopFront fail!\n");
        return;
    }
    (void)memcpy(node, &(queue->data[queue->head]), sizeof(int));
    queue->head = (queue->head + 1) % MAXSIZE_QL1;
}

typedef struct {
    char* key;
    int cnt;
    UT_hash_handle hh;
} Hash;

void AddHash(char* key, Hash** hashObj)
{
    Hash* node;
    HASH_FIND_STR(*hashObj, key, node);
    if (node == NULL) {
        Hash* tmp = calloc(1, sizeof(Hash));
        tmp->key = key;
        tmp->cnt++;
        HASH_ADD_KEYPTR(hh, *hashObj, key, strlen(key), tmp);
    } else {
        node->cnt++;
    }
}

void DelHash(Hash** hashObj)
{
    Hash* node;
    Hash* node2;
    HASH_ITER(hh, *hashObj, node, node2) {
        HASH_DEL(*hashObj, node);
        free(node->key);
        free(node);
    }
}

void OutputHash(Hash** hashObj, char** returnData)
{
    int i = 0;
    Hash* node;
    Hash* node2;
    HASH_ITER(hh, *hashObj, node, node2) {
        strcpy(returnData[i++], node->key);
        HASH_DEL(*hashObj, node);
        free(node);
        node = NULL;
    }
}

int compareHash(Hash* a, Hash* b) 
{
    /* 先排次数，再排string */
    if (a->cnt != b->cnt) {
        return a->cnt > b->cnt;
    }
    return strcmp(a->key, b->key);
}

char** MallocDataL2(int maxX, int maxY) 
{
    char** data = calloc(maxX, sizeof(char*));
    for (int i = 0; i < maxX; i++) {
        data[i] = calloc(maxY, sizeof(char*));
    }
    return data;
}

char ** watchedVideosByFriends(
    char*** watchedVideos, 
    int watchedVideosSize, 
    int* watchedVideosColSize, 
    int** friends, 
    int friendsSize, 
    int* friendsColSize, 
    int id, 
    int level, 
    int* returnSize)
{
    if (watchedVideos == NULL || watchedVideosSize == 0 || friends == NULL || friendsSize == 0 || id >= friendsSize) {
        *returnSize = 0;
        return NULL;
    }

    QueueL1 queue;
    QueueL1Init(&queue);

    Hash* hashObj = NULL;
    bool visit[friendsSize];
    memset(visit, 0, sizeof(visit));

    /* 遍历level层frend，建立hash */
    QueueL1Push(&queue, &id);

    while (!QueueL1IsEmpty(&queue) && level >= 0) {
        int queueLen = QueueL1GetLen(&queue);
        for (int qIndex = 0; qIndex < queueLen; qIndex++) {
            int frendId = 0;
            /* 找到frend */
            QueueL1PopFront(&queue, &frendId);
            if (level == 0 && visit[frendId] == 0) {
                /* 距离为K的看了啥，距离不为K的不统计 */
                for (int vIndex = 0; vIndex < watchedVideosColSize[frendId]; vIndex++) {
                    AddHash(watchedVideos[frendId][vIndex], &hashObj);
                }
            }

            /* 注意：刨除之前出现的朋友 */
            visit[frendId] = 1;
            
            /* frend's frend入队 */
            for (int ffi = 0; ffi < friendsColSize[frendId]; ffi++) {
                int newId = friends[frendId][ffi];
                QueueL1Push(&queue, &newId);
            }
        }
        level--;
    }
    
    /* hash排序 */
    HASH_SORT(hashObj, compareHash);

    /* 输出 */
    *returnSize = HASH_COUNT(hashObj);
    char** returnData =  MallocDataL2(HASH_COUNT(hashObj), MAXSIZE_VIDSTRLEN);
    OutputHash(&hashObj, returnData);

    return returnData;
}
```