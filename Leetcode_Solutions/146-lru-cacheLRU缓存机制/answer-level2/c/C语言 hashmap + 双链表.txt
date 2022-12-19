### 代码

```c
struct LRUNode {
    // hash table
    int key;
    int value;
    UT_hash_handle hh;
    // doubly lined list
    struct LRUNode *prev;
    struct LRUNode *next;
};

static inline void RemoveDNode(struct LRUNode *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

static inline void InsertToDHead(struct LRUNode *head, struct LRUNode *node)
{
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

typedef struct {
    int cap;
    int size;
    struct LRUNode *dhead, *dtail;
    struct LRUNode *hashmap;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache* rc = (LRUCache *)malloc(sizeof(LRUCache));
    rc->cap = capacity;
    rc->size = 0;
    rc->dhead = (struct LRUNode *)malloc(sizeof(struct LRUNode));
    rc->dtail = (struct LRUNode *)malloc(sizeof(struct LRUNode));
    rc->dhead->next = rc->dtail;
    rc->dtail->prev = rc->dhead;
    rc->hashmap = NULL;
    return rc;
}

int lRUCacheGet(LRUCache* obj, int key) {
    struct LRUNode *node = NULL;

    HASH_FIND_INT(obj->hashmap, &key, node);  /* id already in the hash? */
    if (node == NULL) {
        return -1;
    }
    if (obj->dhead->next != node) {
        RemoveDNode(node);
        InsertToDHead(obj->dhead, node);
    }
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    struct LRUNode *node = NULL;

    HASH_FIND_INT(obj->hashmap, &key, node);  /* id already in the hash? */
    if (node != NULL) {
        node->value = value;
        lRUCacheGet(obj, key);
        return ;
    }

    node = (struct LRUNode *)malloc(sizeof(struct LRUNode));
    node->key = key;
    node->value = value;
    HASH_ADD_INT(obj->hashmap, key, node);
    InsertToDHead(obj->dhead, node);

    if (obj->size < obj->cap) {
        obj->size++;
    } else {
        node = obj->dtail->prev;
        HASH_DEL(obj->hashmap, node);
        RemoveDNode(node);
        free(node);
    }
}

void lRUCacheFree(LRUCache* obj) {
    struct LRUNode *cur, *tmp;

    HASH_ITER(hh, obj->hashmap, cur, tmp) {
        HASH_DEL(obj->hashmap, cur);
        RemoveDNode(cur);
        free(cur);
    }
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/
```