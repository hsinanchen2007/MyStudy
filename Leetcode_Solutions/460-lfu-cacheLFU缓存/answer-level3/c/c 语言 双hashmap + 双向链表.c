### 解题思路
执行用时 : 124 ms, 91.67%
内存消耗 : 25.7 MB 100.00%

### 代码

```c
struct LFUNode {
    int key;
    int value;
    int frequency;
    UT_hash_handle hh;
    struct LFUNode *prev;
    struct LFUNode *next;
};

struct FreDlist {
    int key;
    struct LFUNode *head;
    struct LFUNode *tail;
    UT_hash_handle hh;
};

//alloc free addtohead remove(from tail)
static inline void AllocFreDlist(struct FreDlist **list)
{
    *list = (struct FreDlist *)malloc(sizeof(struct FreDlist));
    (*list)->head = (struct LFUNode *)malloc(sizeof(struct LFUNode));
    (*list)->tail = (struct LFUNode *)malloc(sizeof(struct LFUNode));
    (*list)->head->next = (*list)->tail;
    (*list)->tail->prev = (*list)->head;
}

static inline void FreeFreDlist(struct FreDlist *list)
{
    free(list->head);
    free(list->tail);
    free(list);
}

static inline void AddNodeToHead(struct LFUNode *head, struct LFUNode *node)
{
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

static inline void RemoveNode(struct LFUNode *node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

typedef struct {
    struct FreDlist *freMap;
    struct LFUNode *nodeMap;
    int cap; // HASH_COUNT(nodeMap) <= cap
    int minFre;
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache *obj = (LFUCache *)malloc(sizeof(LFUCache));
    obj->freMap = NULL;
    obj->nodeMap = NULL;
    obj->cap = capacity;
    obj->minFre = 0;
    return obj;
}

int lFUCacheGet(LFUCache* obj, int key) {
    if (obj->cap == 0) {
        return -1;
    }
    //printf("get %d\n", key);
    struct LFUNode *node = NULL;
    struct FreDlist *list = NULL;

    HASH_FIND_INT(obj->nodeMap, &key, node);
    if (node == NULL) {
        return -1;
    }

    if (obj->minFre == node->frequency) {
        HASH_FIND_INT(obj->freMap, &node->frequency, list);
        if (node->prev == list->head &&
            node->next == list->tail) {
            obj->minFre++;
        }
    }
    RemoveNode(node);
    (node->frequency)++;

    HASH_FIND_INT(obj->freMap, &node->frequency, list);
    if (list == NULL) {
        AllocFreDlist(&list);
        list->key = node->frequency;
        HASH_ADD_INT(obj->freMap, key, list);
    }
    AddNodeToHead(list->head, node);

    return node->value;
}

void lFUCachePut(LFUCache* obj, int key, int value)
{
    if (obj->cap == 0) {
        return ;
    }
    //printf("put %d %d\n", key, value);
    struct LFUNode *node = NULL;
    struct FreDlist *list = NULL;

    HASH_FIND_INT(obj->nodeMap, &key, node);
    if (node != NULL) {
        node->value = value;
        HASH_FIND_INT(obj->freMap, &node->frequency, list);
        RemoveNode(node);
        AddNodeToHead(list->head, node);
        lFUCacheGet(obj, key);
        return ;
    }

    node = (struct LFUNode *)malloc(sizeof(struct LFUNode));
    node->key = key;
    node->value = value;
    HASH_ADD_INT(obj->nodeMap, key, node);
    // add to fremap
    node->frequency = 1;
    HASH_FIND_INT(obj->freMap, &node->frequency, list);
    if (list == NULL) {
        AllocFreDlist(&list);
        list->key = node->frequency;
        HASH_ADD_INT(obj->freMap, key, list);
    }
    AddNodeToHead(list->head, node);

    if (HASH_COUNT(obj->nodeMap) > obj->cap) {
        HASH_FIND_INT(obj->freMap, &obj->minFre, list);
        //printf("%d %d %d", obj->minFre, HASH_COUNT(obj->nodeMap), obj->cap);
        node = list->tail->prev;
        RemoveNode(node);
        HASH_DEL(obj->nodeMap, node);
        free(node);
    }
    obj->minFre = 1;
}

void lFUCacheFree(LFUCache* obj) {
    struct LFUNode *lcurr, *ltmp;
    struct FreDlist *fcurr, *ftmp;
    HASH_ITER(hh, obj->nodeMap, lcurr, ltmp) {
        HASH_DEL(obj->nodeMap, lcurr);
        RemoveNode(lcurr);
        free(lcurr);
    }
    HASH_ITER(hh, obj->freMap, fcurr, ftmp) {
        FreeFreDlist(fcurr);
    }
}

```