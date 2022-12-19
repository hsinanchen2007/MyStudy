```

#define MAX_KEY 3000

typedef struct _node
{
    int value;
    int key;
    struct _node *pre;
    struct _node *next;
}Node;

typedef struct
{
    Node *head;
    Node *tail;
    int count;
    int capacity;
    Node *map[MAX_KEY];
}LRUCache;

void addNodeAtHead(LRUCache *cache, int key, int value)
{
    Node *headNext = cache->head->next;

    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->pre = cache->head;
    node->next = headNext;

    headNext->pre = node;
    cache->head->next = node;

    (cache->map)[key] = node;
    (cache->count)++;
}

void removeNode(LRUCache *cache, Node *node)
{
    assert(node);
    
    Node *pre = node->pre;
    Node *next = node->next;

    pre->next = next;
    next->pre = pre;

    (cache->map)[node->key] = NULL;

    free(node);

    (cache->count)--;
}

void removeNodeAtEnd(LRUCache *cache)
{
    removeNode(cache, cache->tail->pre);
}

LRUCache* lRUCacheCreate(int capacity) {

    LRUCache *cache = malloc(sizeof(LRUCache));
    cache->count = 0;
    cache->capacity = capacity;
    
    Node *head = malloc(sizeof(Node));
    head->pre = NULL;
    Node *tail = malloc(sizeof(Node));
    tail->next = NULL;

    head->next = tail;
    tail->pre = head;

    cache->head = head;
    cache->tail = tail;

    memset(cache->map, 0, sizeof(Node *) * MAX_KEY);

    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {

    Node *node = (obj->map)[key];

    if(node == NULL) return -1;

    int value = node->value;

    removeNode(obj, node);

    addNodeAtHead(obj, key, value);

    return value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {

    Node *node = (obj->map)[key];

    if(node)
    {
        removeNode(obj, node);
    } 
    else
    {   // node == NULL
        if(obj->count >= obj->capacity)
            removeNodeAtEnd(obj);
    }

    addNodeAtHead(obj, key, value);
}

void lRUCacheFree(LRUCache* obj) {

    Node *cur = obj->head;

    while(cur)
    {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }

    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
```
