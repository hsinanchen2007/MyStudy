### 解题思路
C语言

### 代码

```c

struct _LRUEntry {
    struct _LRUEntry* pre;
    struct _LRUEntry* next;
    int key;
    int val;
};
typedef struct _LRUEntry LRUEntry;
typedef struct {
    int size;
    int capacity;
    LRUEntry* head;
    LRUEntry* tail;
} LRUCache;

#define MAX_NUM 4000
int hash[MAX_NUM] ={0};
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    memset(cache,0,sizeof(LRUCache));
    cache->capacity = capacity;
    memset(hash,0,sizeof(int) * MAX_NUM);
    return cache;
}
void moveTohead(LRUCache* obj, int key) {
    //printf("key%d\n",key);
    LRUEntry* head = obj->head;
    LRUEntry* tail = obj->tail;
    LRUEntry* cur = obj->head;
    while (cur->key != key) {
        cur = cur->next;
    }
    if (cur == head) {
        return;
    }
    else if (tail == cur) {
        LRUEntry* pre = cur->pre;
        //printf("%d\n",tail->val);
        //printf("key%d\n",key);
        pre->next = cur->next;
        cur->next = head;
        cur->pre = NULL;
        head->pre = cur;
        obj->head = cur;
        obj->tail = pre;
        return;
    } else {
        LRUEntry* pre = cur->pre;
        LRUEntry* next = cur->next;
        pre->next = next;
        next->pre = pre;
        cur->next = head;
        cur->pre = NULL;
        head->pre = cur;
        obj->head = cur;
        return;
    }
    return;
}
void deleteAndAddHead(LRUCache* obj, int key, int value) {
    if (obj->capacity == 1) {
        int key2 = obj->head->key;
        hash[key2] = 0;
        LRUEntry* head = obj->head;
        head->key = key;
        head->val = value;
        //LRUEntry* node = (LRUEntry*)malloc(sizeof(LRUEntry));
        //memset(node,0,sizeof(node));
        return;
    }
    //printf("putkey%d\n",key);
    LRUEntry* tail = obj->tail;
    LRUEntry* head = obj->head;
    LRUEntry* pre = tail->pre;
    //printf("%d\n",key);
    pre->next = NULL;
    obj->tail = pre;
    int key2 = tail->key;
    hash[key2] = 0;
    free(tail);
    LRUEntry* node = (LRUEntry*)malloc(sizeof(LRUEntry));
    memset(node,0,sizeof(node));
    node->key = key;
    node->val = value;
    node->next = head;
    head->pre = node;
    obj->head = node;
    return;
}

void moveToheadFromKey(LRUCache* obj, int key, int value) {
    LRUEntry* head = obj->head;
    LRUEntry* tail = obj->tail;
    LRUEntry* cur = obj->head;
    while (cur->key != key) {
        cur = cur->next;
    }
    cur->val = value;
    hash[key] = value;
    if (cur == head) {
        return;
    }
    else if (tail == cur) {
        LRUEntry* pre = cur->pre;
        pre->next = NULL;
        cur->next = head;
        cur->pre = NULL;
        head->pre = cur;
        obj->head = cur;
        obj->tail = pre;
        return;
    } else {
        LRUEntry* pre = cur->pre;
        LRUEntry* next = cur->next;
        pre->next = next;
        next->pre = pre;
        cur->next = head;
        cur->pre = NULL;
        head->pre = cur;
        obj->head = cur;
        return;
    }
    return;
}

void derectAddHead(LRUCache* obj, int key, int value) {
    if (obj->head == NULL) {
        LRUEntry* node = (LRUEntry*)malloc(sizeof(LRUEntry));
        memset(node,0,sizeof(node));
        node->key = key;
        node->val = value;
        obj->head = node;
        obj->tail = node;
        obj->size++;
        return;
    }
    LRUEntry* head = obj->head;
    LRUEntry* node = (LRUEntry*)malloc(sizeof(LRUEntry));
    memset(node,0,sizeof(node));
    node->key = key;
    node->val = value;
    node->next = head;
    head->pre = node;
    obj->head = node;
    obj->size++;
    return;
}

void addToHead(LRUCache* obj, int key, int value) {
    int size = obj->size;
    int capacity = obj->capacity;
    if (size >= capacity) {
        deleteAndAddHead(obj,key,value);
    }else {
        derectAddHead(obj,key,value);
    }
    return;
}
int lRUCacheGet(LRUCache* obj, int key) {
    if (hash[key] == 0) {
        return -1;
    }else {
        moveTohead(obj, key);
        return hash[key];
    }
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (hash[key] == 0) {
        addToHead(obj,key,value);
        hash[key] = value;
    }else {
        moveToheadFromKey(obj,key,value);
    }
    return;
}

void lRUCacheFree(LRUCache* obj) {
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