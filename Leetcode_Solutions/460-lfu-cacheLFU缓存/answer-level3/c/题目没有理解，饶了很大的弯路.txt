### 解题思路
开始理解最后访问是记录的访问节点，导致计算的不正确

后面使用time标识，每次get的时候time+1即可

代码比较简单，主要使用hash标识

### 代码

```c
#if 0
#define PRINTFZLL printf
#else
#define PRINTFZLL
#endif

typedef struct Node {
    int key;
    int val;
    int count;
    int time;
    UT_hash_handle hh; /* makes this structure hashable */
} NODE_S;

typedef struct {
    int time;
    int capibility;
    NODE_S *lfuNode;
} LFUCache;


LFUCache *lFUCacheCreate(int capacity)
{
    LFUCache *lftCache = malloc(sizeof(LFUCache));
    if (lftCache == NULL) {
        return NULL;
    }

    lftCache->time = 0;
    lftCache->capibility = capacity;
    lftCache->lfuNode = NULL;
    return lftCache;
}

NODE_S* lFUCacheFind(LFUCache *obj, int key)
{
    LFUCache *lftCache = obj;
    NODE_S *findNode = NULL;

    if (lftCache == NULL) {
        return NULL;
    }

    HASH_FIND_INT(lftCache->lfuNode, &key, findNode);
    if (findNode == NULL) {
        return NULL;
    }
    findNode->count++;
    return findNode;
}

int lFUCacheGet(LFUCache *obj, int key)
{
    LFUCache *lftCache = obj;
    NODE_S *findNode = NULL;

    if (lftCache == NULL) {
        return -1;
    }

    findNode = lFUCacheFind(lftCache, key);
    if (findNode == NULL) {
        return -1;
    }
    lftCache->time = lftCache->time + 1;
    findNode->time = lftCache->time;
    PRINTFZLL("\r\n lFUCacheGet[%d,%d,%d,%d]",findNode->key, findNode->val, findNode->count, findNode->time);
    return findNode->val;
}

void DeleteNode(LFUCache *lftCache)
{
    if (lftCache == NULL) {
        return;
    }

    NODE_S *current = NULL;
    NODE_S *tmp = NULL;
    NODE_S *delNode = NULL;
    int count = __INT32_MAX__;
    HASH_ITER(hh, lftCache->lfuNode, current, tmp)
    {
        PRINTFZLL("\r\n DeleteNodeInfo[%d,%d,%d,%d]", current->key, current->val, current->count, current->time);
        if ((current->count < count) || (delNode == NULL)){
            count = current->count;
            delNode = current;
        } else if (current->count == count) {
            if (current->time < delNode->time) {
                count = current->count;
                delNode = current;
            }
        }
    }

    if (delNode == NULL)
    {
        PRINTFZLL("\r\n DeleteNode NULL");
    }
    else{
        PRINTFZLL("\r\n DeleteNode[%d,%d,%d]", delNode->key, delNode->count, delNode->val);
    }
    
    HASH_DEL(lftCache->lfuNode, delNode);
    free(delNode);
    return;
}

void lFUCachePut(LFUCache *obj, int key, int value)
{
    LFUCache *lftCache = obj;
    NODE_S *find = NULL;
    //PRINTFZLL("\r\n lFUCachePut begin key=%d, num:%d cahce:%d", key, num, lftCache->capibility);
    find = lFUCacheFind(lftCache, key);
    if (find != NULL) {
        find->val = value;
        find->time = lftCache->time;
        return;
    }

    if (lftCache->capibility == 0) {
        return;
    }

    int num;
    num = HASH_COUNT(lftCache->lfuNode);
    PRINTFZLL("\r\n lFUCachePut key=%d, num:%d cahce:%d", key, num, lftCache->capibility);
    if (num >= lftCache->capibility) {
        DeleteNode(lftCache);
    }

    NODE_S *addNode = NULL;
    addNode = malloc(sizeof(NODE_S));
    addNode->key = key;
    addNode->count = 1;
    addNode->val = value;
    addNode->time = lftCache->time;
    HASH_ADD_INT(lftCache->lfuNode, key, addNode); /* id: name of key field */
    return;
}

void lFUCacheFree(LFUCache *obj)
{
    LFUCache *lftCache = obj;

    if (lftCache == NULL) {
        return;
    }

    if (lftCache->lfuNode == NULL) {
        free(lftCache);
        return;
    }

    NODE_S *current = NULL;
    NODE_S *tmp = NULL;
    NODE_S *delNode = -1;
    int count = __INT32_MAX__;
    HASH_ITER(hh, lftCache->lfuNode, current, tmp)
    {
        HASH_DEL(lftCache->lfuNode, current);
        free(current);
    }
    free(lftCache);
    return;
}
```